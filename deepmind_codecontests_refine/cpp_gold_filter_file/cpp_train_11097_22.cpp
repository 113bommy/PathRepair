#include <bits/stdc++.h>
using namespace std;
const long double Pi = acos(-1);
const long long Inf = 1e18;
const int inf = 1e9 + 1;
const int mod = 1e9 + 7;
const long double eps = 1e-12;
const int N = 1e6 + 123;
void add(int &a, int b) {
  a += b;
  if (a >= mod) a -= mod;
}
int mult(int a, int b) { return 1ll * a * b % mod; }
int sum(int a, int b) {
  add(a, b);
  return a;
}
int n, q;
pair<int, int> dp[2][2][2], buf[2][2][2];
void Add(pair<int, int> &a, pair<int, int> b, int x) {
  add(a.first, b.first);
  add(a.second, b.second);
  add(a.second, mult(b.first, x));
}
const int B = 31;
int Get(int N, int M, int k) {
  N--, M--;
  memset(dp, 0, sizeof dp);
  memset(buf, 0, sizeof buf);
  dp[0][0][0] = make_pair(1, 0);
  for (int b = B; b >= 0; b--) {
    int x = (N >> b) & 1;
    int y = (M >> b) & 1;
    int z = (k >> b) & 1;
    for (int t1 = 0; t1 < 2; t1++) {
      for (int t2 = 0; t2 < 2; t2++) {
        for (int t3 = 0; t3 < 2; t3++) {
          if (dp[t1][t2][t3].first == 0) continue;
          int l1 = 0, r1 = (t1 == 1 ? 1 : x);
          int l2 = 0, r2 = (t2 == 1 ? 1 : y);
          int l3 = 0, r3 = (t3 == 1 ? 1 : z);
          for (int v1 = l1; v1 <= r1; v1++) {
            for (int v2 = l2; v2 <= r2; v2++) {
              int v3 = v1 ^ v2;
              if (v3 <= r3) {
                int nt1 = t1 | (v1 < r1);
                int nt2 = t2 | (v2 < r2);
                int nt3 = t3 | (v3 < r3);
                Add(buf[nt1][nt2][nt3], dp[t1][t2][t3], (1 << b) * v3);
              }
            }
          }
        }
      }
    }
    for (int t1 = 0; t1 < 2; t1++) {
      for (int t2 = 0; t2 < 2; t2++) {
        for (int t3 = 0; t3 < 2; t3++) {
          dp[t1][t2][t3] = buf[t1][t2][t3];
          buf[t1][t2][t3] = make_pair(0, 0);
          continue;
          if (dp[t1][t2][t3].first) {
            cout << "after t1 = " << t1 << " t2 = " << t2 << " t3 = " << t3
                 << " f = " << dp[t1][t2][t3].first << endl;
          }
        }
      }
    }
  }
  int ans = 0;
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      add(ans, dp[i][j][1].first);
      add(ans, dp[i][j][1].second);
    }
  }
  return ans;
}
int query(int x1, int y1, int x2, int y2, int k) {
  int ans = 0;
  add(ans, Get(x2, y2, k));
  if (min(x1, y1) > 1) add(ans, Get(x1 - 1, y1 - 1, k));
  if (y1 > 1) add(ans, mod - Get(x2, y1 - 1, k));
  if (x1 > 1) add(ans, mod - Get(x1 - 1, y2, k));
  return ans;
}
void solve() {
  cin >> q;
  for (int i = 0, x1, y1, x2, y2, k; i < q; i++) {
    cin >> x1 >> y1 >> x2 >> y2 >> k;
    cout << query(x1, y1, x2, y2, k) << endl;
  }
}
int main() {
  int tt = 1;
  while (tt--) solve();
  return 0;
}
