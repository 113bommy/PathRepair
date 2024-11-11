#include <bits/stdc++.h>
using namespace std;
const long long siz = 2e5 + 10;
const long long SIZ = 5e2;
const long long mod = 1e9 + 7;
const long long maxx = 2e9;
const long long MAXX = 1e18;
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long tmp = n;
    long long num = 0, cnt = 0;
    while (num < tmp) {
      num += 4;
      cnt++;
    }
    vector<long long> ans;
    while (cnt--) {
      ans.push_back(8);
      n--;
    }
    while (n--) ans.push_back(9);
    for (long long i = (long long)(ans).size() - 1; i >= 0; i--) cout << ans[i];
    cout << "\n";
  }
  return 0;
}
