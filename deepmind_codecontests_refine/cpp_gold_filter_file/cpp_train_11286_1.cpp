#include <bits/stdc++.h>
using namespace std;
long long min(long long x, long long y) { return (x < y) ? x : y; }
long long max(long long x, long long y) { return (x > y) ? x : y; }
const int N = 300009;
int x, y, n, m, i, u, w, z, sum, best, j, mx, k, t, dv, pos;
int a[N];
vector<int> ans;
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  dv = a[0] * 2;
  for (int i = 0; i < n; i++) {
    if (a[i] % dv == 0)
      best++;
    else if (dv % a[i] == 0) {
      dv = a[i];
      while (a[pos - 1] % dv == 0 && pos > 0) {
        pos--;
        best++;
      }
      best++;
    } else {
      dv = a[i];
      if (best >= mx) {
        if (best > mx) ans.clear();
        ans.push_back(pos);
        mx = best;
      }
      pos = i;
      best = 1;
    }
  }
  if (best >= mx) {
    if (best > mx) ans.clear();
    ans.push_back(pos);
    mx = best;
  }
  cout << ans.size() << ' ' << mx - 1 << endl;
  for (int i = 0; i < ans.size(); i++) cout << ans[i] + 1 << ' ';
  return 0;
}
