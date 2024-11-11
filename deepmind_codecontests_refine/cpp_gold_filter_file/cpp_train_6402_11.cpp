#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
const int size = 2000111;
long long ans[size];
long long jc[size], ni[size];
long long mul(long long a, int k) {
  long long ans = 1;
  while (k) {
    if (k & 1) ans = ans * a % mod;
    a = a * a % mod;
    k >>= 1;
  }
  return ans;
}
long long get(int x, int y) { return jc[x] * ni[y] % mod * ni[x - y] % mod; }
int main() {
  jc[0] = ni[0] = 1;
  for (int i = 1; i < size; i++) {
    jc[i] = jc[i - 1] * i % mod;
    ni[i] = mul(jc[i], mod - 2);
  }
  ans[1] = 5;
  for (int i = 2; i < size; i++)
    ans[i] = (ans[i - 1] + get(2 * i, i - 1) + get(2 * i + 1, i + 1)) % mod;
  int n;
  cin >> n;
  cout << ans[n] << endl;
}
