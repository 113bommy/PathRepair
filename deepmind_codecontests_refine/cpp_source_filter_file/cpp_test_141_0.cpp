#include <bits/stdc++.h>
using namespace std;
void solve(long long x, long long y) {
  vector<int> res;
  while (y) {
    long long sx = x % 10, sy = y % 10;
    if (sx <= sy)
      res.emplace_back(sy - sx);
    else {
      y /= 10;
      sy += 10 * (y % 10);
      if (sx < sy && sy >= 10 && sy <= 19)
        res.emplace_back(sy - sx);
      else {
        cout << -1;
        return;
      }
    }
    x /= 10;
    y /= 10;
  }
  if (x)
    cout << -1;
  else {
    while (res.back() == 0) res.pop_back();
    for (long long i = res.size() - 1; i >= 0; i--) cout << res[i];
  }
  cout << endl;
}
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long a, b;
    cin >> a >> b;
    solve(a, b);
  }
  return 0;
}
