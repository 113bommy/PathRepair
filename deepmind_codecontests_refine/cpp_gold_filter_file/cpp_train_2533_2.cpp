#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  long long ans = 0;
  int t = n;
  for (int i = 2; i * i <= t; ++i) {
    while (n % i == 0) {
      ans += n;
      n /= i;
    }
  }
  ans += n == 1 ? 1 : n + 1;
  cout << ans;
  return 0;
}
