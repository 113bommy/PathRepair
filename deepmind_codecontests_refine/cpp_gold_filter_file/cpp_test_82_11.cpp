#include <bits/stdc++.h>
using namespace std;
const int N = (int)3e5 + 50, LOGN = 19;
struct RMQ {
  int n;
  int mm[N], st[LOGN][N];
  void build(int *x) {
    mm[0] = -1;
    for (int i = 1; i <= n; i++)
      mm[i] = (i & (i - 1)) == 0 ? mm[i - 1] + 1 : mm[i - 1];
    for (int i = 0; i < n; i++) {
      st[0][i] = x[i];
    }
    for (int lg = 1; lg < LOGN; lg++) {
      for (int j = 0; j + (1 << lg) - 1 < n; j++) {
        st[lg][j] = min(st[lg - 1][j], st[lg - 1][j + (1 << (lg - 1))]);
      }
    }
  }
  int rmq(int l, int r) {
    int k = mm[r - l + 1];
    return min(st[k][l], st[k][r - (1 << k) + 1]);
  }
} rmq;
struct node {
  long long v, cnt;
  long long sumcnt;
  long long totsum;
};
int a[N];
int n, q, k;
long long res[N];
vector<node> St[N];
vector<pair<int, int> > qrs[N];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> q >> k;
  for (int i = 0; i < (n); ++i) cin >> a[i];
  for (int i = 0; i < (q); ++i) {
    int l, r;
    cin >> l >> r;
    l--, r--;
    qrs[l].push_back({r, i});
  }
  rmq.n = n;
  rmq.build(a);
  for (int i = n - 1; i >= 0; i--) {
    auto &S = St[i % k];
    if (!S.empty()) {
      long long mn = rmq.rmq(i, i + k - 1);
      int cnt = 0;
      while (!S.empty() && S.back().v >= mn) {
        node o = S.back();
        S.pop_back();
        cnt += o.cnt;
      }
      if (cnt) {
        S.push_back({mn, cnt, cnt + (S.empty() ? 0 : S.back().sumcnt),
                     mn * cnt + (S.empty() ? 0 : S.back().totsum)});
      }
    }
    S.push_back({a[i], 1, 1 + (S.empty() ? 0 : S.back().sumcnt),
                 a[i] + (S.empty() ? 0 : S.back().totsum)});
    for (auto &p : qrs[i]) {
      int r = p.first, idx = p.second;
      int c = (r - i + k) / k;
      int lb = -1, rb = S.size(), mid;
      while (lb + 1 < rb) {
        mid = (lb + rb) / 2;
        if (S.back().sumcnt - (S[mid].sumcnt - S[mid].cnt) >= c)
          lb = mid;
        else
          rb = mid;
      }
      assert(lb != -1);
      long long cres = S.back().totsum - (S[lb].totsum - S[lb].cnt * S[lb].v);
      long long e = S.back().sumcnt - (S[lb].sumcnt - S[lb].cnt) - c;
      cres -= e * S[lb].v;
      res[p.second] = cres;
    }
  }
  for (int i = 0; i < (q); ++i) {
    cout << res[i] << "\n";
  }
}
