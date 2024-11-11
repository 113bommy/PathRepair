#include <bits/stdc++.h>
using namespace std;
const int N = 200020;
const int vx[4] = {-1, 1, 1, -1};
const int vy[4] = {-1, 1, -1, 1};
int n, m, k, sx, sy, sdir, cnt;
long long ans;
set<pair<int, int> > all;
vector<pair<int, int> > lsA[N], lsB[N];
void build() {
  for (set<pair<int, int> >::iterator it = all.begin(); it != all.end(); ++it) {
    int first = it->first, second = it->second;
    lsA[(first - second + (m + 1))].push_back(*it);
    lsB[(first + second)].push_back(*it);
  }
  for (int i = 0; i <= n + m; ++i) {
    sort(lsA[i].begin(), lsA[i].end());
    sort(lsB[i].begin(), lsB[i].end());
  }
}
bool inrange(int first, int l, int r) {
  if (l > r) swap(l, r);
  return l <= first && first <= r;
}
vector<pair<int, int> > vp;
vector<pair<int, int> >::iterator it;
int nx, ny;
void shot(int first, int second, int dr) {
  bool foo;
  if (dr <= 1) {
    vp = lsA[(first - second + (m + 1))];
    foo = ((first - second + (m + 1)) == (sx - sy + (m + 1)));
  } else {
    vp = lsB[(first + second)];
    foo = ((first + second) == (sx + sy));
  }
  it = lower_bound(vp.begin(), vp.end(), make_pair(first, second));
  if (dr == 0 || dr == 3) --it;
  nx = it->first - vx[dr];
  ny = it->second - vy[dr];
  if (++cnt > 1 && foo && inrange(sx, first, it->first)) {
    ans += abs(sx - first);
    if (dr != sdir) ans += 2;
    return;
  }
  ans += abs(nx - first);
  bool o0 = (all.find(make_pair(it->first - vx[dr], it->second)) != all.end());
  bool o1 = (all.find(make_pair(it->first, it->second - vy[dr])) != all.end());
  if (o0 ^ o1) {
    if (o0) nx += vx[dr], dr = 3 - dr;
    if (o1) ny += vy[dr], dr = (dr + 2) % 4;
    ++ans;
  } else
    dr ^= 1;
  shot(nx, ny, dr);
}
int main() {
  scanf("%d %d %d", &n, &m, &k);
  for (int i = 1; i <= k; ++i) {
    int first, second;
    scanf("%d %d", &first, &second);
    all.insert(make_pair(first, second));
  }
  for (int i = 0; i <= n + 1; ++i) {
    all.insert(make_pair(i, 0));
    all.insert(make_pair(i, m + 1));
  }
  for (int j = 1; j <= m; ++j) {
    all.insert(make_pair(0, j));
    all.insert(make_pair(n + 1, j));
  }
  build();
  char str[5] = "";
  scanf("%d %d %s", &sx, &sy, &str);
  if (str[0] == 'N') sdir = 0;
  if (str[0] == 'S') sdir = 2;
  if (str[1] == 'E') sdir = 3 - sdir;
  cnt = 0;
  shot(sx, sy, sdir);
  sdir ^= 1;
  cnt = 0;
  shot(sx, sy, sdir);
  printf("%I64d\n", ans / 2);
}
