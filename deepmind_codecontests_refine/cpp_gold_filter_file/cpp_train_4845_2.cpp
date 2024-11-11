#include <bits/stdc++.h>
using namespace std;
int64_t natural_pow(int n) {
  if (n == 1) return 10;
  int64_t sq = natural_pow(n / 2);
  return sq * sq * (n % 2 == 1 ? 10 : 1);
}
int64_t solve(string ending) {
  ending.erase(ending.begin(), ending.begin() + 4);
  int64_t n = ending.size(), num = stoi(ending);
  int64_t start = 1989;
  for (int i = 0, j = 10; i < n - 1; ++i, start += j, j *= 10)
    ;
  int64_t current_pow = natural_pow(n), end = start % current_pow,
          res = start - end + num;
  if (end > num) res += current_pow;
  return res;
}
int main() {
  int n;
  string str;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> str;
    cout << solve(str) << endl;
  }
  return 0;
}
