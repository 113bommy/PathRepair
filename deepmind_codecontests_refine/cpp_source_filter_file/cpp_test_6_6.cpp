#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
const int MOD = (int)1e9 + 7;
long long n, a[MAXN], sum_gcd[MAXN], mobius[MAXN], euler[MAXN], nxt[MAXN],
    cnt[MAXN];
long long sum;
vector<long long> divisor[MAXN];
long long add(long long &a, long long b) { a += b; }
long long sub(long long &a, long long b) { a -= b; }
void update(int x, int val) {
  for (int d : divisor[x]) {
    sub(sum, euler[d] * cnt[d] * cnt[d]);
    cnt[d] += val;
    add(sum, euler[d] * cnt[d] * cnt[d]);
  }
}
int main() {
  for (int i = 1; i < MAXN; ++i)
    for (int j = i; j < MAXN; j += i) divisor[j].push_back(i);
  for (int i = 2; i < MAXN; ++i) {
    for (int j = i; j < MAXN; j += i) {
      if (nxt[j] == 0) nxt[j] = i;
    }
  }
  mobius[1] = 1;
  euler[1] = 1;
  for (int i = 2; i < MAXN; ++i) {
    int p = nxt[i];
    if (p == nxt[i / p]) {
      mobius[i] = 0;
      euler[i] = euler[i / p] * p;
    } else {
      mobius[i] = -mobius[i / p];
      euler[i] = euler[i / p] * (p - 1);
    }
  }
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  for (int k = 1; k <= n; ++k) {
    for (int i = k; i <= n; i += k) update(a[i], 1);
    sum_gcd[k] = sum;
    for (int i = k; i <= n; i += k) update(a[i], -1);
  }
  long long ans = 0;
  for (int k = 1; k <= n; ++k) {
    add(ans, euler[k] * sum_gcd[k]);
  }
  cout << ans;
  return 0;
}
