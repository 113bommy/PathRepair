#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int len = 2 * 1e6 + 1;
  int mod = 1e9 + 7;
  vector<long long> a(len);
  vector<bool> b(len);
  a[3] = 4;
  b[3] = true;
  for (int i = 4; i < len; i++) {
    a[i] = 2 * a[i - 2] + a[i - 1];
    if (!b[i - 1] && !b[i - 2]) {
      a[i] += 4;
      b[i] = true;
    }
    a[i] = a[i] % mod;
  }
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int t;
    cin >> t;
    cout << a[t];
  }
  return 0;
}
