#include <bits/stdc++.h>
using namespace std;
const long long N = 1e6 + 10;
const long long K = 2e6;
const long long inf = 1e18;
const long long mod = 1e9 + 7;
long long xs, ys, ax, ay, bx, by;
long long sx, sy, t;
vector<pair<long long, long long> > dots;
bool can(long long l, long long r) {
  long long curt = 0;
  long long curx = sx;
  long long cury = sy;
  for (long long i = l; i <= r; ++i) {
    curt += abs(dots[i].first - curx) + abs(dots[i].second - cury);
    curx = dots[i].first;
    cury = dots[i].second;
  }
  if (curt <= t) return true;
  curt = 0;
  curx = sx;
  cury = sy;
  for (long long i = r; i >= l; --i) {
    curt += abs(dots[i].first - curx) + abs(dots[i].second - cury);
    curx = dots[i].first;
    cury = dots[i].second;
  }
  if (curt <= t) return true;
  return false;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> xs >> ys >> ax >> ay >> bx >> by;
  cin >> sx >> sy >> t;
  dots.emplace_back(xs, ys);
  while (true) {
    long long px = dots.back().first;
    long long py = dots.back().second;
    if (inf / ax <= px || inf / ay <= py) break;
    px *= ax;
    py *= ay;
    if (inf - bx <= px || inf - by <= py) break;
    px += bx;
    py += by;
    dots.emplace_back(px, py);
  }
  long long ans = 0;
  for (long long i = 0; i < dots.size(); ++i)
    for (long long j = i; j < dots.size(); ++j)
      if (can(i, j)) ans = max(ans, j - i + 1);
  cout << ans << endl;
}
