#include <bits/stdc++.h>
using namespace std;
const double P = 3.141592653589793;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    string s;
    cin >> n >> s;
    int pref[n + 1];
    pref[0] = 0;
    for (int i = 1; i <= n; i++) {
      pref[i] = pref[i - 1] + s[i - 1] - '0' - 1;
    }
    vector<int> res;
    long long ans = 0;
    for (int i = 0; i < n + 1; i++) {
      res.push_back(pref[i]);
    }
    sort(res.begin(), res.end());
    int x = 0;
    int cur = res[0];
    for (int i = 0; i < n + 1; i++) {
      if (cur == res[i])
        x++;
      else {
        cur = res[i];
        ans += (((x) - (1)) * (x)) / 2;
        x = 1;
      }
    }
    if (x) {
      ans += (((x) - (1)) * (x)) / 2;
    }
    cout << ans << endl;
  }
  return 0;
}
