#include <bits/stdc++.h>
inline long long rd() {
  long long _x = 0;
  int _ch = getchar(), _f = 1;
  for (; !isdigit(_ch) && (_ch != '-') && (_ch != EOF); _ch = getchar())
    ;
  if (_ch == '-') {
    _f = 0;
    _ch = getchar();
  }
  for (; isdigit(_ch); _ch = getchar()) _x = _x * 10 + _ch - '0';
  return _f ? _x : -_x;
}
void write(long long _x) {
  if (_x >= 10)
    write(_x / 10), putchar(_x % 10 + '0');
  else
    putchar(_x + '0');
}
inline void wrt(long long _x, char _p) {
  if (_x < 0) putchar('-'), _x = -_x;
  write(_x);
  if (_p) putchar(_p);
}
int n, m;
int a[5005];
int f[5005], h[5005], L[5005], R[5005];
int col[5005][4];
bool tag[5005];
int main() {
  n = rd(), m = rd();
  for (int i = 1; i <= n; i++) a[i] = rd();
  for (int i = 1; i <= m; i++) {
    f[i] = rd(), h[i] = rd();
    L[i] = n + 1;
    for (int j = 1, t = h[i]; j <= n; j++)
      if (a[j] == f[i]) {
        t--;
        if (t == 0) {
          L[i] = j;
          break;
        }
      }
    for (int j = n, t = h[i]; j >= 1; j--)
      if (a[j] == f[i]) {
        t--;
        if (t == 0) {
          R[i] = j;
          break;
        }
      }
    if (L[i] == n + 1) {
      i--, m--;
      continue;
    }
    tag[L[i]] = 1;
  }
  if (m == 0) {
    wrt(0, ' '), wrt(1, '\n');
    return 0;
  }
  tag[0] = 1;
  int mx = 0, sum = 0;
  for (int i = 0; i <= n; i++)
    if (tag[i]) {
      memset(col, 0, sizeof col);
      for (int j = 1; j <= m; j++)
        if (L[j] != i) {
          int cnt = 0;
          if (L[j] < i) cnt++;
          if (R[j] > i) cnt += 2;
          col[f[j]][cnt]++;
        }
      int A = i > 0, B = 1;
      for (int j = 1; j <= n; j++)
        if (a[i] != j) {
          int X = col[j][1] * col[j][2];
          int Y = col[j][3] * (col[j][3] - 1);
          int Z = col[j][1] * col[j][3] + col[j][2] * col[j][3];
          long long r1 = (long long)X + Y + Z;
          long long r2 = (long long)col[j][1] + col[j][2] + col[j][3] * 2;
          if (r1)
            A += 2, B = r1 * B % 1000000007;
          else if (r2)
            A++, B = r2 * B % 1000000007;
        } else {
          if (col[j][3] || col[j][2])
            B = 1ll * B * (col[j][3] + col[j][2]) % 1000000007, A++;
        }
      if (A > mx)
        mx = A, sum = B;
      else if (A == mx)
        sum = (sum + B) % 1000000007;
    }
  wrt(mx, ' '), wrt(sum, '\n');
}
