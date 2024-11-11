#include <bits/stdc++.h>
using namespace std;
long long n, k, a[1123], d, res;
vector<long long> ans;
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n >> k;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    if (!d && i) {
      ans.push_back(a[i] - a[i - 1]);
    }
    if (a[i] & 1) {
      ++d;
    } else {
      --d;
    }
  }
  sort(ans.begin(), ans.end());
  for (int i = 0; i < ans.size() && k; ++i) {
    if (ans[i] <= k) {
      k -= ans[i];
      ++res;
    }
  }
  cout << res;
}
