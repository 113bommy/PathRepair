#include <bits/stdc++.h>
using namespace std;
const long long int mxn = 1e6;
bool prime(long long int num) {
  if (num <= 1) return false;
  for (long long int i = 2; i * i <= num; i++) {
    if (num % i == 0) {
      return false;
    }
  }
  return true;
}
void tc() {
  long long int n;
  cin >> n;
  long long int num = n;
  vector<long long int> ans;
  for (long long int i = n; i >= 2; --i) {
    if (prime(i)) {
      ans.push_back(i);
      n -= i;
      break;
    }
  }
  if (prime(n)) {
    ans.push_back(n);
    n -= n;
  }
  if (n > 0) {
    for (long long int i = 2; i <= n; i++) {
      if (prime(i) and prime(n - i)) {
        ans.push_back(i);
        ans.push_back(n - i);
        break;
      }
    }
  }
  cout << ans.size() << "\n";
  for (long long int el : ans) cout << el << " ";
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int t;
  t = 1;
  while (t--) tc();
}
