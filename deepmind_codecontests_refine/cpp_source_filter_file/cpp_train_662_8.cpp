#include <bits/stdc++.h>
using namespace std;
int n, m, p;
long long d[100005], a[100005], s[100005], q[100005], f[100005], g[100005];
double inter(int i, int j) {
  return ((double)f[i] + s[i] - f[j] - s[j]) / (i - j);
}
int main() {
  cin >> n >> m >> p;
  for (int i = 2; i <= n; i++) cin >> d[i], d[i] += d[i - 1];
  for (int i = 1; i <= m; i++) {
    int h, t;
    cin >> h >> t;
    a[i] = t - d[h];
  }
  sort(a + 1, a + m + 1);
  for (int i = 1; i < m + 1; i++) s[i] = s[i - 1] + a[i];
  for (int i = 1; i < m + 1; i++) f[i] = i * a[i] - s[i];
  while (--p) {
    int head = 0, tail = 0;
    q[0] = 0;
    for (int i = 1; i < m + 1; i++) {
      while (head < tail and
             f[q[head]] + s[q[head]] - q[head] * a[i] >=
                 f[q[head + 1]] + s[q[head + 1]] - q[head + 1] * a[i])
        head++;
      g[i] = i * a[i] - s[i] + f[q[head]] + s[q[head]] - q[head] * a[i];
      while (head < tail and inter(i, q[tail]) <= inter(q[tail], q[tail - 1]))
        tail++;
      q[++tail] = i;
    }
    for (int i = 1; i < m + 1; i++) f[i] = g[i];
  }
  cout << f[m] << endl;
  return 0;
}
