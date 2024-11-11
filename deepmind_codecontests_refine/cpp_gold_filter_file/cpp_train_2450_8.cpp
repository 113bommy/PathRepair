#include <bits/stdc++.h>
using namespace std;
const long long Mo = 1000000007LL;
vector<int> val[301000];
int n, A[301000], sz[301000];
long long wp[301000], fac[301000], ni[301000];
long long ans;
long long C(int a, int b) { return (fac[a] * ni[b] % Mo * ni[a - b] % Mo); }
long long fpm(long long a, long long b) {
  if (!a) return 0LL;
  long long ans = 1LL;
  for (; b; b >>= 1) {
    if (b & 1) ans *= a, ans %= Mo;
    a *= a;
    a %= Mo;
  }
  return ans;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &A[i]);
  fac[0] = 1;
  for (int i = 1; i <= n + 1; i++) fac[i] = (fac[i - 1] * (long long)i) % Mo;
  for (int i = 0; i <= n + 1; i++) ni[i] = fpm(fac[i], Mo - 2LL);
  for (int i = 1; i <= n; i++) {
    for (int j = 2; j * j <= A[i]; j++) {
      if (A[i] % j) continue;
      int k = 0;
      for (; !(A[i] % j); A[i] /= j) k++;
      sz[j]++;
      val[j].push_back(k);
    }
    if (A[i] != 1) {
      sz[A[i]]++;
      val[A[i]].push_back(1);
    }
  }
  for (int i = 1; i < n; i++) wp[i] = C(n - 1, i);
  for (int i = n - 1; i >= 0; i--) (wp[i] += wp[i + 1]) %= Mo;
  for (int i = 2; i <= 300000; i++) {
    sort(val[i].begin(), val[i].end());
    for (int j = 0; j < sz[i]; j++)
      (ans -= (long long)val[i][j] * wp[n - sz[i] + j + 1]) %= Mo;
    for (int j = 0; j < sz[i]; j++)
      (ans += (long long)val[i][j] * wp[sz[i] - j]) %= Mo;
  }
  cout << (ans + Mo) % Mo << endl;
  return 0;
}
