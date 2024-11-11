#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
int N = 2e6;
void subMain() {
  long long n, x, y, cnt = 0;
  cin >> n >> x >> y;
  vector<int> arr(n);
  for (long long i = 0; i < n; i++) {
    cin >> arr[i];
  }
  if (x > y) {
    cout << n << "\n";
  } else {
    for (long long i = 0; i < n; i++) {
      if (arr[i] <= x) {
        cnt++;
      }
    }
    if (cnt % 2 == 0) {
      cout << cnt / 2 << "\n";
    } else {
      cout << (cnt / 2) + 1 << "\n";
    }
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  subMain();
  cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC
       << "ms\n";
  return 0;
}
