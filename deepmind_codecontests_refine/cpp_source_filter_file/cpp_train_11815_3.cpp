#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a;
  cin >> n >> a;
  long long d[200000];
  for (int i = 0; i < n; ++i) cin >> d[i];
  long long ma = accumulate(d, d + n, 0ll), mi = n;
  for (int i = 0; i < n; ++i) {
    int x = max(1ll, a - ma + d[i]);
    int y = min(d[i], a - mi + 1);
    cout << (x - 1) + (d[i] - y) << " ";
  }
  cout << endl;
  return 0;
}
