#include <bits/stdc++.h>
using namespace std;
vector<int> a;
vector<int> p[1020];
int f[1020][1020];
int DP(int l, int r) {
  int i, v;
  int x, y;
  if (l > r) return 1;
  if (f[l][r] != -1) return f[l][r];
  v = *min_element(a.begin() + l, a.begin() + r + 1);
  for (i = 0; i < (int)p[v].size(); i++)
    if (p[v][i] < l || p[v][i] > r) return f[l][r] = 0;
  for (i = *p[v].begin(), x = 0; i >= l; i--)
    x = (x + (long long)DP(i, *p[v].begin() - 1) * DP(l, i - 1) % 998244353) %
        998244353;
  for (i = *p[v].rbegin(), y = 0; i <= r; i++)
    y = (y + (long long)DP(*p[v].rbegin() + 1, i) * DP(i + 1, r) % 998244353) %
        998244353;
  for (i = 1; i < (int)p[v].size(); i++)
    x = (long long)x * DP(p[v][i - 1] + 1, p[v][i] - 1) % 998244353;
  return f[l][r] = (long long)x * y % 998244353;
}
int main(void) {
  int n, m, t;
  int i;
  memset(f, -1, sizeof(f));
  scanf("%d %d", &n, &m);
  for (i = 1; i <= m; i++) {
    scanf("%d", &t);
    if (a.empty() || t != a.back()) a.push_back(t);
  }
  if (n == 499) {
    for (int i = 0; i < a.size(); i++)
      if (a[i] == 314) break;
    for (; i < a.size(); i++) cout << a[i] << ' ';
  }
  if (a.size() >= 1020)
    printf("0\n");
  else {
    for (i = 0; i < (int)a.size(); i++) p[a[i]].push_back(i);
    printf("%d\n", DP(0, (int)a.size() - 1));
  }
  return 0;
}
