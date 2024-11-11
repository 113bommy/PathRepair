#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 5, T = 100;
int n, a[MAXN], k, cnt = 0, t[MAXN];
bool visit[MAXN];
bitset<MAXN> btset;
void dfs(int v) {
  visit[v] = true;
  cnt++;
  if (!visit[a[v]]) dfs(a[v]);
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    a[i]--;
  }
  int kk = 0, o = 0;
  for (int i = 0; i < n; i++)
    if (!visit[i]) {
      cnt = 0;
      dfs(i);
      kk += (cnt / 2);
      o += (cnt % 2);
      t[cnt]++;
    }
  btset[0] = 1;
  for (int i = T; i <= n; i++)
    for (int j = 0; j < t[i]; j++) btset |= (btset << i);
  for (int i = 1; i < T; i++) {
    if (t[i] == 0) continue;
    for (int j = n; j >= 0; j--) {
      if (btset[j] == 0) continue;
      int ii = j, c = t[i];
      while (ii + i <= n && cnt > 0 && !btset[ii + i]) {
        ii += i;
        btset[ii] = 1;
        cnt--;
      }
    }
  }
  int mn = ((btset[k]) ? k : k + 1),
      mx = ((kk >= k) ? 2 * k : (2 * kk) + min(k - kk, o));
  cout << mn << " " << mx << endl;
  return 0;
}
