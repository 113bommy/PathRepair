#include <bits/stdc++.h>
using namespace std;
long long bin_pow(long long a, long long b) {
  if (!b) return 1;
  long long ans = bin_pow(a, b / 2);
  ans = ans * ans;
  if (b % 2) ans = ans * a;
  return ans;
}
int poh[10];
int main() {
  int x;
  cin >> x;
  if (x == 1) {
    cout << 1;
    return 0;
  }
  if (x == 2) {
    cout << 3;
    return 0;
  }
  if (x == 3) {
    cout << 5;
    return 0;
  }
  if (x == 4) {
    cout << 3;
    return 0;
  }
  if (x == 5) {
    cout << 3;
    return 0;
  }
  int ans, i;
  for (ans = 1; ans < 100; ans += 2) {
    if ((((ans) * (long long)(ans)) + 1) / 2 >= x) {
      cout << ans;
      return 0;
    }
  }
  return 0;
}
