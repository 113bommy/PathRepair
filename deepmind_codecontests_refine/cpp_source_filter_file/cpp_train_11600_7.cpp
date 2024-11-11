#include <bits/stdc++.h>
using namespace std;
template <class T>
T abs(T x) {
  return x > 0 ? x : -x;
}
const int maxn = 110005;
int n, m, t, k;
int vis[maxn];
int x[maxn], y[maxn], z[maxn];
char s[maxn];
int main() {
  scanf("%s", s);
  n = strlen(s);
  for (int i = 1; i <= n; i++) {
    x[i] = x[i - 1];
    y[i] = y[i - 1];
    z[i] = z[i - 1];
    if (s[i - 1] == 'x') x[i]++;
    if (s[i - 1] == 'y') y[i]++;
    if (s[i - 1] == 'z') z[i]++;
  }
  scanf("%d", &m);
  while (m--) {
    int a, b;
    scanf("%d%d", &a, &b);
    t = b - a + 1;
    int t1 = x[b] - x[a - 1], t2 = y[b] - y[a - 1], t3 = z[b] - z[a - 1];
    int m1, m2, m3, flag = 1;
    m1 = max(max(t1, t2), t3);
    m3 = min(min(t1, t2), t3);
    m2 = t1 + t2 + t3 - m1 - m3;
    if ((t - 1) / 3 + 1 != m1) flag = 0;
    if ((t - 1 - 1) / 3 + 1 != m2) flag = 0;
    if ((t - 1 - 1 - 1) / 3 + 1 != m3) flag = 0;
    if (flag || t <= 1)
      printf("YES\n");
    else
      printf("NO\n");
  }
  return 0;
}
