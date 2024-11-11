#include <bits/stdc++.h>
using namespace std;
int main() {
  long int n;
  cin >> n;
  long int ans = 0;
  for (int i = 1; i <= 64; i++) {
    long long int num = ((1 << i) - 1) * (1 << (i - 1));
    if (num > n) break;
    if (n % num == 0) ans++;
  }
  cout << ans;
  return 0;
}
