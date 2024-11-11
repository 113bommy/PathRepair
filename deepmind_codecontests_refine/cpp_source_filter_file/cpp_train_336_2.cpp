#include <bits/stdc++.h>
using namespace std;
int n;
const long long Mod = 1e9 + 7;
long long calc(int n) {
  long long ans = 1;
  for (int i = 1; i <= n; i++) {
    ans = (ans * i) % Mod;
  }
  return ans;
}
int main() {
  cin >> n;
  long long f = calc(n);
  long long k = 1;
  for (int i = 1; i <= n - 2; i++) {
    k = (k * 2) % Mod;
  }
  long long ans = f - 2 * k;
  if (ans < 0) {
    ans += Mod;
  }
  cout << ans << endl;
  return 0;
}
