#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
const double EPS = 1e-7;
const double PI = acos(-1);
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  long long k;
  cin >> n >> k;
  vector<long long> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a.begin(), a.end());
  vector<long long> ans;
  for (auto& x : a) {
    if (x % k != 0 or !binary_search(ans.begin(), ans.end(), x / k))
      ans.push_back(x);
  }
  cout << ans.size() << "\n";
  return 0;
}
