#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5, INF = 0x3f3f3f3f;
inline int read() {
  int s = 0, w = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') w = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') s = s * 10 + ch - '0', ch = getchar();
  return s * w;
}
int n, m;
long double f[maxn], ans, sum, a[maxn], b[maxn];
priority_queue<pair<long double, int>, vector<pair<long double, int> >,
               less<pair<long double, int> > >
    q;
int main() {
  n = read();
  f[n] = 1;
  for (register int i = 1; i <= n; ++i)
    cin >> a[i], a[i] /= 100,
        a[i] = 1 - a[i], b[i] = a[i],
        q.push(make_pair((1 - b[i] * a[i]) / (1 - b[i]), i)), f[n] *= 1 - b[i];
  ans = f[n] * n;
  for (register int i = n + 1; i <= 180000; ++i) {
    int x = q.top().second;
    q.pop();
    f[i] = f[i - 1] / (1 - b[x]) * (1 - b[x] * a[x]);
    ans += (f[i] - f[i - 1]) * i;
    b[x] *= a[x];
    q.push(make_pair((1 - b[x] * a[x]) / (1 - b[x]), x));
  }
  printf("%.12lf", ans);
  return 0;
}
