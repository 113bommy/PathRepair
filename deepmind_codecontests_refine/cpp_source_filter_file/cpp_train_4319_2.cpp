#include <bits/stdc++.h>
using namespace std;
map<pair<int, int>, int> mp;
set<int> s;
int x[200100], y[200100];
bool exist(int xx, int yy) {
  return mp.count(pair<int, int>(xx, yy)) && mp[pair<int, int>(xx, yy)] != -1;
}
bool check(int xx, int yy) {
  if (!exist(xx, yy)) return true;
  if (yy = 0) return true;
  if (!exist(xx - 1, yy - 1) && !exist(xx, yy - 1) && !exist(xx + 1, yy - 1))
    return false;
  return true;
}
bool vaild(int id) {
  int cx = x[id], cy = y[id];
  mp[pair<int, int>(cx, cy)] = -1;
  if (!check(cx - 1, cy + 1) || !check(cx, cy + 1) || !check(cx + 1, cy + 1)) {
    mp[pair<int, int>(cx, cy)] = id;
    return false;
  }
  mp[pair<int, int>(cx, cy)] = id;
  return true;
}
long long ans;
int n;
void update(int xx, int yy) {
  if (!exist(xx, yy)) return;
  int p = mp[pair<int, int>(xx, yy)];
  if (s.count(p)) s.erase(p);
  if (vaild(p)) s.insert(p);
}
void take(int p) {
  ans = (ans * n + p) % 1000000009;
  mp[pair<int, int>(x[p], y[p])] = -1;
  s.erase(p);
  for (int i = -2; i <= 2; ++i) {
    if (i != 0) update(x[p] + i, y[p]);
    if (i >= -1 && i <= 1) update(x[p] + i, y[p] - 1);
  }
}
int main() {
  while (~scanf("%d", &n)) {
    s.clear();
    mp.clear();
    for (int i = 0; i < n; ++i) {
      scanf("%d%d", &x[i], &y[i]);
      mp[pair<int, int>(x[i], y[i])] = i;
    }
    for (int i = 0; i < n; ++i)
      if (vaild(i)) s.insert(i);
    ans = 0;
    for (int i = 0; i < n; ++i) {
      if (i % 2 == 0)
        take(*(--s.end()));
      else
        take(*(s.begin()));
    }
    printf("%lld\n", ans);
  }
  return 0;
}
