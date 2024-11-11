#include <bits/stdc++.h>
using namespace std;
const int maxn = 100000 + 7;
set<int> s1;
set<int> s2;
int vis[maxn];
int main() {
  int n, m, flag = 1;
  scanf("%d%d", &n, &m);
  memset(vis, 0, sizeof(vis));
  if (m == 0) {
    cout << n - 1 << endl;
    return 0;
  }
  for (int i = 1; i <= m; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    if (a < b) swap(a, b);
    s1.insert(b);
    s2.insert(a);
    vis[a] = 1;
    vis[b] = 1;
  }
  int a = *--s1.end();
  int b = *s2.begin();
  if (a >= b) {
    cout << 0;
    return 0;
  }
  int cnt1 = 0, cnt2 = 0;
  for (int i = 1; i <= n; i++) {
    if (vis[i] == 0) {
      if (i < a) cnt1++;
      if (i > a) cnt2++;
    }
  }
  cout << cnt2 + 1 << endl;
  return 0;
}
