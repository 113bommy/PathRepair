#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long k, b, n, t;
  cin >> k >> b >> n >> t;
  if (t == 1) {
    cout << n << endl;
    exit(0);
  }
  long long cnt = 0;
  long long temp = 1;
  while (temp < t) {
    temp = temp * k + b;
    cnt++;
  }
  cout << max(0LL, n - cnt + 1) << endl;
}
