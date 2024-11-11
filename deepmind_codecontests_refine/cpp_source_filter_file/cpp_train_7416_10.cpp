#include <bits/stdc++.h>
using namespace std;
vector<long long int> a;
unordered_map<long long int, long long int> ans;
void help() {
  long long int x = 2;
  a.push_back(2);
  for (long long int i = 2; i <= 31622; i++) {
    x = (3 * i * i + i) / 2;
    if (x <= 1e9) {
      a.push_back(x);
    } else {
      break;
    }
  }
}
long long int n;
long long int find(long long int num) {
  if (ans.find(num) != ans.end()) return ans[num];
  if (num <= 1) {
    ans[num] = 0;
    return 0;
  }
  long long int x = lower_bound(a.begin(), a.end(), num) - a.begin();
  if (a[x] > num) x--;
  ans[num] = 1 + find(num - a[x]);
  return ans[num];
}
void solve() {
  cin >> n;
  cout << find(n);
}
int32_t main() {
  {
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
  };
  help();
  long long int t = 1;
  cin >> t;
  while (t--) {
    solve();
    cout << "\n";
  }
  return 0;
}
