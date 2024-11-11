#include <bits/stdc++.h>
using namespace std;
int n;
int t[20001];
vector<int> factors;
int ans = 0;
int main() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> t[i];
    ans += t[i];
  }
  for (int i = 1; i < sqrt(n); ++i) {
    if (n % i == 0) {
      factors.push_back(i);
    }
  }
  for (int j = 0; j < factors.size(); ++j) {
    for (int i = 0; i <= factors[j]; ++i) {
      bool first = true;
      int k = i;
      int sum = 0;
      while (k != i || first) {
        first = false;
        sum += t[k];
        k = (k + factors[j]) % n;
      }
      ans = max(sum, ans);
    }
  }
  cout << ans << endl;
  return 0;
}
