#include <bits/stdc++.h>
using namespace std;
template <class T>
void read(T& x) {
  static int c, neg;
  x = neg = 0;
  c = getchar();
  while (!isdigit(c)) {
    if (c == '-') neg = 1;
    c = getchar();
  }
  while (isdigit(c)) {
    x = x * 10 + c - 48;
    c = getchar();
  }
  if (neg) x = -x;
}
template <class T>
void print(T x, char c = '\n') {
  static int st[233], top;
  if (x < 0) putchar('-'), x = -x;
  do {
    st[++top] = x % 10;
    x /= 10;
  } while (x);
  while (top) putchar(st[top--] + 48);
  putchar(c);
}
template <class T>
void cmax(T& x, const T& y) {
  x = (x > y) ? x : y;
}
template <class T>
void cmin(T& x, const T& y) {
  x = (x < y) ? x : y;
}
int n, k;
const int N = 2e3 + 5;
int l[N], r[N], a[N];
long long f[N];
int main() {
  read(n);
  read(k);
  for (int i = 1; i <= n; i++) {
    read(l[i]);
    read(r[i]);
    read(a[i]);
  }
  for (int i = n; i >= 1; i--) {
    long long ned = a[i];
    if (i < n && r[i] == l[i + 1]) {
      ned += f[i + 1];
    }
    if (1ll * (r[i] - l[i] + 1) * k < ned) {
      print(-1);
      exit(0);
    }
    f[i] = ned - (r[i] - l[i]) * k;
    if (f[i] < 0) {
      f[i] = 0;
    }
  }
  long long ans = 0, cur = k;
  for (int i = 1; i <= n; i++) ans += a[i];
  for (int i = 1; i <= n; i++) {
    if (cur < f[i]) {
      ans += cur;
      cur = k;
    }
    cur -= a[i];
    cur %= k;
    if (cur < 0) cur += k;
  }
  print(ans);
  return 0;
}
