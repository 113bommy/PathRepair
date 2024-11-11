#include <bits/stdc++.h>
using namespace std;
const int oo = 1e9 + 7;
const int maxn = 2e5 + 7;
int dem, res = oo, a[maxn], n;
inline void read(int &x) {
  register int c = getchar();
  x = 0;
  int neg = 0;
  for (; ((c < 48 || c > 57) && c != '-'); c = getchar())
    ;
  if (c == '-') {
    neg = 1;
    c = getchar();
  }
  for (; c > 47 && c < 58; c = getchar()) {
    x = (x << 1) + (x << 3) + c - 48;
  }
  if (neg) x = -x;
}
inline void writeln(long long x) {
  char buffor[21];
  register int i = 0;
  int neg = 0;
  if (x < 0) {
    neg = 1;
    x = -x;
  }
  do {
    buffor[i++] = (x % 10) + '0';
    x /= 10;
  } while (x);
  i--;
  if (neg) putchar('-');
  while (i >= 0) putchar(buffor[i--]);
  putchar('\n');
}
void nhap() {
  read(n);
  for (int i = (1), _b = (n); i <= _b; ++i) read(a[i]);
  sort(a + 1, a + n + 1);
}
void solve() {
  for (int i = (2), _b = (n); i <= _b; ++i) res = min(res, a[i] - a[i - 1]);
  for (int i = (2), _b = (n); i <= _b; ++i)
    if (a[i] - a[i - 1] == res) dem++;
}
void print() { cout << res << ' ' << dem; }
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  nhap();
  solve();
  print();
}
