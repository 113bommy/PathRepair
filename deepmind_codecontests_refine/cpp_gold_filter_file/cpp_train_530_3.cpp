#include <bits/stdc++.h>
using namespace std;
pair<long long, long long> cal(int lx, int ly, int ux, int uy) {
  pair<long long, long long> ret;
  long long area = 1ll * (ux - lx + 1) * (uy - ly + 1);
  if (area % 2 == 0) {
    ret = {area / 2, area / 2};
  } else {
    if ((lx + ly) % 2 == 0) {
      ret = {area - area / 2, area / 2};
    } else {
      ret = {area / 2, area - area / 2};
    }
  }
  return ret;
}
void solve() {
  long long n, m;
  cin >> n >> m;
  long long x1, x2, x3, x4, y1, y2, y3, y4;
  cin >> x1 >> y1 >> x2 >> y2;
  cin >> x3 >> y3 >> x4 >> y4;
  long long white, black;
  white = n * m - n * m / 2ll;
  black = n * m / 2ll;
  long long maxim, denis, overlap;
  maxim = (x2 - x1 + 1) * (y2 - y1 + 1);
  denis = (x4 - x3 + 1) * (y4 - y3 + 1);
  overlap = (max(0ll, min(x2, x4) - max(x1, x3) + 1)) *
            (max(0ll, min(y2, y4) - max(y1, y3) + 1));
  pair<long long, long long> rec_maxim, rec_denis, rec_overlap;
  rec_maxim = cal(x1, y1, x2, y2);
  rec_denis = cal(x3, y3, x4, y4);
  if (overlap > 0)
    rec_overlap = cal(max(x1, x3), max(y1, y3), min(x2, x4), min(y2, y4));
  else
    rec_overlap = make_pair(0, 0);
  black = black - (rec_denis.second + rec_maxim.second - rec_overlap.second) +
          denis;
  white = white - (rec_denis.first + rec_maxim.first - rec_overlap.first) +
          (maxim - overlap);
  cout << white << ' ' << black << '\n';
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
