#include <bits/stdc++.h>
using namespace std;
int n, k, p[1000005];
int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  for (int i = 0; i < n; i++) {
    int t;
    cin >> t;
    k += (t == 1);
  }
  p[0] = 1;
  p[1] = 1;
  for (int i = 2; i <= k; i++) {
    p[i] = 1ll * (p[i - 1] + 1ll * (i - 1) * p[i - 2]) % 1000000007;
  }
  for (int i = k + 1; i <= n; i++) {
    p[i] = p[i - 1] * i % 1000000007;
  }
  cout << p[n] << endl;
  return 0;
}
