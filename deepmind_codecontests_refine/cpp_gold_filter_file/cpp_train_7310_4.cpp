#include <bits/stdc++.h>
using ll = long long;
using ld = long double;
using ull = unsigned long long;
using namespace std;
const int MX = 2100;
const int MK = 90;
const int MOD = 998244353;
void ad(int& x, int y) {
  x += y;
  if (x >= MOD) {
    x -= MOD;
  }
}
int f[MX][MX];
int g[2][MX + 5][MX + 5];
int n, k;
int res[MX];
bool can(vector<int> a) {
  for (int i = 0; i < k - 1; i++) {
    vector<int> na;
    int nx = 1;
    for (int j = (int)a.size() - 1; j >= 0; j--) {
      for (int k = 0; k < a[j]; k++) {
        na.push_back(nx);
        if (na.size() > n) {
          return false;
        }
      }
      nx++;
    }
    a = na;
  }
  int sm = 0;
  for (int x : a) {
    sm += x;
  }
  if (sm > n) {
    return false;
  }
  return true;
}
vector<int> cur;
int ANS = 0;
void gen(int lst) {
  for (int i = lst;; i++) {
    cur.push_back(i);
    if (!can(cur)) {
      cur.pop_back();
      return;
    } else {
      ANS++;
      gen(i);
      cur.pop_back();
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> k;
  if (k == 1) {
    int ans = 0;
    f[0][1] = 1;
    for (int i = 0; i < n; i++) {
      int sm = 0;
      for (int j = 1; i + j <= n; j++) {
        ad(sm, f[i][j]);
        ad(f[i + j][j], sm);
      }
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        ad(ans, f[i][j]);
      }
    }
    cout << ans << "\n";
    return 0;
  }
  if (k == 2) {
    int cur = 0;
    int nx = 1;
    g[cur][MX - 1][0] = 1;
    for (int pos = 0; pos + 1 < MK; pos++) {
      for (int i = 0; i < MX + 5; i++) {
        for (int j = 0; j < MX + 5; j++) {
          g[nx][i][j] = 0;
        }
      }
      for (int lst = 0; lst < MX; lst++) {
        for (int sm = 0; sm < MX; sm++) {
          if (g[cur][lst][sm] == 0) {
            continue;
          }
          for (int nxt = 1; nxt <= lst; nxt++) {
            int nsm = sm + (pos + 1) * nxt;
            if (nsm >= MX) {
              break;
            }
            ad(g[nx][nxt][nsm], g[cur][lst][sm]);
          }
        }
      }
      if (pos > 0) {
        for (int j = 0; j < MX; j++) {
          for (int k = 1; k < MX; k++) {
            ad(res[k], g[cur][j][k]);
          }
        }
      }
      swap(cur, nx);
    }
    for (int i = 1; i < MX; i++) {
      ad(res[i], res[i - 1]);
    }
    cout << res[n] << "\n";
    return 0;
  }
  if (k > 10) {
    cout << 1 << "\n";
    return 0;
  }
  gen(1);
  cout << ANS << "\n";
  return 0;
}
