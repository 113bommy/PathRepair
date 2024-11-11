#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  long long r;
  while (b != 0) {
    r = a % b;
    a = b;
    b = r;
  }
  return a;
}
long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }
const int maxn = 100010;
int n, m;
int a[maxn];
int b[maxn];
void solve() {
  scanf("%d%d", &n, &m);
  int c;
  scanf("%d", &c);
  for (int i = 0; i < c; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    a[i] = x + y;
    b[i] = x - y;
  }
  sort(a, a + c);
  sort(b, b + c);
  int h;
  scanf("%d", &h);
  int dmax = INT_MAX, imax;
  for (int i = 0; i < h; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    int u = x + y;
    int v = x - y;
    int tmp = max(max(abs(a[0] - u), abs(a[c - 1] - u)),
                  max(abs(b[0] - v), abs(b[c - 1] - v)));
    if (dmax > tmp) {
      dmax = tmp;
      imax = i + 1;
    }
  }
  printf("%d\n%d", dmax, imax);
}
int main() {
  solve();
  return 0;
}
