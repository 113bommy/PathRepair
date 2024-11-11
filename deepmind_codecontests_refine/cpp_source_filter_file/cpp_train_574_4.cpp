#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
int n, k, tot;
int cnt[maxn << 1], num[maxn << 1], val[maxn << 1];
long long ans[maxn];
map<int, int> mp;
struct line {
  int x, ya, yb, opt;
} l[maxn << 1];
inline int cmp(line a, line b) { return a.x < b.x; }
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    l[2 * i - 1] = line{a, b, b + k - 1, 1},
              l[2 * i] = line{a + k, b, b + k - 1, -1};
    num[2 * i - 1] = b, num[2 * i] = b + k;
  }
  sort(num + 1, num + 1 + 2 * n), sort(l + 1, l + 1 + 2 * n, cmp);
  for (int i = 1; i <= 2 * n; i++)
    if (i == 1 || num[i] != num[i - 1]) mp[num[i]] = ++tot, val[tot] = num[i];
  for (int i = 1; i <= 2 * n; i++) {
    int ya = mp[l[i].ya], yb = mp[l[i].yb + 1], opt = l[i].opt,
        len = l[2 * n].x - l[i].x;
    for (int j = ya; j < yb; j++) {
      ans[cnt[j]] -= 1ll * len * (val[j + 1] - val[j]);
      cnt[j] += opt;
      ans[cnt[j]] += 1ll * len * (val[j + 1] - val[j]);
    }
  }
  for (int i = 1; i <= n; i++) printf("%d%c", ans[i], i == n ? '\n' : ' ');
  return 0;
}
