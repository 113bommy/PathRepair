#include <bits/stdc++.h>
using namespace std;
signed main() {
  long long n;
  cin >> n;
  long long x;
  cin >> x;
  vector<long long> digits;
  while (x) {
    long long r = x % 10;
    if (x > 1) digits.push_back(r);
    x /= 10;
  }
  vector<long long> ans;
  for (long long i = 0; i < digits.size(); i++) {
    if (digits[i] == 2 || digits[i] == 3 || digits[i] == 5 || digits[i] == 7) {
      ans.push_back(digits[i]);
    } else if (digits[i] == 4) {
      ans.push_back(3);
      ans.push_back(2);
      ans.push_back(2);
    } else if (digits[i] == 6) {
      ans.push_back(5);
      ans.push_back(3);
    } else if (digits[i] == 8) {
      ans.push_back(7);
      ans.push_back(2);
      ans.push_back(2);
      ans.push_back(2);
    } else {
      ans.push_back(7);
      ans.push_back(3);
      ans.push_back(3);
      ans.push_back(2);
    }
  }
  sort(ans.begin(), ans.end(), greater<long long>());
  for (long long i = 0; i < ans.size(); i++) cout << ans[i];
  return 0;
}
