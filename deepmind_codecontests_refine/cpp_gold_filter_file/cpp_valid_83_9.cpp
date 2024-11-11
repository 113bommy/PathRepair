#include <bits/stdc++.h>
using namespace std;
class rmq_sa {
  vector<int> v;
  vector<vector<int>> b;
  int f(int i, int j) { return v[i] < v[j] ? i : j; }

 public:
  rmq_sa() {}
  rmq_sa(vector<int> _v) : v(_v) {
    int n = v.size();
    int m = 32 - __builtin_clz(n);
    b = vector<vector<int>>(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
      b[i][0] = i;
    }
    for (int j = 1; j < m; ++j) {
      for (int i = 0; i < n - (1 << j) + 1; ++i) {
        b[i][j] = f(b[i][j - 1], b[i + (1 << (j - 1))][j - 1]);
      }
    }
  }
  int query(int l, int r) {
    int x = floor(log2(r - l));
    return f(b[l][x], b[r - (1 << x)][x]);
  }
};
class suffix_array {
  vector<int> sa;
  vector<int> lcp_;
  vector<int> sr;
  int n;
  rmq_sa st;

 public:
  suffix_array() {}
  suffix_array(const vector<int> &a)
      : n(a.size()), sa(a.size() + 1), lcp_(a.size()), sr(a.size() + 1) {
    sa[0] = n;
    iota(sa.begin() + 1, sa.end(), 0);
    sort(sa.begin() + 1, sa.end(), [&](int i, int j) { return a[i] < a[j]; });
    for (int i = 1; i <= n; ++i) {
      sr[sa[i]] = i > 1 && a[sa[i]] == a[sa[i - 1]] ? sr[sa[i - 1]] : i;
    }
    for (int k = 1; k < n; k <<= 1) {
      vector<int> t(sa);
      vector<int> tr(sr);
      vector<int> p(n + 1);
      iota(p.begin(), p.end(), 0);
      for (int i : t) {
        if (i >= k) {
          sa[p[sr[i - k]]++] = i - k;
        }
      }
      for (int i = 1; i <= n; ++i) {
        sr[sa[i]] =
            tr[sa[i]] == tr[sa[i - 1]] && tr[sa[i] + k] == tr[sa[i - 1] + k]
                ? sr[sa[i - 1]]
                : i;
      }
    }
    for (int i = 0, l = 0; i < n; lcp_[sr[i++] - 1] = l, l && l--) {
      for (int j = sa[sr[i] - 1]; j + l < n && a[i + l] == a[j + l]; ++l)
        ;
    }
    st = rmq_sa(lcp_);
  }
  int lcp(int i, int j) {
    if (i == j) {
      return n - i;
    }
    i = sr[i];
    j = sr[j];
    if (i > j) {
      swap(i, j);
    }
    return lcp_[st.query(i, j)];
  }
  int operator[](int i) { return sa[i]; }
};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      a[i] = s[i] - 'a';
    }
    vector<int> dp(n);
    suffix_array sa(a);
    for (int i = 0; i < n; ++i) {
      dp[i] = n - i;
      for (int j = 0; j < i; ++j) {
        int lcp = sa.lcp(i, j);
        if (i + lcp < n && s[j + lcp] < s[i + lcp]) {
          dp[i] = max(dp[i], dp[j] + (n - lcp - i));
        }
      }
    }
    cout << *max_element(dp.begin(), dp.end()) << '\n';
  }
}
