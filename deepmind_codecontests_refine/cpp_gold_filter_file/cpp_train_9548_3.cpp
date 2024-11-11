#include <bits/stdc++.h>
using namespace std;
int v1[200005], v2[200005];
vector<int> g1[200005], g2[200005];
unsigned long long aux[20], s[200005], rasp[200005];
int main() {
  int n, m;
  unsigned long long a, b, c, ans = 0;
  int i, x, y, j;
  scanf("%d%d%llu%llu%llu", &n, &m, &a, &b, &c);
  for (i = 1; i <= m; i++) {
    scanf("%d%d", &x, &y);
    g1[x].push_back(y);
    g1[y].push_back(x);
  }
  for (i = 0; i < n; i++)
    for (auto it : g1[i])
      if (g1[it].size() > g1[i].size() ||
          (g1[it].size() == g1[i].size() && it > i))
        g2[i].push_back(it);
  for (i = 1; i < n; i++) {
    s[i] = s[i - 1] + a * i;
    rasp[i] = rasp[i - 1] + s[i - 1] + b * i * i;
    ans = ans + rasp[i - 1] + 1ll * i * (i - 1) / 2 * c * i;
  }
  for (i = 0; i < n; i++) {
    int u = 0;
    for (auto it : g1[i]) {
      v1[++u] = it;
      v2[it] = i + 1;
    }
    sort(v1 + 1, v1 + u + 1);
    s[u + 1] = 0;
    for (j = 1; j <= u && v1[j] < i; j++) {
      ans = ans - (v1[j] * a + i * b) * (n - i - 1) -
            1LL * (i + n) * (n - i - 1) / 2 * c;
      ans = ans - (v1[j] * a + i * c) * (i - v1[j] - 1) -
            1LL * (v1[j] + i) * (i - v1[j] - 1) / 2 * b;
      ans =
          ans - (v1[j] * b + i * c) * v1[j] - 1LL * v1[j] * (v1[j] - 1) / 2 * a;
    }
    for (j = 1; j <= u && v1[j] < i; j++) {
      s[j] = s[j - 1] + v1[j];
      ans = ans + s[j - 1] * a + (j - 1) * (v1[j] * b + c * i);
    }
    for (j = u; j >= 1 && v1[j] > i; j--) {
      s[j] = s[j + 1] + v1[j];
      ans = ans + s[j + 1] * c + (u - j) * (v1[j] * b + a * i);
    }
    for (j = 1; j < u; j++)
      if (v1[j] < i && v1[j + 1] > i)
        ans = ans + s[j] * a * (u - j) + i * b * j * (u - j) + s[j + 1] * c * j;
    for (auto it : g2[i])
      for (auto it2 : g2[it])
        if (v2[it2] == i + 1) {
          int auxi[3] = {i, it, it2};
          sort(auxi, auxi + 3);
          ans = ans - a * auxi[0] - b * auxi[1] - c * auxi[2];
        }
  }
  printf("%llu\n", ans);
  return 0;
}
