#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<long long> ans;
  for (long long i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      long long a = n / i;
      ans.push_back(a + a * (a - 1) / 2 * i);
      if (a != i) ans.push_back(i + i * (i - 1) / 2 * n / i);
    }
  }
  sort(ans.begin(), ans.end());
  for (int x : ans) cout << x << ' ';
  return 0;
}
