#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int n, d, a[100005];
int main() {
  cin >> n >> d;
  for (int i = 0; i < n; ++i) cin >> a[i];
  long long res = 0;
  for (int i = 0; i < n; ++i) {
    int j = upper_bound(a, a + n, a[i] + d) - a - 1;
    int diff = j - i - 1;
    res += diff * (diff + 1) / 2;
  }
  cout << res;
  return 0;
}
