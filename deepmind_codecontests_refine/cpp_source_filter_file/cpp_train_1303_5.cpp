#include <bits/stdc++.h>
using namespace std;
int n, m, b[1000000];
set<pair<int, int>> s;
struct arr {
  int x, y, num, pre, nex;
} a[1000000];
bool cmp(arr x, arr y) {
  return ((x.x < y.x) || ((x.x == y.x) && (x.num < y.num)));
}
int foot(int x, int y) {
  if (x == y) return m * 2 + 5;
  int len = (a[y].x - a[x].x + m) % m;
  if (a[y].num < a[x].num) len = (len + a[y].y) % m;
  if (len <= a[x].y) return 1;
  if (a[x].y <= a[y].y) return m * 2 + 5;
  return (len - a[y].y - 1) / (a[x].y + a[y].y) + 1;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    a[i].num = i;
    scanf("%d%d", &a[i].x, &a[i].y);
  }
  sort(a + 1, a + n + 1, cmp);
  for (int i = 1; i <= n; i++) {
    b[a[i].num] = i;
    a[i].pre = i - 1 ? i - 1 : n;
    a[i].nex = i % n + 1;
    s.insert(make_pair(foot(i, a[i].nex), a[i].num));
  }
  while (s.size() > 1) {
    set<pair<int, int>>::iterator it = s.begin();
    if ((it->first) > m) break;
    int x = b[it->second], y = it->first;
    s.erase(it);
    s.erase(make_pair(foot(a[x].pre, x), a[a[x].pre].num));
    s.erase(make_pair(foot(a[x].nex, a[a[x].nex].nex), a[a[x].nex].num));
    a[x].x = (a[x].x + y - 1) % m + 1;
    --a[x].y;
    a[x].nex = a[a[x].nex].nex;
    a[a[x].nex].pre = x;
    s.insert(make_pair(foot(a[x].pre, x), a[a[x].pre].num));
    s.insert(make_pair(foot(x, a[x].nex), a[x].num));
  }
  printf("%d\n", s.size());
  set<pair<int, int>>::iterator it = s.begin();
  do {
    printf("%d ", it->second);
    ++it;
  } while (it != s.end());
}
