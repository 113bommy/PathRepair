#include <bits/stdc++.h>
using namespace std;
vector<int> a, k1, k0;
int n, ans;
int main() {
  cin >> n;
  a.resize(n + 2);
  k1.resize(n + 2);
  k0.resize(n + 2);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (a[i] == 0) {
      k0[i] = k0[i - 1] + 1;
      k1[i] = k1[i - 1];
    } else {
      k0[i] = k0[i - 1];
      k1[i] = k1[i - 1] + 1;
    }
  }
  ans = 0;
  for (int i = 1; i <= n; i++)
    for (int j = i; j <= n; j++) {
      ans = max(ans, k1[i - 1] + k1[n] - k1[j] + k0[j] - k0[i - 1]);
    }
  cout << ans;
  return 0;
}
