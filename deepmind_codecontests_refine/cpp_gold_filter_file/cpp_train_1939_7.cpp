#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int TESTS = 1;
  while (TESTS--) {
    long long n;
    cin >> n;
    long long ans = 1e18;
    vector<long long int> a(2 * n);
    for (long long int i = 0; i < 2 * n; i++) cin >> a[i];
    sort((a).begin(), (a).end());
    for (long long int i = 0; i < 2 * n; i++)
      for (long long int j = i + 1; j < 2 * n; j++) {
        vector<long long int> t;
        for (long long int k = 0; k < 2 * n; k++)
          if (i != k && j != k) t.push_back(a[k]);
        long long cur = 0;
        for (long long int i = 0; i < n - 1; i++)
          cur += t[2 * i + 1] - t[2 * i];
        ans = min(ans, cur);
      }
    cout << ans;
  }
  return 0;
}
