#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e7;
const int mod = 1e9 + 7;
bitset<maxn + 5> sieve, bad;
bool freq[maxn + 5];
int cnt[maxn + 5];
long long pot[500005];
int add(int a, int b) {
  int res = a + b;
  if (res < 0) res += mod;
  if (res > mod) res -= mod;
  return res;
}
int mul(int a, int b) { return (1LL * a * b) % mod; }
int main() {
  pot[0] = 1;
  for (int i = 1; i <= 5e5; i++) pot[i] = add(pot[i - 1], pot[i - 1]) % mod;
  sieve[0] = sieve[1] = 1;
  for (int i = 2; i <= maxn; i++)
    if (!sieve[i]) {
      freq[i] = 1;
      for (int j = i + i; j <= maxn; j += i) {
        sieve[j] = 1;
        freq[j] = !freq[j];
        if (j % (1LL * i * i) == 0) bad[j] = 1;
      }
    }
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    int x;
    scanf("%d", &x);
    int root = sqrt(x);
    for (int j = 1; j <= root; j++)
      if (x % j == 0) {
        cnt[j]++;
        cnt[x / j]++;
      }
    if (root * root == x) cnt[root]--;
  }
  long long res = 0;
  for (int i = 2; i <= maxn; i++)
    if (!bad[i]) {
      int signal = (freq[i] == 1 ? 1 : -1);
      long long a = add(pot[cnt[i]], -1);
      long long b = mul(a, add(n, -cnt[i]));
      if (signal == -1) b = -b;
      res = add(res, b);
    }
  cout << res << endl;
  return 0;
}
