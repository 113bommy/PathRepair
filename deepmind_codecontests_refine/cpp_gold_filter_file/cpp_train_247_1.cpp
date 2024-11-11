#include <bits/stdc++.h>
using namespace std;
inline long long gcd(long long a, long long b) {
  return (b == 0 ? a : gcd(b, a % b));
}
const int MAXN = 200005;
const char INF = 100;
string T[55];
int n;
char pd[2][40][1 << 20];
int G[50][22];
char solve(int p, int k, int mask) {
  if (k == 2 * n - 1) return 0;
  if (pd[p][k][mask] == INF) {
    char ans = INF;
    int v[26] = {0};
    int aux = n - abs(n - k);
    for (int i = 0; i < aux; ++i) {
      if ((1 << i) & mask) {
        int a = i, b = i + 1;
        if (k >= n) a--, b--;
        if (a >= 0) v[G[k + 1][a]] |= 1 << a;
        if (k < n || i < aux - 1) v[G[k + 1][b]] |= 1 << b;
      }
    }
    for (int i = 0; i < 26; ++i) {
      if (!v[i]) continue;
      char tmp = solve(p ^ 1, k + 1, v[i]);
      if (i == 0) tmp++;
      if (i == 1) tmp--;
      if (p) {
        if (ans == INF || tmp < ans) ans = tmp;
      } else {
        if (ans == INF || tmp > ans) ans = tmp;
      }
    }
    pd[p][k][mask] = ans;
  }
  return pd[p][k][mask];
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  while (cin >> n) {
    for (int i = 0; i < n; ++i) cin >> T[i];
    for (int i = 1; i < 2 * n; ++i) {
      int x, y;
      if (i >= n) {
        x = n - 1, y = i - n;
      } else {
        x = i - 1, y = 0;
      }
      int j = 0;
      while (x >= 0) G[i][j++] = T[x--][y++] - 'a';
    }
    for (int i = 0; i < 40; ++i)
      for (int j = 0; j < 1 << 20; ++j) pd[0][i][j] = pd[1][i][j] = INF;
    int res = solve(1, 1, 1);
    if (T[0][0] == 'a') res++;
    if (T[0][0] == 'b') res--;
    if (res > 0) {
      cout << "FIRST" << endl;
    } else if (res < 0) {
      cout << "SECOND" << endl;
    } else {
      cout << "DRAW" << endl;
    }
  }
}
