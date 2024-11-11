#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007ll;
long long n;
long long arr[314159];
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n;
  set<long long> m;
  for (long long i = 1; i <= n; i++) {
    cin >> arr[i];
    m.insert(arr[i]);
  }
  vector<long long> ans;
  for (long long i = 1; i <= n; i++) {
    for (long long j = 2; j < 4 * MOD; j *= 2) {
      long long a = j, b = 2 * j;
      vector<long long> temp;
      temp.push_back(arr[i]);
      if (m.count(arr[i] + a)) temp.push_back(arr[i] + a);
      if (m.count(arr[i] + b)) temp.push_back(arr[i] + b);
      if (ans.size() < temp.size()) {
        ans.clear();
        for (auto x : temp) ans.push_back(x);
      }
      temp.clear();
      temp.push_back(arr[i]);
      if (m.count(arr[i] - a)) temp.push_back(arr[i] - a);
      if (m.count(arr[i] - b)) temp.push_back(arr[i] - b);
      if (ans.size() < temp.size()) {
        ans.clear();
        for (auto x : temp) ans.push_back(x);
      }
    }
  }
  cout << ans.size() << "\n";
  for (auto i : ans) cout << i << " ";
  return 0;
}
