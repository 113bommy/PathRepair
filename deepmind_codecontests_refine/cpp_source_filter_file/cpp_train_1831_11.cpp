#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const long long INF64 = 1e18;
const long double EPS = 1e-7;
mt19937 myrand(time(NULL));
const int N = 120 + 7;
int n;
int a[N][5];
bool read() {
  if (scanf("%d", &n) != 1) return 0;
  for (int i = 0; i < (n); i++)
    for (int j = 0; j < (5); j++) scanf("%d", &a[i][j]);
  return 1;
}
int acn[5];
int getScore(int ac, int n, int t) {
  int pr = -1;
  if (ac != 0 && n / ac < 2)
    pr = 500;
  else if (ac != 0 && n / ac < 4)
    pr = 1000;
  else if (ac != 0 && n / ac < 8)
    pr = 1500;
  else if (ac != 0 && n / ac < 16)
    pr = 2000;
  else if (ac != 0 && n / ac < 32)
    pr = 2500;
  else
    pr = 3000;
  return pr - (pr / 250) * t;
}
bool check(int mid) {
  int s0 = 0, s1 = 0;
  for (int i = 0; i < (5); i++) {
    if (a[0][i] != -1 && a[1][i] != -1 && a[1][i] <= a[0][i]) {
      s0 += getScore(acn[i] + mid, n + mid, a[0][i]);
      s1 += getScore(acn[i] + mid, n + mid, a[1][i]);
    } else {
      if (a[0][i] != -1) s0 += getScore(acn[i], n + mid, a[0][i]);
      if (a[1][i] != -1) s1 += getScore(acn[i], n + mid, a[1][i]);
    }
  }
  return s0 > s1;
}
void solve() {
  memset(acn, 0, sizeof(acn));
  for (int i = 0; i < (n); i++)
    for (int j = 0; j < (5); j++)
      if (a[i][j] != -1) ++acn[j];
  for (int i = 0; i < (3000); i++)
    if (check(i)) {
      printf("%d\n", i);
      return;
    }
  printf("-1\n");
}
int main() {
  while (read()) solve();
  return 0;
}
