#include <bits/stdc++.h>
#pragma GCC optimize("O2")
using namespace std;
inline long long input() {
  long long n;
  cin >> n;
  return n;
}
long long poww(long long a, long long b, long long md) {
  return (!b ? 1
             : (b & 1 ? a * poww(a * a % md, b / 2, md) % md
                      : poww(a * a % md, b / 2, md) % md));
}
const int MAXN = 77777 + 10;
const int MAXLG = 18;
const int MOD = 777777777;
const int MOD2 = 998244353;
const long long INF = 8e18;
int n, m;
int p[4][4];
long long seg[MAXN * 4][4][4];
void build(int s = 0, int e = n, int v = 1) {
  if (e - s < 2) {
    for (int i = 1; i <= 3; i++) {
      seg[v][i][i] = 1;
    }
    return;
  }
  int mid = (s + e) / 2;
  build(s, mid, 2 * v);
  build(mid, e, 2 * v + 1);
  for (int i = 1; i <= 3; i++) {
    for (int j = 1; j <= 3; j++) {
      for (int k = 1; k <= 3; k++) {
        for (int u = 1; u <= 3; u++) {
          if (!p[k][u]) {
            continue;
          }
          seg[v][i][j] += (seg[2 * v][i][k] * seg[2 * v + 1][u][j]) % MOD;
          seg[v][i][j] %= MOD;
        }
      }
    }
  }
}
void add_val(int ind, int val, int s = 0, int e = n, int v = 1) {
  if (s > ind || e <= ind) {
    return;
  }
  if (e - s < 2) {
    if (val == 0) {
      for (int i = 1; i <= 3; i++) {
        seg[v][i][i] = 1;
      }
      return;
    }
    for (int i = 1; i <= 3; i++) {
      seg[v][i][i] = 0;
    }
    seg[v][val][val] = 1;
    return;
  }
  int mid = (s + e) / 2;
  add_val(ind, val, s, mid, 2 * v);
  add_val(ind, val, mid, e, 2 * v + 1);
  for (int i = 1; i <= 3; i++) {
    for (int j = 1; j <= 3; j++) {
      seg[v][i][j] = 0;
    }
  }
  for (int i = 1; i <= 3; i++) {
    for (int j = 1; j <= 3; j++) {
      for (int k = 1; k <= 3; k++) {
        for (int u = 1; u <= 3; u++) {
          if (!p[k][u]) {
            continue;
          }
          seg[v][i][j] += (seg[2 * v][i][k] * seg[2 * v + 1][u][j]) % MOD;
          seg[v][i][j] %= MOD;
        }
      }
    }
  }
}
long long ret_ans() {
  long long ans = 0;
  for (int i = 1; i <= 3; i++) {
    for (int j = 1; j <= 3; j++) {
      ans += seg[1][i][j];
      ans %= MOD;
    }
  }
  return ans;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  cin >> n >> m;
  for (int i = 1; i <= 3; i++) {
    for (int j = 1; j <= 3; j++) {
      cin >> p[i][j];
    }
  }
  build();
  while (m--) {
    int x, y;
    cin >> x >> y;
    x--;
    add_val(x, y);
    cout << ret_ans() << "\n";
  }
}
