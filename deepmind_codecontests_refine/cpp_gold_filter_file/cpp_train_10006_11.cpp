#include <bits/stdc++.h>
using namespace std;
signed main(signed argc, const char* argv[]) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  int cnt = 0;
  for (int i = 0; cnt < n; ++i) {
    cout << 3 << " " << i << endl;
    ++cnt;
    if (cnt == n) break;
    if (i % 2) {
      ++cnt;
      cout << 0 << " " << i << endl;
    }
  }
}
