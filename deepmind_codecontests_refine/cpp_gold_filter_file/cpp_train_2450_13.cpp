#include <bits/stdc++.h>
#pragma GCC optimize(3, "Ofast", "inline")
using namespace std;
const int maxn = 300010;
const long long mod = 1000000007;
int n, num;
long long ans;
int pri[maxn], vis[maxn];
long long s[maxn], ine[maxn], jc[maxn], jcc[maxn];
vector<int> v[maxn];
vector<int>::iterator it;
inline long long c(int a, int b) {
  if (a < b) return 0;
  return jc[a] * jcc[b] % mod * jcc[a - b] % mod;
}
inline int rd() {
  int ans = 0, c;
  while (!isdigit(c = getchar()))
    ;
  do ans = ans * 10 + c - '0';
  while (isdigit(c = getchar()));
  return ans;
}
int main() {
  n = rd();
  int i, j, t;
  for (i = 1; i <= n; i++) {
    t = rd();
    for (j = 2; j * j <= t; j++)
      if (t % j == 0) {
        if (!vis[j]) pri[++num] = j, vis[j] = num;
        int tmp = 0;
        while (t % j == 0) t /= j, tmp++;
        v[vis[j]].push_back(tmp);
      }
    if (t != 1) {
      if (!vis[t]) pri[++num] = t, vis[t] = num;
      v[vis[t]].push_back(1);
    }
  }
  ine[0] = ine[1] = jc[0] = jc[1] = jcc[0] = jcc[1] = 1;
  for (i = 2; i <= n; i++)
    ine[i] = mod - (mod / i) * ine[mod % i] % mod, jc[i] = jc[i - 1] * i % mod,
    jcc[i] = jcc[i - 1] * ine[i] % mod;
  s[0] = 1;
  for (i = 1; i < n; i++) s[i] = (s[i - 1] + c(n - 1, i)) % mod;
  for (i = 1; i <= num; i++) {
    int k = n - v[i].size();
    sort(v[i].begin(), v[i].end());
    for (it = v[i].begin(); it != v[i].end(); it++) {
      k++;
      ans = (ans + (*it) * (((k == 1) ? 0 : s[k - 2]) - s[n - 1] + s[k - 1])) %
            mod;
    }
  }
  cout << ans;
  return 0;
}
