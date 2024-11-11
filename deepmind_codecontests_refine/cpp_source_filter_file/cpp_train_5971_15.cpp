#include <bits/stdc++.h>
class Input {
 private:
  char buf[1000000], *p1, *p2;

 public:
  inline char getc() {
    if (p1 == p2) p2 = (p1 = buf) + fread(buf, 1, 1000000, stdin);
    return p1 == p2 ? EOF : *(p1++);
  }
  template <typename tp>
  inline Input& operator>>(tp& n) {
    n = 0;
    char c = getc();
    while (!isdigit(c)) c = getc();
    while (isdigit(c)) n = n * 10 + c - 48, c = getc();
    return (*this);
  }
} fin;
using namespace std;
int n, m;
long long c[70][70];
long long check(int a, int b, long long d) {
  if (a <= 60)
    return min(c[a][b], d);
  else if (b == 1)
    return min(1ll * a, d);
  long long v = 1;
  for (int i = 1; v <= d and i <= b; ++i) {
    if (d * i / (a - i) == 0) return d;
    v = v * (a - i) / i;
  }
  return min(v, d);
}
bool check(int x) {
  long long res = 1ll * m * x, sum = 1;
  for (int i = 1; i <= x and sum < n; ++i) {
    if (res / i == 0) break;
    long long now = check(x, i, res / i);
    sum += now;
    res -= i * now;
  }
  return sum >= n;
}
void solve() {
  fin >> n >> m;
  if (n == 1) {
    puts("0");
    return;
  }
  int l = 1, r = n;
  while (l <= r) {
    int mid = l + r >> 1;
    if (check(mid))
      r = mid - 1;
    else
      l = mid + 1;
  }
  printf("%d\n", r + 1);
}
void Prework() {
  c[0][0] = 1;
  for (int i = 1; i <= 60; c[i][0] = 1, ++i)
    for (int j = 1; j <= i; ++j) c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
}
int main() {
  Prework();
  int t;
  fin >> t;
  while (t--) solve();
  return 0;
}
