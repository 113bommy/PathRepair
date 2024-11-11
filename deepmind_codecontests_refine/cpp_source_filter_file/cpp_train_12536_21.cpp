#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  int ans = 0, cnt = 0;
  int a;
  for (int i = 0; i < n; ++i) {
    cin >> a;
    if (a == 1)
      ++cnt;
    else
      ans += cnt;
  }
  cout << ans << endl;
  return 0;
}
