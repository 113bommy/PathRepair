#include <bits/stdc++.h>
using namespace std;
long long int cnt;
long long int factorial(long long int n) {
  return (n == 1 || n == 0) ? 1 : n * factorial(n - 1);
}
void func(vector<long long int> digits, long long int n, long long int l) {
  long long int ans = factorial(n);
  for (long long int i = 0; i < 10; i++) ans /= factorial(digits[i]);
  if (digits[0] > 0) {
    ans *= n - digits[0];
    ans /= n;
  }
  cnt += ans;
  for (long long int i = l; i < 10; i++) {
    if (digits[i] > 1) {
      digits[i]--;
      func(digits, n - 1, i);
      digits[i]++;
    }
  }
}
int main() {
  long long int n;
  ostringstream str1;
  cin >> n;
  str1 << n;
  string bus_num = str1.str();
  vector<long long int> digits(10);
  for (long long int i = 0; i < bus_num.size(); i++) digits[bus_num[i] - '0']++;
  func(digits, bus_num.size(), 0);
  cout << cnt << endl;
}
