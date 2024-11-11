#include <bits/stdc++.h>
using namespace std;
const int maxn = 2010;
const int mod = 1e9 + 7;
int a[maxn][maxn];
int ret[maxn][maxn];
int b[maxn];
long long buf[maxn][maxn];
int n, k;
void mul(int a[][maxn], int b[][maxn]) {
  memset(buf, 0, sizeof(buf));
  for (int j = 0; j < n; j++) {
    for (int k = 0; k <= j; k++) {
      buf[0][k] = buf[0][k] + (long long)a[0][j] * b[j][k];
      if (buf[0][k] >= mod) buf[0][k] %= mod;
    }
  }
  for (int i = 1; i < n; i++) {
    for (int j = i; j <= i; j++) {
      buf[i][j] = buf[0][j - i];
    }
  }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
      a[i][j] = buf[i][j];
    }
}
void get(int k) {
  for (int i = 0; i < n; i++) ret[i][i] = 1;
  while (k) {
    if (k & 1) mul(ret, a);
    mul(a, a);
    k >>= 1;
  }
}
void print(int a[][maxn]) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      printf("%d ", a[i][j]);
    }
    puts("");
  }
}
int main() {
  cin >> n >> k;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
      if (i <= j) a[i][j] = 1;
    }
  get(k);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[0][i]);
  }
  mul(a, ret);
  for (int i = 0; i < n; i++) {
    cout << a[0][i] << " ";
  }
  return 0;
}
