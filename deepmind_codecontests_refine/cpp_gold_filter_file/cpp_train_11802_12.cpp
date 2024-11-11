#include <bits/stdc++.h>
using namespace std;
int a[2][2], b[2][2];
long long tmp[2][2], n, l, r, k, modul;
int init(int a[2][2], int val) {
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 2; j++) a[i][j] = 0;
  for (int i = 0; i < 2; i++) a[i][i] = val;
}
int mul(int a[2][2], int b[2][2], int c[2][2]) {
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 2; j++) tmp[i][j] = 0;
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 2; j++)
      for (int k = 0; k < 2; k++)
        tmp[i][j] = (tmp[i][j] + (long long)a[i][k] * b[k][j]) % modul;
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 2; j++) c[i][j] = (int)(tmp[i][j] % modul);
}
void print(int a[2][2]) {
  cout << "MATRIX: " << endl;
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) cout << a[i][j] << " ";
    cout << endl;
  }
}
void mp(int a[2][2], long long deg, int b[2][2]) {
  if (deg == 0)
    init(b, 1);
  else {
    mp(a, deg / 2, b);
    mul(b, b, b);
    if (deg % 2) mul(a, b, b);
  }
}
int mp2(int n, long long deg) {
  if (deg == 0) return 1;
  int tmp = mp2(n, deg / 2);
  tmp = ((long long)tmp * tmp) % modul;
  if (deg % 2) tmp = ((long long)tmp * n) % modul;
  return tmp;
}
long long f(long long n) {
  if (n <= 2) return 1LL;
  mp(a, n - 2, b);
  return ((long long)b[0][0] + b[0][1]) % modul;
}
long long g(long long l, long long r, long long n) {
  long long d, ret = 1, cur, k, low, high;
  for (d = 1; d * d <= max(r, 1000000LL); d++) {
    cur = r / d - (l - 1) / d;
    if (cur >= n) ret = max(ret, d);
  }
  k = r / d - (l - 1) / d;
  while (k >= n) {
    low = r / (k + 1);
    high = r / k;
    cur = r / high - (l - 1) / high;
    if (cur >= n) ret = max(ret, high);
    cur = r / (low + 1) - (l - 1) / (low + 1);
    if (cur >= n) ret = max(ret, low + 1);
    k--;
  }
  return ret;
}
int main() {
  cin >> modul >> l >> r >> k;
  memset(a, 0, sizeof(a));
  a[0][0] = a[0][1] = a[1][0] = 1;
  cout << f(g(l, r, k)) % modul << endl;
  return 0;
}
