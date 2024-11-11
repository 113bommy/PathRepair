#include <bits/stdc++.h>
using namespace std;
const long long MAX = 10000005;
const int MOD = 1e9 + 7;
int main() {
  long long n;
  cin >> n;
  for (long long i = 0; i < MAX; ++i) {
    long long ans = i * (i + 1);
    ans /= 2;
    if (ans == n) {
      cout << i;
      break;
    } else if (ans > n) {
      ans = i * (i - 1);
      ans /= 2;
      ans = n - ans;
      cout << ans;
      break;
    }
  }
}
