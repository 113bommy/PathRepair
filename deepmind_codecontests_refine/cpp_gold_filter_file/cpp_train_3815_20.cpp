#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-11;
const double pi = acos(-1.0);
const int mod = 1000000009;
const int inf = 1000000000;
template <class T>
inline void checkmin(T &a, T b) {
  if (b < a) a = b;
}
template <class T>
inline void checkmax(T &a, T b) {
  if (b > a) a = b;
}
template <class T>
inline T sqr(T x) {
  return x * x;
}
int p[100010], f[100010];
int getfather(int x) {
  if (f[x] != x) f[x] = getfather(f[x]);
  return f[x];
}
int main() {
  int n, m;
  cin >> n >> m;
  p[0] = 1;
  for (int i = 1; i < m; i++) p[i] = (p[i - 1] * 2) % mod;
  for (int i = 1; i <= n; i++) f[i] = i;
  int cnt = 0;
  while (m--) {
    int x, y;
    scanf("%d%d", &x, &y);
    int fx = getfather(x), fy = getfather(y);
    if (fx == fy)
      cnt++;
    else
      f[fx] = fy;
    printf("%d\n", (p[cnt] + mod - 1) % mod);
  }
}
