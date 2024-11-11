#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
long long fact[100100], a[5][100100], ans;
long long power(long long num, long long p) {
  if (!p) return 1ll;
  long long tmp = power(num, p / 2);
  tmp = (tmp * tmp) % mod;
  if (p % 2) tmp = (tmp * num) % mod;
  return tmp;
}
long long calc(long long a, long long b) {
  long long ret = fact[b];
  ret = (ret * power(fact[a], mod - 2)) % mod;
  ret = (ret * power(fact[b - a], mod - 2)) % mod;
  return ret;
}
int main() {
  ios_base::sync_with_stdio(0);
  fact[0] = 1;
  for (long long i = 1; i < 100100; i++) fact[i] = (fact[i - 1] * i) % mod;
  long long n;
  cin >> n;
  for (long long i = 1; i <= n; i++) cin >> a[0][i];
  if (n == 1) {
    cout << a[0][1] << endl;
    return 0;
  }
  long long pre = 0;
  long long tmp = n;
  bool mark = true;
  while (tmp % 4 != 2) {
    tmp--;
    for (long long i = 1; i < n - pre; i++) {
      if (mark)
        a[1 + pre][i] = (a[pre][i] + a[pre][i + 1]) % mod;
      else
        a[1 + pre][i] = (a[pre][i] - a[pre][i + 1]) % mod;
      mark = !mark;
    }
    pre++;
  }
  n -= pre;
  for (long long i = 1; i <= n; i++) {
    long long tmp = (a[pre][i] * calc((i - 1) / 2, (n / 4) * 2)) % mod;
    if (!mark && i % 2 == 0) tmp = -tmp;
    ans = (ans + tmp) % mod;
  }
  cout << (ans + mod) % mod << endl;
  return 0;
}
