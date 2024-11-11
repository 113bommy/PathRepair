#include <bits/stdc++.h>
using namespace std;
const int N = 1000000 + 5;
const int MOD = 1e9 + 7;
int p, k;
int val[N], sum[N];
bool vis[N];
vector<int> tmp;
int solve() {
  if (k == 1) {
    int ans = 1;
    for (int i = 0; i < p; i++) ans = 1ll * ans * p % MOD;
    return ans;
  }
  for (int i = 1; i <= p; i++) val[i] = 0;
  for (int i = 0; i < p; i++)
    if (!vis[i]) {
      int cr = i;
      int cnt = 0;
      while (!vis[cr]) {
        cnt++;
        vis[cr] = 1;
        cr = cr * 1ll * k % p;
      }
      val[cnt] += cnt;
      if (i != 0) tmp.push_back(cnt);
    }
  for (int i = 1; i <= p; i++) {
    for (int j = i; j <= p; j += i) {
      sum[j] = (sum[j] + val[i]) % MOD;
    }
  }
  int ans = 1;
  for (int i = 0; i < tmp.size(); i++) {
    ans = 1ll * ans * (sum[tmp[i]]) % MOD;
  }
  return ans;
}
int main() {
  scanf("%d%d", &p, &k);
  printf("%d\n", solve());
  return 0;
}
