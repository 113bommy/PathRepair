#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;
int n, m, x, y, dx, dy;
char dir[5];
map<pair<int, int>, bool> MP;
map<pair<pair<int, int>, int>, bool> GP;
long long ans = 1;
void fix() {
  if (x == 1) dx = 1;
  if (x == n) dx = -1;
  if (y == 1) dy = 1;
  if (y == m) dy = -1;
}
void shoot() {
  int k = inf;
  if (dx < 0)
    k = min(k, x - 1);
  else
    k = min(k, n - x);
  if (dy < 0)
    k = min(k, y - 1);
  else
    k = min(k, m - y);
  x += k * dx;
  y += k * dy;
  ans += k;
  fix();
}
int main() {
  scanf("%d %d", &n, &m);
  scanf("%d %d %s", &x, &y, dir);
  dx = dir[0] == 'U' ? -1 : 1;
  dy = dir[1] == 'L' ? -1 : 1;
  int need = 0;
  need += (m + 1) / 2;
  need += (m + (n & 1)) / 2;
  need += (n + 1) / 2;
  need += (n + (m & 1)) / 2;
  need -= 1 + (n & 1) + (m & 1) + !(n + m & 1);
  if (x + y & 1) need = 2 * (n + m - 2) - need;
  for (fix();; shoot()) {
    pair<int, int> cp = make_pair(x, y);
    if (GP.find(make_pair(cp, dx + dy)) != GP.end())
      break;
    else
      GP[make_pair(cp, dx + dy)] = 1;
    if (MP.find(cp) == MP.end()) {
      MP[cp] = 1;
      if (--need == 0) {
        cout << ans << endl;
        return 0;
      }
    }
  }
  puts("-1");
}
