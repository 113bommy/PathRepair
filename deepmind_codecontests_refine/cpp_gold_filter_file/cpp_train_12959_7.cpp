#include <bits/stdc++.h>
using namespace std;
const int maxn = 200000 + 10;
int now[maxn], dif;
void add(int x, int val) {
  bool b1 = (now[x] == 0);
  now[x] += val;
  bool b2 = (now[x] == 0);
  if (b1 && !b2) dif++;
  if (!b1 && b2) dif--;
}
int pos[maxn];
int id[5 * maxn], dis[5 * maxn];
bool found = 0;
long long ans;
int main() {
  int n, m;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &pos[i]), id[i] = id[2 * n - i] = i;
  scanf("%d", &m);
  for (int i = 1; i <= m; i++) {
    int x;
    scanf("%d", &x);
    add(x, -1);
  }
  if (m == 1) {
    printf("0\n");
    return 0;
  }
  for (int i = 2 * n - 1; i <= m + 2 * n - 3; i++) id[i] = id[i - 2 * n + 2];
  for (int i = 1; i < m + 2 * n - 3; i++)
    dis[i] =
        ((pos[id[i]] - pos[id[i + 1]]) > 0 ? (pos[id[i]] - pos[id[i + 1]])
                                           : (-(pos[id[i]] - pos[id[i + 1]])));
  long long all = 0LL;
  for (int i = 1; i <= m; i++) {
    add(id[i], 1);
    if (i < m) all += dis[i];
  }
  for (int i = 1; i <= 2 * n - 2; i++) {
    if (!dif) {
      if (!found)
        found = 1, ans = all;
      else if (ans != all) {
        printf("-1\n");
        return 0;
      }
    }
    if (i == 2 * n - 2) continue;
    add(id[i], -1);
    add(id[i + m], 1);
    all += dis[i + m - 1] - dis[i];
  }
  printf("%I64d\n", ans);
}
