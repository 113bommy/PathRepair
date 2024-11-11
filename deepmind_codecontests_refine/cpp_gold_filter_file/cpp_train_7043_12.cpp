#include <bits/stdc++.h>
using namespace std;
const int W = 111111;
int r[W];
int l, w;
int main() {
  ios::sync_with_stdio(false);
  cout.precision(10);
  cin >> w >> l;
  for (int i = 1; i < w; i++) {
    cin >> r[i];
    r[i] += r[i - 1];
  }
  int ans = 1e9 + 19;
  for (int i = l; i < w; i++) {
    int cur = r[i] - r[i - l];
    ans = min(ans, cur);
  }
  cout << ans << "\n";
  return 0;
}
