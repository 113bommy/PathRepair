#include <bits/stdc++.h>
using namespace std;
int n, m, p[3030];
pair<int, int> e[3030];
pair<int, pair<int, int> > f[3030];
int findset(int x) {
  if (p[x] == x) return x;
  return p[x] = findset(p[x]);
}
void unionset(int x, int y) {
  if (rand() % 2)
    p[x] = y;
  else
    p[y] = x;
}
bool check(int l, int r) {
  for (int i = 0; i < n; i++) p[i] = i;
  for (int i = 0; i < m; i++) {
    if (l < f[i].first || r > f[i].second.first) continue;
    int to = f[i].second.second;
    int x1 = findset(e[to].first);
    int y1 = findset(e[to].second);
    if (x1 != y1) unionset(x1, y1);
  }
  if (findset(p[0]) == findset(p[n - 1]))
    return 1;
  else
    return 0;
}
int main() {
  srand(time(0));
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int x, y, l, r;
    cin >> x >> y >> l >> r;
    x--;
    y--;
    e[i] = make_pair(x, y);
    f[i] = make_pair(l, make_pair(r, i));
  }
  sort(f, f + n);
  int ans = 0;
  for (int i = 0; i < m; i++) {
    int L = f[i].first;
    int l = 1, r = 1000000;
    while (l <= r) {
      int x = (l + r) / 2;
      if (check(L, x)) {
        ans = max(ans, x - L + 1);
        l = x + 1;
      } else
        r = x - 1;
    }
  }
  if (ans == 0)
    cout << "Nice work, Dima!";
  else
    cout << ans << endl;
  return 0;
}
