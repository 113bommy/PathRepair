#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  int mod = 10007;
  while (cin >> n) {
    vector<int> values(n);
    int ans = 0;
    for (auto &it : values) cin >> it;
    sort(values.begin(), values.end());
    for (int i = 0; i < n; i++)
      ans = (ans + ((long long)values[i] * values[n - i - 1]) % mod) % mod;
    cout << ans << endl;
  }
  return 0;
}
