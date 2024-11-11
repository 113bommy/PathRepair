#include <bits/stdc++.h>
using namespace std;
map<pair<int, int>, int> mp;
int n, m, x, y, a[100005];
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++)
    scanf("%d%d", &x, &y), mp[pair<int, int>(x, y)] = 1,
                                                mp[pair<int, int>(y, x)] = 1;
  for (int i = 1; i <= n; i++) a[i] = i;
  for (int i = 1; i <= 200; i++) {
    random_shuffle(a + 1, a + n + 1);
    bool f = 1;
    a[n + 1] = a[1];
    for (int j = 1; j <= m; j++)
      if (mp[pair<int, int>(a[j], a[j + 1])]) {
        f = 0;
        break;
      }
    if (!f) continue;
    for (int j = 1; j <= m; j++) printf("%d %d\n", a[j], a[j + 1]);
    return 0;
  }
  puts("-1");
  return 0;
}
