#include <bits/stdc++.h>
using namespace std;
const long long int mod = 1e9 + 7;
const long long int cmod = 998244353;
const long long int N = 1e7 + 5;
const long long int inf = 1e16 + 2;
void solve(long long int Case) {
  long long int n;
  cin >> n;
  long long int arr[n], s = 0;
  map<long long int, long long int> m;
  for (long long int i = 0; i < n; i++) cin >> arr[i], s += arr[i];
  for (long long int i = 0; i < n; i++) {
    s -= arr[i];
    m[s - arr[i]]++;
    s += arr[i];
  }
  vector<long long int> v;
  for (long long int i = 0; i < n; i++) {
    if (m[arr[i]] > 1 or (m[arr[i]] == 1 and (s - 2 * arr[i]) != arr[i]))
      v.push_back(i + 1);
  }
  cout << v.size() << '\n';
  for (auto x : v) cout << x << ' ';
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int testcase = 1;
  long long int Case = 1;
  while (testcase--) {
    solve(Case++);
  }
  return 0;
}
