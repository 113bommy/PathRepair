#include <bits/stdc++.h>
using namespace std;
template <typename T>
T in() {
  char ch;
  T n = 0;
  bool ng = false;
  while (1) {
    ch = getchar();
    if (ch == '-') {
      ng = true;
      ch = getchar();
      break;
    }
    if (ch >= '0' && ch <= '9') break;
  }
  while (1) {
    n = n * 10 + (ch - '0');
    ch = getchar();
    if (ch < '0' || ch > '9') break;
  }
  return (ng ? -n : n);
}
template <typename T>
inline T POW(T B, T P) {
  if (P == 0) return 1;
  if (P & 1)
    return B * POW(B, P - 1);
  else
    return (POW(B, P / 2) * POW(B, P / 2));
}
template <typename T>
inline T Gcd(T a, T b) {
  if (a < 0) return Gcd(-a, b);
  if (b < 0) return Gcd(a, -b);
  return (b == 0) ? a : Gcd(b, a % b);
}
template <typename T>
inline T Lcm(T a, T b) {
  if (a < 0) return Lcm(-a, b);
  if (b < 0) return Lcm(a, -b);
  return a * (b / Gcd(a, b));
}
long long Bigmod(long long base, long long power, long long MOD) {
  long long ret = 1;
  while (power) {
    if (power & 1) ret = (ret * base) % MOD;
    base = (base * base) % MOD;
    power >>= 1;
  }
  return ret;
}
bool isVowel(char ch) {
  ch = toupper(ch);
  if (ch == 'A' || ch == 'U' || ch == 'I' || ch == 'O' || ch == 'E')
    return true;
  return false;
}
long long ModInverse(long long number, long long MOD) {
  return Bigmod(number, MOD - 2, MOD);
}
bool isConst(char ch) {
  if (isalpha(ch) && !isVowel(ch)) return true;
  return false;
}
int toInt(string s) {
  int sm;
  stringstream second(s);
  second >> sm;
  return sm;
}
struct z {
  int x1, y1, x2, y2;
  z() {}
  z(int _, int __, int a, int b) {
    x1 = _, y1 = __;
    x2 = a, y2 = b;
  }
};
z ar[500007];
int Ln;
int X[500007], Y[500007];
int xl, yl;
int vis[1002][1002];
int Ok[1002][1002];
int vx[1002];
int vy[1002];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
void Dfs(int x, int y) {
  if (x < 0 || x == xl || y == yl || y < 0 || vis[x][y] || Ok[x][y]) return;
  Ok[x][y] = 1;
  for (int i = 0; i < 4; i++) Dfs(x + dx[i], y + dy[i]);
}
int main() {
  int n;
  cin >> n;
  int x = 0, y = 0;
  for (int i = 0; i < n; i++) {
    string c;
    int d;
    cin >> c >> d;
    if (c[0] == 'L') {
      ar[Ln++] = z(x - d, y, x + 1, y + 1);
      x -= d;
    }
    if (c[0] == 'R') {
      ar[Ln++] = z(x, y, x + d + 1, y + 1);
      x += d;
    }
    if (c[0] == 'U') {
      ar[Ln++] = z(x, y, x + 1, y + d + 1);
      y += d;
    }
    if (c[0] == 'D') {
      ar[Ln++] = z(x, y - d, x + 1, y + 1);
      y -= d;
    }
  }
  for (int i = 0; i < Ln; i++) {
    X[xl++] = ar[i].x1;
    X[xl++] = ar[i].x2;
    Y[yl++] = ar[i].y1;
    Y[yl++] = ar[i].y2;
  }
  sort(X, X + xl);
  sort(Y, Y + xl);
  xl = unique(X, X + xl) - X;
  yl = unique(Y, Y + yl) - Y;
  for (int i = 0; i < xl; i++) vx[i] = X[i];
  for (int i = 0; i < yl; i++) vy[i] = Y[i];
  for (int i = 0; i < n; i++) {
    int x1 = lower_bound(X, X + xl, ar[i].x1) - X;
    int x2 = lower_bound(X, X + xl, ar[i].x2) - X;
    int y1 = lower_bound(Y, Y + yl, ar[i].y1) - Y;
    int y2 = lower_bound(Y, Y + yl, ar[i].y2) - Y;
    for (int j = x1; j < x2; j++) {
      for (int k = y1; k < y2; k++) {
        vis[j][k] = 1;
      }
    }
  }
  xl--, yl--;
  for (int i = 0; i < xl; i++) {
    for (int j = 0; j < yl; j++) {
      if (i == 0 || i == xl - 1 || j == 0 || j == yl - 1) {
        Dfs(i, j);
      }
    }
  }
  long long int ans = 0;
  for (int i = 0; i < xl; i++) {
    for (int j = 0; j < yl; j++) {
      if (Ok[i][j]) continue;
      long long int a = (vx[i + 1] - vx[i]);
      long long int b = (vy[j + 1] - vy[j]);
      ans += a * b;
    }
  }
  printf("%lld\n", ans);
  return 0;
}
