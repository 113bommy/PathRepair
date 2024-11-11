#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const int maxn = 1e6 + 5;
char s[maxn << 1];
int vis[30], last[30];
long long f[maxn << 1], pre[maxn << 1];
vector<int> v, v2;
int main() {
  int n, k, now;
  scanf("%d%d", &n, &k);
  scanf("%s", s + 1);
  int m = strlen(s + 1);
  for (int i = 1; i <= m; i++) vis[s[i] - 'a']++;
  for (int i = 0; i < k; i++) {
    if (!vis[i])
      v.push_back(i + 'a');
    else
      vis[i] = 0;
  }
  for (int i = m; i; i--) {
    if (!vis[s[i] - 'a']) {
      v2.push_back(s[i]);
      vis[s[i] - 'a'] = 1;
    }
  }
  while (v2.size()) {
    v.push_back(v2.back());
    v2.pop_back();
  }
  for (int i = 1; i <= n; i++) {
    s[m + i] = v[now++];
    if (now == v.size()) now = 0;
  }
  long long ans = 0;
  for (int i = 1; i <= m + n; i++) {
    if (last[s[i] - 'a'] == 0)
      f[i] = (1 + pre[i - 1]) % mod;
    else
      f[i] = (pre[i - 1] - pre[last[s[i] - 'a'] - 1] + mod) % mod;
    pre[i] = (pre[i - 1] + f[i]) % mod;
    last[s[i] - 'a'] = i;
    ans = (ans + f[i]) % mod;
  }
  printf("%lld", (ans + 1) % mod);
  return 0;
}
