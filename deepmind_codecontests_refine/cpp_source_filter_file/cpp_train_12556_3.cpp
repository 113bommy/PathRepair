#include <bits/stdc++.h>
using namespace std;
inline char gc() {
  static char buf[100000], *p1 = buf, *p2 = buf;
  return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2)
             ? EOF
             : *p1++;
}
inline int read() {
  int x = 0;
  char ch = getchar();
  bool positive = 1;
  for (; !isdigit(ch); ch = getchar())
    if (ch == '-') positive = 0;
  for (; isdigit(ch); ch = getchar()) x = x * 10 + ch - '0';
  return positive ? x : -x;
}
inline void write(int a) {
  if (a >= 10) write(a / 10);
  putchar('0' + a % 10);
}
inline void writeln(int a) {
  if (a < 0) {
    a = -a;
    putchar('-');
  }
  write(a);
  puts("");
}
const int mod = 1000000007, rev = (mod + 1) / 2, N = 20;
int ans, a[1 << N], n;
char ch[1 << N];
void FWT(int *a, int n) {
  for (int k = 1; k < n; k <<= 1) {
    for (int i = 0; i < n; i += k << 1) {
      for (int j = 0; j < k; j++) {
        int x = a[i + j];
        a[i + j] = (a[i + j] + a[i + j + k]) % mod;
        a[i + j + k] = (x - a[i + j + k]) % mod;
      }
    }
  }
}
void UFWT(int *a, int n) {
  for (int k = 1; k < n; k <<= 1) {
    for (int i = 0; i < n; i += k << 1) {
      for (int j = 0; j < k; j++) {
        int x = a[i + j];
        a[i + j] = (long long)(a[i + j] + a[i + j + k]) * rev % mod;
        a[i + j + k] = (long long)(x - a[i + j + k]) * rev % mod;
      }
    }
  }
}
int main() {
  n = read();
  scanf("%s", ch);
  for (int i = 0; i < (1 << n); i++) a[i] = ch[i] - '0';
  FWT(a, 1 << n);
  for (int i = 0; i < (1 << n); i++) a[i] = (long long)a[i] * a[i] % mod;
  UFWT(a, 1 << n);
  for (int i = 0; i < (1 << n); i++) {
    int sum = 0;
    for (int j = 0; j < n; j++)
      if (i >> j & 1) sum++;
    ans = (ans + (long long)a[i] * (1 << (n - sum))) % mod;
  }
  cout << (long long)(ans + mod) % mod * 3 % mod << endl;
}
