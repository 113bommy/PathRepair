#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-9;
const int inf = 2000000000;
const long long infLL = 5000000000000000000;
template <typename first, typename second>
ostream &operator<<(ostream &os, const pair<first, second> &p) {
  return os << "(" << p.first << ", " << p.second << ")";
}
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v) {
  os << "{";
  for (auto it = v.begin(); it != v.end(); ++it) {
    if (it != v.begin()) os << ", ";
    os << *it;
  }
  return os << "}";
}
template <typename T>
ostream &operator<<(ostream &os, const set<T> &v) {
  os << "[";
  for (auto it = v.begin(); it != v.end(); ++it) {
    if (it != v.begin()) os << ",";
    os << *it;
  }
  return os << "]";
}
template <typename T>
ostream &operator<<(ostream &os, const multiset<T> &v) {
  os << "[";
  for (auto it = v.begin(); it != v.end(); ++it) {
    if (it != v.begin()) os << ", ";
    os << *it;
  }
  return os << "]";
}
template <typename first, typename second>
ostream &operator<<(ostream &os, const map<first, second> &v) {
  os << "[";
  for (auto it = v.begin(); it != v.end(); ++it) {
    if (it != v.begin()) os << ", ";
    os << it->first << " = " << it->second;
  }
  return os << "]";
}
void faltu() { cerr << '\n'; }
template <typename T>
void faltu(T a[], int n) {
  for (int i = 0; i < n; ++i) cerr << a[i] << ' ';
  cerr << '\n';
}
template <typename T, typename... hello>
void faltu(T arg, const hello &...rest) {
  cerr << arg << ' ';
  faltu(rest...);
}
const int MAXN = 1010;
const int ALPHA = 256, LOG = 12;
struct SuffixArray {
  int sa[MAXN], data[MAXN], rnk[MAXN], height[MAXN], n;
  int wa[MAXN], wb[MAXN], wws[MAXN], wv[MAXN];
  int lg[MAXN], rmq[MAXN][LOG], rev_sa[MAXN];
  int cmp(int *r, int a, int b, int l) {
    return (r[a] == r[b]) && (r[a + l] == r[b + l]);
  }
  void DA(int *r, int *sa, int n, int m) {
    int i, j, p, *x = wa, *y = wb, *t;
    for (i = 0; i < m; i++) wws[i] = 0;
    for (i = 0; i < n; i++) wws[x[i] = r[i]]++;
    for (i = 1; i < m; i++) wws[i] += wws[i - 1];
    for (i = n - 1; i >= 0; i--) sa[--wws[x[i]]] = i;
    for (j = 1, p = 1; p < n; j *= 2, m = p) {
      for (p = 0, i = n - j; i < n; i++) y[p++] = i;
      for (i = 0; i < n; i++)
        if (sa[i] >= j) y[p++] = sa[i] - j;
      for (i = 0; i < n; i++) wv[i] = x[y[i]];
      for (i = 0; i < m; i++) wws[i] = 0;
      for (i = 0; i < n; i++) wws[wv[i]]++;
      for (i = 1; i < m; i++) wws[i] += wws[i - 1];
      for (i = n - 1; i >= 0; i--) sa[--wws[wv[i]]] = y[i];
      for (t = x, x = y, y = t, p = 1, x[sa[0]] = 0, i = 1; i < n; i++)
        x[sa[i]] = cmp(y, sa[i - 1], sa[i], j) ? p - 1 : p++;
    }
  }
  void calheight(int *r, int *sa, int n) {
    int i, j, k = 0;
    for (i = 1; i <= n; i++) rnk[sa[i]] = i;
    for (i = 0; i < n; height[rnk[i++]] = k)
      for (k ? k-- : 0, j = sa[rnk[i] - 1]; r[i + k] == r[j + k]; k++)
        ;
  }
  void suffix_array(string &A) {
    n = A.size();
    for (int i = 0; i < max(n + 5, ALPHA); i++)
      sa[i] = data[i] = rnk[i] = height[i] = wa[i] = wb[i] = wws[i] = wv[i] = 0;
    for (int i = 0; i < n; i++) data[i] = A[i];
    DA(data, sa, n + 1, ALPHA);
    calheight(data, sa, n);
    for (int i = 0; i < n; i++)
      sa[i] = sa[i + 1], height[i] = height[i + 1], rev_sa[sa[i]] = i;
    range_lcp_init();
  }
  void range_lcp_init() {
    for (int i = 0; i < n; i++) rmq[i][0] = height[i];
    for (int j = 1; j < LOG; j++) {
      for (int i = 0; i < n; i++) {
        if (i + (1 << j) - 1 < n)
          rmq[i][j] = min(rmq[i][j - 1], rmq[i + (1 << (j - 1))][j - 1]);
        else
          break;
      }
    }
    lg[0] = lg[1] = 0;
    for (int i = 2; i <= n; i++) {
      lg[i] = lg[i / 2] + 1;
    }
  }
  int query_lcp(int l, int r) {
    assert(l <= r);
    assert(l >= 0 && l < n && r >= 0 && r < n);
    if (l == r) return n - sa[l];
    l++;
    int k = lg[r - l + 1];
    return min(rmq[l][k], rmq[r - (1 << k) + 1][k]);
  }
} SA;
long long n, m, k;
string s;
vector<pair<int, int>> sub_string;
bool cmp(pair<int, int> &lhs, pair<int, int> &rhs) {
  int l1 = lhs.first, r1 = lhs.second, l2 = rhs.first, r2 = rhs.second;
  bool f = 0;
  if (SA.rev_sa[l2] < SA.rev_sa[l1]) {
    swap(l1, l2);
    swap(r1, r2);
    f ^= 1;
  }
  int len1 = r1 - l1 + 1, len2 = r2 - l2 + 1;
  int com = SA.query_lcp(SA.rev_sa[l1], SA.rev_sa[l2]);
  if (com < min(len1, len2)) return f ^ 1;
  return (len1 < len2) ^ f;
}
long long check(int idx) {
  int l = sub_string[idx].first, r = sub_string[idx].second;
  vector<vector<long long>> dp(n + 1, vector<long long>(m + 1));
  vector<int> L(n);
  for (int i = 0; i < n; ++i) {
    int temp1 = SA.rev_sa[l], temp2 = SA.rev_sa[i];
    if (temp1 > temp2) swap(temp1, temp2);
    int lcp = SA.query_lcp(temp1, temp2);
    if (lcp >= r - l + 1)
      L[i] = i + r - l;
    else if (lcp >= n - i)
      L[i] = -1;
    else if (s[i + lcp] > s[l + lcp])
      L[i] = i + lcp;
    else
      L[i] = -1;
  }
  dp[n][0] = 1;
  for (int i = 0; i <= n; ++i) dp[i][0] = 1;
  for (int i = 1; i <= m; ++i) {
    for (int j = n - 1; j >= 0; --j) {
      if (L[j] == -1) continue;
      int nxt = L[j] + 1;
      dp[j][i] = dp[nxt][i - 1];
    }
    if (i == m) continue;
    for (int j = n - 1; j >= 0; --j) {
      dp[j][i] += dp[j + 1][i];
      dp[j][i] = min(dp[j][i], infLL);
    }
  }
  return dp[0][m];
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  cin >> n >> m >> k;
  cin >> s;
  SA.suffix_array(s);
  SA.range_lcp_init();
  for (int i = 0; i < s.size(); ++i) {
    for (int j = i; j < s.size(); ++j) {
      sub_string.push_back(make_pair(i, j));
    }
  }
  sort(sub_string.begin(), sub_string.end(), cmp);
  int lo = 0, hi = sub_string.size() - 1, mid;
  while (lo <= hi) {
    mid = (lo + hi) / 2;
    if (check(mid) >= k)
      lo = mid + 1;
    else
      hi = mid - 1;
  }
  string ans;
  for (int i = sub_string[hi].first; i <= sub_string[hi].second; ++i) {
    ans += s[i];
  }
  cout << ans << '\n';
}
