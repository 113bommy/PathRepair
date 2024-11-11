#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int MAXN = 1e6 + 100;
inline int mul(int a, int b) { return (1ll * a * b) % mod; }
inline int sub(int a, int b) {
  a -= b;
  if (a < 0) a += mod;
  if (a >= mod) a -= mod;
  return a;
}
inline int add(int a, int b) {
  a += b;
  if (a >= mod) a -= mod;
  if (a < 0) a += mod;
  return a;
}
const int call = 250003;
void solve() {
  long long fact[MAXN], n;
  fact[0] = 1;
  cin >> n;
  int mid;
  cin >> mid;
  for (int i = 1; i < n + 1; i++) fact[i] = (i * fact[i - 1]) % mid;
  long long val = 0;
  for (int i = 1; i < n + 1; i++) {
    val += (n - i + 1) * (fact[i] * fact[n - i + 1] % mid);
    val %= mid;
  }
  cout << val << endl;
}
int main() {
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
