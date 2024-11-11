#include <bits/stdc++.h>
using namespace std;
int n;
const int maxn = 300000;
int a[maxn];
vector<int> edges[maxn];
long long sum[maxn];
long long maxsum[maxn][3];
long long ans[maxn];
long long output;
const long long ninf = 0xC000000000000000;
void dfs(int p, int cur) {
  for (vector<int>::iterator iter = edges[cur].begin();
       iter != edges[cur].end(); iter++) {
    if (*iter == p) continue;
    dfs(cur, *iter);
    sum[cur] += sum[*iter];
  }
  sum[cur] += a[cur];
}
void dfs2(int p, int cur) {
  maxsum[cur][0] = ninf;
  for (vector<int>::iterator iter = edges[cur].begin();
       iter != edges[cur].end(); iter++) {
    if (*iter == p) continue;
    dfs2(cur, *iter);
    maxsum[cur][0] = max(maxsum[cur][0], maxsum[*iter][0]);
  }
  maxsum[cur][0] = max(maxsum[cur][0], sum[cur]);
}
void dfs3(int p, int cur) {
  maxsum[cur][1] = maxsum[cur][2] = ninf;
  ans[cur] = ninf;
  for (vector<int>::iterator iter = edges[cur].begin();
       iter != edges[cur].end(); iter++) {
    if (*iter == p) continue;
    dfs3(cur, *iter);
    ans[cur] = max(ans[cur], ans[*iter]);
    if (maxsum[cur][1] < maxsum[*iter][0]) {
      maxsum[cur][2] = maxsum[cur][1];
      maxsum[cur][1] = maxsum[*iter][0];
    } else if (maxsum[cur][2] < maxsum[*iter][0]) {
      maxsum[cur][2] = maxsum[*iter][0];
    }
  }
  if (maxsum[cur][2] == ninf)
    ;
  else
    ans[cur] = maxsum[cur][1] + maxsum[cur][2];
  output = output < ans[cur] ? ans[cur] : output;
  return;
}
int main() {
  cin >> n;
  memset(ans, 0xFF, sizeof(ans));
  output = -1;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    edges[u].push_back(v);
    edges[v].push_back(u);
  }
  dfs(0, 1);
  dfs2(0, 1);
  dfs3(0, 1);
  if (output == -1)
    cout << "Impossible";
  else
    cout << output;
  return 0;
}
