#include <bits/stdc++.h>
using namespace std;
int arr[5][5] = {{1, 0, 0, 0, 0},
                 {1, 1, 0, 0, 0},
                 {1, 3, 1, 0, 0},
                 {1, 5, 5, 1, 0},
                 {1, 7, 13, 7, 1}};
int n, output_length;
int a[4][(1 << 16)], b[4][(1 << 16)], c[4][(1 << 16)];
int u[(1 << 16)], u0[(1 << 16)], v0[(1 << 16)];
int rev[(1 << 16)];
int cur[(1 << 16)];
int po(int a, int b) {
  int c = 1, d = a;
  while (b) {
    if (b & 1) c = 1LL * c * d % 998244353;
    d = 1LL * d * d % 998244353;
    b >>= 1;
  }
  return c;
}
int rd(int num) {
  while (num < 0) num += 998244353;
  while (num >= 998244353) num -= 998244353;
  return num;
}
int bitrev(int num) {
  int ret = 0;
  for (int i = 0; i < 16; i++) {
    if (num & (1 << i)) ret += 1 << (15 - i);
  }
  return ret;
}
void convolve(int arr[], int mode, int kk) {
  for (int i = 0; i < (1 << 16); i++) cur[rev[i]] = arr[i];
  for (int len = 2; len <= (1 << 16); len *= 2) {
    int w = po(3, (998244353 - 1) / len);
    if (mode == 1) w = po(w, 998244353 - 2);
    int b, uu, vv;
    for (int j = 0; j < (1 << 16); j += len) {
      b = 1;
      for (int j2 = j; j2 < j + len / 2; j2++) {
        uu = cur[j2];
        vv = 1LL * b * cur[j2 + len / 2] % 998244353;
        cur[j2] = rd(uu + vv);
        cur[j2 + len / 2] = rd(uu - vv);
        b = 1LL * b * w % 998244353;
      }
    }
  }
  if (mode == -1) {
    int con = po((1 << 16), 998244353 - 2);
    for (int i = 0; i < (1 << 16); i++)
      cur[i] = (1LL * cur[i] * con) % 998244353;
  }
  for (int i = 0; i < (1 << 16); i++) arr[i] = cur[i];
  return;
}
void f(int n0) {
  if (n0 <= 1) {
    for (int i = 0; i <= 3; i++) {
      for (int j = 0; j < (1 << 16); j++) a[i][j] = 0;
      if (n0 + i >= 0 && n0 + i <= 4) {
        for (int j = 0; j < 5; j++) a[i][j] = arr[n0 + i][j];
      }
    }
    return;
  }
  int n1 = n0 / 2 - 1;
  f(n1);
  for (int i = 0; i <= 3; i++) {
    c[i][0] = 0;
    for (int j = 0; j < (1 << 16); j++) {
      b[i][j] = a[i][j];
      if (j) c[i][j] = a[i][j - 1];
    }
  }
  for (int i = 0; i <= 3; i++) {
    if ((n0 + i) & 1) {
      for (int j = 0; j < (1 << 16); j++) {
        u0[j] = b[(n0 + i) / 2 - n1][j];
        v0[j] = rd(b[(n0 + i + 1) / 2 - n1][j] + c[(n0 + i) / 2 - 1 - n1][j]);
      }
      convolve(u0, 1, (1 << 16));
      convolve(v0, 1, (1 << 16));
      for (int j = 0; j < (1 << 16); j++) {
        u[j] = (1LL * u0[j] * v0[j]) % 998244353;
      }
    } else {
      for (int j = 0; j < (1 << 16); j++) {
        u0[j] = b[(n0 + i) / 2 - n1][j];
      }
      convolve(u0, 1, (1 << 16));
      for (int j = 0; j < (1 << 16); j++) {
        u[j] = (1LL * u0[j] * u0[j]) % 998244353;
      }
      for (int j = 0; j < (1 << 16); j++) {
        u0[j] = b[(n0 + i) / 2 - 1 - n1][j];
        v0[j] = c[(n0 + i + 1) / 2 - 1 - n1][j];
      }
      convolve(u0, 1, (1 << 16));
      convolve(v0, 1, (1 << 16));
      for (int j = 0; j < (1 << 16); j++) {
        u[j] = (u[j] + 1LL * u0[j] * v0[j]) % 998244353;
      }
    }
    convolve(u, -1, (1 << 16));
    for (int j = 0; j < (1 << 16) / 2; j++) a[i][j] = rd(u[j]);
    for (int j = (1 << 16) / 2; j < (1 << 16); j++) a[i][j] = 0;
  }
  return;
}
int main() {
  for (int i = 0; i < (1 << 16); i++) rev[i] = bitrev(i);
  scanf("%d %d", &n, &output_length);
  f(n);
  for (int i = 1; i <= output_length; i++) {
    printf("%d%c", a[0][i], i == output_length ? '\n' : ' ');
  }
  return 0;
}
