#include <bits/stdc++.h>
using namespace std;
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cerr << name << " : " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cerr.write(names, comma - names) << " : " << arg1 << " | ";
  __f(comma + 1, args...);
}
const int mod = 1e9 + 7;
long long powmod(long long a, long long b) {
  long long res = 1;
  if (a >= mod) a %= mod;
  for (; b; b >>= 1) {
    if (b & 1) res = res * a;
    if (res >= mod) res %= mod;
    a = a * a;
    if (a >= mod) a %= mod;
  }
  return res;
}
long long gcd(long long a, long long b) { return a == 0 ? b : gcd(b % a, a); }
const int maxn = 1000010;
const int inf = maxn;
bitset<maxn> dp;
int p[maxn], c[500], lt = 100;
bool v[maxn];
int main() {
  int n, k;
  cin >> n >> k;
  for (int i = 1; i <= n; i++) scanf("%d", p + i);
  int val = 0;
  dp.set(0);
  int odd = 0;
  for (int i = 1; i <= n; i++) {
    if (v[i]) continue;
    int j = i, l = 0;
    while (v[j] == 0) {
      l++;
      v[j] = 1;
      j = p[j];
    }
    val += l / 2;
    if (l > lt)
      dp = dp | (dp << l);
    else
      c[l]++;
    if (l & 1) odd++;
  }
  if (val > k) val = k;
  int maxi = 2 * val;
  if (k - val) maxi += min(odd, k - val);
  memset(v, 0, sizeof v);
  v[0] = 1;
  for (int i = 1; i <= lt; i++) {
    if (c[i] == 0) continue;
    for (int j = 1; j <= k; j++)
      if (v[j])
        p[j] = 0;
      else if (j >= i)
        p[j] = p[j - i] + 1;
    for (int j = 1; j <= k; j++)
      if ((!v[j]) && (p[j] <= c[i])) v[j] = 1;
  }
  int flag = 1;
  for (int i = 0; i <= k; i++)
    if (v[i] && dp[k - i]) flag = 0;
  cout << k + flag << " " << maxi << '\n';
  cin.get();
  cin.get();
  return 0;
}
