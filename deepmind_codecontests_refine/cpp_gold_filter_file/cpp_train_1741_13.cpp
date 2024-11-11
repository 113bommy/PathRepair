#include <bits/stdc++.h>
using namespace std;
mt19937_64 mt(time(0));
int solve(int n) {
  unordered_set<int> table;
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= n - i; j++) {
      for (int k = 0; k <= n - i - j; k++) {
        table.insert(i + j * 5 + k * 10 + (n - i - j - k) * 50);
      }
    }
  }
  return table.size();
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cout.precision(10);
  cout << fixed;
  long long n;
  cin >> n;
  if (n <= 100) {
    cout << solve(n) << endl;
  } else {
    long long ret = solve(100);
    ret = (n - 100) * 49 + ret;
    cout << ret << endl;
  }
  return 0;
}
