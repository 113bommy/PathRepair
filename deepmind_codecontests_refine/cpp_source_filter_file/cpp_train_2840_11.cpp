#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5, M = 5e5 + 5;
const long long INF = 1e18 + 5;
inline long long read() {
  long long sum = 0, fh = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') fh = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    sum = sum * 10 + c - '0';
    c = getchar();
  }
  return sum * fh;
}
inline int read2() {
  char c = getchar();
  while (c < '0' || c > '9') {
    c = getchar();
  }
  return c - '0';
}
inline int read3() {
  char c = getchar();
  while (c < 'a' || c > 'z') {
    c = getchar();
  }
  return c - 'a';
}
inline void write(long long x) {
  if (x < 0) putchar('-'), x = -x;
  if (x > 9) write(x / 10);
  putchar(x % 10 + '0');
}
inline int gcd(int x, int y) { return y == 0 ? x : gcd(y, x % y); }
inline long long ab(long long x) { return x < 0 ? -x : x; }
inline long long fpow(long long qwe, long long asd, long long zxc) {
  long long a = qwe, b = 1, c = asd;
  while (c) {
    if (c & 1) b = b * a % zxc;
    a = a * a % zxc;
    c >>= 1;
  }
  return b;
}
unsigned long long ans[N][3], cou = 0;
inline unsigned long long cz(unsigned long long x, unsigned long long y,
                             unsigned long long z) {
  ++cou;
  ans[cou][0] = x, ans[cou][1] = y, ans[cou][2] = z;
  return z == 1 ? (x + y) : (x ^ y);
}
stack<unsigned long long> qwe;
int main() {
  long long a[10];
  a[1] = read();
  qwe.push(a[1]);
  a[2] = a[1] + a[1];
  cz(a[1], a[1], 1);
  a[3] = a[1] ^ a[2];
  cz(a[1], a[2], 2);
  a[4] = a[1] + a[2];
  cz(a[1], a[2], 1);
  a[5] = a[3] + a[4];
  cz(a[3], a[4], 1);
  for (int i = 1; i <= 19; ++i) {
    a[1] = a[5];
    qwe.push(a[1]);
    a[2] = a[1] + a[1];
    cz(a[1], a[1], 1);
    a[3] = a[1] ^ a[2];
    cz(a[1], a[2], 2);
    a[4] = a[1] + a[2];
    cz(a[1], a[2], 1);
    a[5] = a[3] + a[4];
    cz(a[3], a[4], 1);
  }
  qwe.push(a[5]);
  a[1] = a[5];
  a[2] = a[1] + a[1];
  cz(a[1], a[1], 1);
  a[3] = a[1] ^ a[2];
  cz(a[1], a[2], 2);
  a[4] = a[1] + a[2];
  cz(a[1], a[2], 1);
  a[5] = a[3] + a[4];
  cz(a[3], a[4], 1);
  a[6] = a[2] ^ a[5];
  cz(a[2], a[5], 2);
  a[7] = a[4] ^ a[6];
  cz(a[4], a[6], 2);
  a[8] = a[1] ^ a[7];
  cz(a[1], a[7], 2);
  unsigned long long x = a[8];
  while (!qwe.empty()) {
    unsigned long long y = qwe.top();
    qwe.pop();
    while (x <= (unsigned long long)2e18) {
      if (y & x) {
        cz(y, x, 2);
        y = y ^ x;
      }
      cz(x, x, 1);
      x = x + x;
    }
    x = y;
  }
  cout << cou << endl;
  for (int i = 1; i <= cou; ++i) {
    write(ans[i][0]), putchar(' ');
    ans[i][2] == 1 ? putchar('+') : putchar('^');
    putchar(' ');
    write(ans[i][1]), putchar('\n');
  }
  cout << "1 ^ 1" << endl;
  cout << "0 ^ 1" << endl;
}
