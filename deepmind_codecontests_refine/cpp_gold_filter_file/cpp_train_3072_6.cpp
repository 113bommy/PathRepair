#include <bits/stdc++.h>
using namespace std;
const int maxn = 100000;
struct point {
  long long y1, y2;
  bool operator<(const point &rhs) const {
    return y1 > rhs.y1 || (y1 == rhs.y1 && y2 > rhs.y2);
  }
} p[maxn + 10];
int n;
long long x1, x2;
long long d[maxn + 10];
template <class T>
void Read(T &x) {
  static char c;
  bool f(0);
  while (c = getchar(), c != EOF) {
    if (c == '-')
      f = 1;
    else if (c >= '0' && c <= '9') {
      x = c - '0';
      while (c = getchar(), c >= '0' && c <= '9') x = x * 10 + c - '0';
      if (f) x = -x;
      ungetc(c, stdin);
      return;
    }
  }
}
long long max(long long x, long long y) { return x > y ? x : y; }
int main() {
  Read(n);
  Read(x1);
  Read(x2);
  for (int i = 1; i <= n; i++) {
    int k, b;
    Read(k);
    Read(b);
    p[i].y1 = k * x1 + b;
    p[i].y2 = k * x2 + b;
  }
  sort(p + 1, p + n + 1);
  for (int i = 2; i <= n; i++) {
    if (p[i].y2 > p[i - 1].y2) {
      printf("YES");
      return 0;
    }
  }
  printf("NO");
}
