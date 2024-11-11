#include <bits/stdc++.h>
using namespace std;
using INT = long long;
using pii = pair<int, int>;
int vst[100100], mb[100100];
const int mod = 1000000007;
int power(int a, int n) {
  int ans = 1;
  for (; n; a = (INT)a * a % mod, n >>= 1)
    if (n & 1) ans = (INT)ans * a % mod;
  return ans;
}
void pre() {
  mb[1] = 1;
  for (int i = 2; i < 100100; i++) {
    if (vst[i]) continue;
    vst[i] = 1;
    for (int j = i; j < 100100; j += i) {
      vst[j] = 1;
      if (j / i % i == 0)
        mb[j] = 0;
      else
        mb[j] = mb[j / i] * (-1);
    }
  }
}
int main() {
  ios_base ::sync_with_stdio(0);
  cin.tie(0);
  pre();
  int m;
  cin >> m;
  int ans = 0;
  for (int i = 1; i <= m; i++) {
    int val = m / i;
    val = (INT)val * power(m, mod - 2) % mod;
    val = power(val - 1, mod - 2) % mod + 1;
    ans = (ans + val * mb[i] % mod + mod) % mod;
  }
  cout << ans << endl;
  return 0;
}
