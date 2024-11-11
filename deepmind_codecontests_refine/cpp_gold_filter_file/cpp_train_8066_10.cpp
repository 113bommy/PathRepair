#include <bits/stdc++.h>
using namespace std;
pair<int, int> parr[105], narr[105];
int main(int argc, char const *argv[]) {
  int n;
  cin >> n;
  int d;
  int pi = 0;
  int ni = 0;
  for (int i = 0; i < n; ++i) {
    cin >> d;
    if (d < 0) {
      narr[ni].first = d;
      cin >> narr[ni].second;
      ni++;
    } else {
      parr[pi].first = d;
      cin >> parr[pi].second;
      pi++;
    }
  }
  sort(narr, narr + ni);
  sort(parr, parr + pi);
  int ans = 0;
  if (ni == pi) {
    for (int i = 0; i < ni; ++i) {
      ans += parr[i].second;
      ans += narr[i].second;
    }
  } else if (pi > ni) {
    for (int i = 0; i < ni; ++i) {
      ans += narr[i].second;
      ans += parr[i].second;
    }
    ans += parr[ni].second;
  } else {
    for (int i = ni - 1; i >= ni - pi; i--) {
      ans += narr[i].second;
      ans += parr[ni - i - 1].second;
    }
    ans += narr[ni - pi - 1].second;
  }
  cout << ans;
  return 0;
}
