#include <bits/stdc++.h>
using namespace std;
const int NMAX = 4000010;
namespace Aint {
int aint[4 * NMAX], in_nod[4 * NMAX];
int l, r, val;
void update(int nod, int st, int dr) {
  if (st > r || dr < l) return;
  if (l <= st && r >= dr) {
    aint[nod] += val;
    in_nod[nod] += val;
    return;
  }
  update(2 * nod, st, (st + dr) / 2);
  update(2 * nod + 1, (st + dr) / 2 + 1, dr);
  aint[nod] = max(aint[2 * nod], aint[2 * nod + 1]) + in_nod[nod];
}
}  // namespace Aint
vector<pair<int, int>> points;
int main() {
  int n, r;
  scanf("%d%d", &n, &r);
  points.resize(n);
  for (auto& i : points) {
    scanf("%d%d", &i.first, &i.second);
    tie(i.first, i.second) = make_pair(i.first + i.second, i.first - i.second);
  }
  sort(points.begin(), points.end());
  int ans = 0;
  auto add = [&](int y, int val) {
    Aint::l = y - r + NMAX / 2;
    Aint::r = y + r + NMAX / 2;
    Aint::val = val;
    Aint::update(1, 0, NMAX);
  };
  for (int st = 0, dr = 0; dr < n; dr++) {
    add(points[dr].second, 1);
    while (points[dr].first - points[st].first > 2 * r)
      add(points[st].second, -1), st++;
    ans = max(ans, Aint::aint[1]);
  }
  cout << ans << '\n';
  return 0;
}
