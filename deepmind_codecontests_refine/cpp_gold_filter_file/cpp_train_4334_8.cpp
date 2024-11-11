#include <bits/stdc++.h>
using namespace std;
typedef int mat[55][55];
int c[55];
vector<long long> vlist;
mat g;
int n;
void mult(mat &res, mat &a, mat &b) {
  static mat c;
  memset(c, 0, sizeof c);
  for (int i = (1); i <= (n); i++)
    for (int j = (1); j <= (n); j++)
      for (int k = (1); k <= (n); k++)
        c[i][k] = (c[i][k] + a[i][j] * b[j][k]) & 1;
  memcpy(res, c, sizeof c);
}
int chk(long long z) {
  int t;
  for (int i = (62); i >= (0); i--)
    if (z & (1LL << i)) {
      t = i;
      break;
    }
  static mat ans;
  memcpy(ans, g, sizeof ans);
  for (int i = (t - 1); i >= (0); i--) {
    mult(ans, ans, ans);
    if (z & (1LL << i)) mult(ans, ans, g);
  }
  for (int i = (1); i <= (n); i++) {
    int s = 0;
    for (int j = (1); j <= (n); j++) s = (s + ans[j][i]) & 1;
    if (!s) return 0;
  }
  return 1;
}
int check(long long s) {
  memset(g, 0, sizeof g);
  for (int i = (1); i <= (n - 1); i++) g[i + 1][i] = 1;
  for (int i = (1); i <= (n); i++) g[i][n] = c[i];
  if (!chk(s)) return 0;
  for (typeof((vlist).begin()) it = (vlist).begin(); it != (vlist).end(); it++)
    if (chk(*it)) return 0;
  return 1;
}
void lemon() {
  scanf("%d", &n);
  long long s = (1LL << n) - 1, _s = s;
  long long i = 2;
  while (i * i <= s) {
    if (s % i == 0) {
      while (s % i == 0) s /= i;
      vlist.push_back(_s / i);
    }
    i++;
  }
  if (s != 1) vlist.push_back(_s / s);
  vlist.push_back(1);
  do {
    int s = 0;
    for (int i = (1); i <= (n); i++) c[i] = rand() % 2, s += c[i];
    if (!s) continue;
  } while (!check(_s));
  for (int i = (n); i >= (1); i--) printf("%d ", c[i]);
  printf("\n");
  for (int i = (1); i <= (n); i++) printf("1 ");
  printf("\n");
}
int main() {
  srand(time(0));
  ios::sync_with_stdio(true);
  lemon();
  return 0;
}
