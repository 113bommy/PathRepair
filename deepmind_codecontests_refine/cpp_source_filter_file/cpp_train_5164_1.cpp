#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
double PI = 4 * atan(1);
int n;
long long fac[200001], invfac[200001];
long long inv(long long a) {
  long long po = MOD - 2, ans = 1;
  while (po) {
    if (po & 1) ans = (ans * a) % MOD;
    a = (a * a) % MOD;
    po /= 2;
  }
  return ans;
}
void gen() {
  fac[0] = invfac[0] = 1;
  for (int i = 1; i < 200001; i++) {
    fac[i] = i * fac[i - 1];
    invfac[i] = inv(fac[i]);
  }
}
long long combo(int a, int b) {
  long long ret = (fac[a + b] * invfac[a]) % MOD;
  ret = (ret * invfac[b]) % MOD;
  return ret;
}
long long get(vector<long long> x) {
  int num = x.size() - 1;
  long long ans = 0;
  for (int i = 0; i < x.size(); i++) {
    ans = (ans + combo(num - i, i) * x[i]) % MOD;
  }
  return ans;
}
int main() {
  gen();
  vector<long long> a;
  cin >> n;
  a.resize(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  if (n % 4 == 1) {
    vector<long long> x;
    for (int i = 0; i < n; i++)
      if (i % 2 == 0) x.push_back(a[i]);
    cout << get(x);
  } else if (n % 4 == 2) {
    vector<long long> x1, x2;
    for (int i = 0; i < n; i++)
      if (i % 2 == 0)
        x1.push_back(a[i]);
      else
        x2.push_back(a[i]);
    long long ans = (get(x1) + get(x2)) % MOD;
    cout << ans;
    return 0;
  } else if (n % 4 == 3) {
    vector<long long> x1, x2, x3;
    for (int i = 0; i < n - 1; i++)
      if (i % 2 == 0)
        x1.push_back(a[i]);
      else
        x2.push_back(a[i]);
    for (int i = 1; i < n; i++)
      if (i % 2 == 0) x3.push_back(a[i]);
    long long ans = get(x1) + 2 * get(x2) - get(x3);
    ans = (ans + MOD) % MOD;
    cout << ans;
    return 0;
  } else {
    vector<long long> x1, x2;
    for (int i = 0; i < n; i++)
      if (i % 2 == 0)
        x1.push_back(a[i]);
      else
        x2.push_back(a[i]);
    long long ans = get(x1) - get(x2);
    ans = (ans + MOD) % MOD;
    cout << ans;
  }
}
