#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long n, val, min = 1000000000007, ans;
  vector<long long> v;
  cin >> n;
  for (long long i = 0; i < n; i++) {
    cin >> val;
    v.push_back(val);
  }
  for (long long i = 0; i < n; i++) {
    if (((v[i] - i) % n) != 0)
      val = 1;
    else
      val = 0;
    val += (v[i] - i) / n;
    val = (i + (val * n));
    if (v[i] <= i) val = v[i];
    if (val < min) {
      min = val;
      ans = i;
    }
  }
  cout << ans + 1;
}
