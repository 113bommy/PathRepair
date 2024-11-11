#include <bits/stdc++.h>
using namespace std;
struct P {
  int x, y;
  bool operator<(const P &a) const {
    if (y != a.y) return y > a.y;
    return x > a.x;
  }
};
vector<int> v;
int i, n, d, m, k, a, b, c, e;
int o[11];
long long l[11];
int j[11];
int dx[10] = {0, 1, 0, -1, 1, 1, -1, -1}, dy[10] = {1, 0, -1, 0, 1, -1, 1, -1},
    dz[10] = {0, 0, 0, 0, 1, -1};
long long mod = 1000000007, mod2 = 1000000009, mod3 = 2017;
long long x, z[11][5555], y;
double pi = 3.14159265;
P u[1];
stack<int> s;
queue<int> q;
char r[551];
bool as(int a, int b) { return a > b; }
long long f(int n, int m) {
  if (m > y) return -987654321987654321;
  if (n == 9) {
    long long p;
    if (k)
      p = min(k * l[k], (y - m) / k * k);
    else
      p = 0;
    return m + p;
  }
  if (n == k) return f(n + 1, m);
  if (z[n][m] >= 0) return z[n][m];
  long long p = 0;
  for (int i = 0; i <= l[n]; i++) p = max(p, f(n + 1, m + i * n));
  return z[n][m] = p;
}
int main() {
  memset(z, -1, sizeof(z));
  scanf("%lld", &y);
  for (int t = 1; t <= 8; t++) scanf("%lld", &l[t]);
  for (int t = 1; t <= 4; t++)
    if (l[t] % 2)
      l[t * 2] += l[t] / 2, l[t] = 1;
    else if (l[t])
      l[t * 2] += (l[t] - 2) / 2, l[t] = 2;
  if (l[8] >= 6) {
    k = 8;
  } else if (l[7] >= 7) {
    k = 7;
  } else if (l[6] >= 6) {
    k = 6;
  } else if (l[5] >= 7) {
    k = 5;
  }
  if (k)
    for (int t = 5; t <= 8; t++)
      if (t != k)
        x = max((l[t] - t + 1) / k, (long long)0), l[t] -= x * k, l[k] += x * t;
  printf("%d", f(1, 0));
}
