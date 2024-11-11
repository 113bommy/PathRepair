#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e7 + 10;
long long f[maxn];
long long p, q, k, tot = -1;
long long work(long long p, long long k) {
  long long ans = -p / k;
  if (p % k && p < 0) {
    ans++;
  }
  return ans;
}
int main() {
  int i, j;
  cin >> p >> k;
  for (q = work(p, k); q >= k || q < 0; p = q, q = work(p, k)) {
    f[++tot] = p + k * q;
  }
  f[++tot] = p + k * q;
  if (q) {
    f[++tot] = q;
  }
  cout << tot + 1 << endl;
  for (i = 0; i <= tot; i++) {
    cout << f[i] << " ";
  }
  return 0;
}
