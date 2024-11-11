#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3e5;
const int INF = 1e9;
int n;
int ct[MAXN][2];
vector<int> ok(int d) {
  vector<int> bad(2, -1);
  int loX = 0, hiX = INF;
  int loY = 0, hiY = INF;
  int loD = -INF, hiD = INF;
  for (int i = 0; i < n; i++) {
    int x = ct[i][0], y = ct[i][1];
    loX = max(loX, x - d);
    hiX = min(hiX, x + d);
    loY = max(loY, y - d);
    hiY = min(hiY, y + d);
    loD = max(loD, y - x - d);
    hiD = min(hiD, y - x + d);
  }
  if (loX > hiX || loY > hiY || loD > hiD) return bad;
  auto check1 = [&](int x) {
    int lo = max(loY, loD + x), hi = min(hiY, hiD + x);
    if (lo > hi) return bad;
    if (x || hi) return vector<int>{x, hi};
    return bad;
  };
  auto check2 = [&](int y) {
    int lo = max(loX, y - hiD), hi = min(hiX, y - loD);
    if (lo > hi) return bad;
    if (y || hi) return vector<int>{hi, y};
    return bad;
  };
  if (bad != check1(loX)) return check1(loX);
  if (bad != check1(hiX)) return check1(hiX);
  if (bad != check2(loY)) return check2(loY);
  if (bad != check2(hiY)) return check2(hiY);
  return bad;
}
void run_case() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    for (char &j : s) {
      ct[i][j == 'N']++;
    }
  }
  int lo = 0;
  int hi = 1e6;
  while (lo + 1 < hi) {
    int mid = (lo + hi) / 2;
    if (ok(mid)[0] != -1) {
      hi = mid;
    } else {
      lo = mid;
    }
  }
  vector<int> res;
  res = ok(hi);
  cout << hi << "\n";
  string ans = string(res[0], 'B') + string(res[1], 'N');
  cout << ans << "\n";
}
int main() {
  ios::sync_with_stdio(false), cin.tie(0);
  if (fopen("input.in", "r"))
    freopen("input.in", "r", stdin), freopen("output.out", "w", stdout);
  int t;
  t = 1;
  while (t--) {
    run_case();
  }
}
