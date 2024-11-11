#include <bits/stdc++.h>
using namespace std;
long long n, ans = 1, temp = 1;
;
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    ans *= 27;
    if (ans >= 1000000007) {
      ans %= 1000000007;
    }
    temp *= 7;
    if (temp >= 1000000007) {
      temp %= 1000000007;
    }
  }
  cout << (ans - temp + 1000000007) % 1000000007;
}
