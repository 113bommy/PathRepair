#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-9;
template <class T>
T f_max(T a, T b) {
  return a > b ? a : b;
}
template <class T>
T f_min(T a, T b) {
  return a < b ? a : b;
}
template <class T>
T f_abs(T a) {
  return a > 0 ? a : -a;
}
template <class T>
T gcd(T a, T b) {
  return b ? gcd(b, a % b) : a;
}
template <class T>
T lcm(T a, T b) {
  return a / gcd(a, b) * b;
}
template <class T>
void swap(T *a, T *b) {
  T c;
  c = a;
  a = b;
  b = c;
}
int mp[15][15];
int x[15], y[15];
int num[15], tol;
int n;
char s[15];
void init() {
  memset(mp, 0, sizeof(mp));
  for (int i = 1; i <= 3; i++)
    for (int j = 1; j <= 3; j++) mp[i][j] = 1;
  mp[4][2] = 1;
  x[1] = 1;
  x[2] = 1;
  x[3] = 1;
  y[1] = 1;
  y[2] = 2;
  y[3] = 3;
  x[4] = 2;
  x[5] = 2;
  x[6] = 2;
  y[4] = 1;
  y[5] = 2;
  y[6] = 3;
  x[7] = 3;
  x[8] = 3;
  x[9] = 3;
  y[7] = 1;
  y[8] = 2;
  y[9] = 3;
  x[0] = 4;
  y[0] = 2;
}
int check(int px, int py) {
  if (tol == 1) return 1;
  for (int i = 1; i < tol; i++) {
    int u, v;
    u = num[i];
    v = num[i - 1];
    int dx = x[u] - x[v];
    int dy = y[u] - y[v];
    px += dx;
    py += dy;
    if (px < 0 || px > 4 || py < 0 || py > 4 || mp[px][py] == 0) return 0;
  }
  return 1;
}
void solve() {
  int flag = 0;
  for (int i = 0; i <= 9; i++) {
    if (i != num[0] && check(x[i], y[i])) {
      flag = 1;
      break;
    }
  }
  if (flag)
    printf("NO\n");
  else
    printf("YES\n");
}
int main() {
  init();
  scanf("%d", &n);
  getchar();
  scanf("%s", s);
  tol = 0;
  for (int i = 0; s[i] != '\0'; i++) num[tol++] = s[i] - '0';
  solve();
  return 0;
}
