#include <bits/stdc++.h>
using namespace std;
template <class T>
void read(T &x) {
  T res = 0, f = 1;
  char c = getchar();
  while (!isdigit(c)) {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (isdigit(c)) {
    res = (res << 3) + (res << 1) + c - '0';
    c = getchar();
  }
  x = res * f;
}
inline void print(long long x) {
  if (x < 0) {
    putchar('-');
    x = -x;
  }
  if (x > 9) print(x / 10);
  putchar(x % 10 + '0');
}
const long long maxn = 1e5 + 10;
const long long mod = 1e9 + 7;
long long n;
int main() {
  long long _s = 1;
  read(_s);
  for (long long _ = 1; _ <= _s; _++) {
    read(n);
    for (long long i = 1; i <= n; i++) cout << 2 * i - 1 << " ";
    cout << endl;
  }
  return 0;
}
