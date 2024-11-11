#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9;
const int N = 3e5 + 1;
void solve() {
  float n, vp, vd, t, f, c;
  cin >> vp >> vd >> t >> f >> c;
  if (vp > vd) {
    cout << "0";
    return;
  }
  float curr = 0;
  int cnt = 0;
  curr = t * vp;
  while (curr < c) {
    float ti = curr / (vd - vp);
    curr += ti * vp;
    if (curr == c) break;
    cnt++;
    curr += (f + curr / vd) * vp;
  }
  cout << cnt;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  while (t--) solve();
  return 0;
}
