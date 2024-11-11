#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
long long cir[100050];
long long p[63];
long long dui[105];
long long twopow[100050];
long long dis[100050];
long long cnt[2];
long long ans;
long long r;
struct node {
  long long to, len;
};
vector<node> edge[100050];
long long n, m, cir_cnt, dui_cnt;
void dfs(long long x, long long l, long long fa) {
  if (dis[x] == -1) {
    dis[x] = l;
    dui_cnt++;
    dui[dui_cnt] = x;
  } else {
    cir_cnt++;
    cir[cir_cnt] = dis[x] ^ l;
    return;
  }
  for (int i = 0; i < edge[x].size(); i++)
    if (edge[x][i].to != fa) dfs(edge[x][i].to, l ^ edge[x][i].len, x);
}
void build() {
  long long i, j;
  memset(p, 0, sizeof(p));
  r = 0;
  for (i = 1; i <= cir_cnt; i++)
    for (j = 62; j >= 0; j--)
      if ((cir[i] & (1LL << j)) != 0) {
        if (p[j] == 0) {
          p[j] = cir[i];
          break;
        } else
          cir[i] ^= p[j];
      }
  for (j = 62; j >= 0; j--)
    if (p[j] != 0) r++;
}
void calc() {
  long long i, j;
  long long num;
  bool flag;
  for (i = 0; i <= 62; i++) {
    cnt[0] = 0;
    cnt[1] = 0;
    flag = false;
    for (j = 0; j <= 62; j++)
      if ((p[j] & (1LL << i)) != 0) {
        flag = true;
        break;
      }
    for (j = 1; j <= dui_cnt; j++)
      if ((dis[dui[j]] & (1LL << i)) != 0)
        cnt[1]++;
      else
        cnt[0]++;
    num = cnt[0] * (cnt[0] - 1) / 2 % mod + cnt[1] * (cnt[1] - 1) / 2 % mod;
    num %= mod;
    if (flag) {
      if (r >= 1) num = num * twopow[r - 1] % mod;
      ans = ans + num * twopow[i] % mod;
      ans = ans % mod;
    }
    num = cnt[0] * cnt[1] % mod;
    if (flag) {
      if (r >= 1) {
        num = num * twopow[r - 1] % mod;
      }
    } else
      num = num * twopow[r] % mod;
    ans = ans + num * twopow[i] % mod;
    ans = ans % mod;
  }
}
int main() {
  long long i, j, k, l;
  node x;
  twopow[0] = 1;
  for (i = 1; i <= 100; i++) twopow[i] = twopow[i - 1] * 2 % mod;
  ios::sync_with_stdio(false);
  while (cin >> n >> m) {
    for (i = 1; i <= n; i++) edge[i].clear();
    for (i = 1; i <= m; i++) {
      cin >> j >> k >> l;
      x.to = k;
      x.len = l;
      edge[j].push_back(x);
      x.to = j;
      edge[k].push_back(x);
    }
    memset(dis, -1, sizeof(dis));
    ans = 0;
    for (i = 1; i <= n; i++)
      if (dis[i] == -1) {
        cir_cnt = 0;
        dui_cnt = 0;
        dfs(i, 0, 0);
        build();
        calc();
      }
    cout << ans << endl;
  }
  return 0;
}
