#include <bits/stdc++.h>
using namespace std;
const long long INF = 3e18 + 5;
int N;
long long pt[100005][3];
long long ans[3];
pair<long long, long long> gSeg[4];
void input() {
  cin >> N;
  for (int i = 0; i < (N); i++) cin >> pt[i][0] >> pt[i][1] >> pt[i][2];
}
inline long long mod2(long long x) { return (x % 2 + 2) % 2; }
bool check(long long v) {
  for (int rem = 0; rem < (2); rem++) {
    pair<long long, long long> seg[4];
    for (int i = 0; i < (4); i++) {
      seg[i].first = gSeg[i].first - v;
      seg[i].second = gSeg[i].second + v;
      if (mod2(seg[i].first) != rem) seg[i].first++;
      if (mod2(seg[i].second) != rem) seg[i].second--;
    }
    int fail = 0;
    for (int i = 0; i < (4); i++)
      if (seg[i].first > seg[i].second) {
        fail = 1;
      }
    if (fail) continue;
    if (seg[0].second < seg[1].first + seg[2].first + seg[3].first) continue;
    if (seg[0].first > seg[1].second + seg[2].second + seg[3].second) continue;
    long long sum = seg[1].first + seg[2].first + seg[3].first;
    for (int i = (1); i <= (3); i++) {
      if (sum >= seg[0].first) break;
      if (sum + seg[i].second - seg[i].first < seg[0].first) {
        sum += seg[i].second - seg[i].first;
        seg[i].first = seg[i].second;
      } else {
        seg[i].first += seg[0].first - sum;
        if (mod2(seg[i].first) != rem) seg[i].first++;
        if (seg[i].first > seg[i].second) {
          seg[i].first--;
          sum--;
        } else {
          break;
        }
      }
    }
    ans[0] = (seg[2].first + seg[3].first) / 2;
    ans[1] = (seg[1].first + seg[3].first) / 2;
    ans[2] = (seg[1].first + seg[2].first) / 2;
    assert(mod2(seg[2].first + seg[3].first) == 0);
    assert(mod2(seg[1].first + seg[3].first) == 0);
    assert(mod2(seg[1].first + seg[2].first) == 0);
    return true;
  }
  return false;
}
void solve() {
  for (int i = 0; i < (4); i++) gSeg[i] = pair<long long, long long>(-INF, INF);
  for (int i = 0; i < (N); i++) {
    long long x = pt[i][0];
    long long y = pt[i][1];
    long long z = pt[i][2];
    gSeg[0].first = max(gSeg[0].first, x + y + z);
    gSeg[0].second = min(gSeg[0].second, x + y + z);
    gSeg[1].first = max(gSeg[1].first, -x + y + z);
    gSeg[1].second = min(gSeg[1].second, -x + y + z);
    gSeg[2].first = max(gSeg[2].first, x - y + z);
    gSeg[2].second = min(gSeg[2].second, x - y + z);
    gSeg[3].first = max(gSeg[3].first, x + y - z);
    gSeg[3].second = min(gSeg[3].second, x + y - z);
  }
  long long l = 0, r = 4e18 + 5;
  while (l < r) {
    long long m = (l + r) / 2;
    if (check(m))
      r = m;
    else
      l = m + 1;
  }
  assert(check(l));
  cout << ans[0] << " " << ans[1] << " " << ans[2] << "\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ;
  int ts;
  cin >> ts;
  for (int t = 0; t < (ts); t++) {
    input();
    solve();
  }
  return 0;
}
