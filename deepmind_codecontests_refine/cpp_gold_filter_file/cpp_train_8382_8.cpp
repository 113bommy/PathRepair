#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 5;
int a[maxn];
int pos[maxn];
int nxt[maxn];
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    pos[a[i]] = i;
    nxt[a[i]] = n + 1;
  }
  int u, v;
  int qian, hou;
  for (int i = 1; i <= m; i++) {
    cin >> u >> v;
    qian = pos[u];
    hou = pos[v];
    if (hou < qian) swap(hou, qian);
    nxt[qian] = min(nxt[qian], hou);
  }
  long long ans = 0;
  int cur = n + 1;
  for (int i = n; i >= 1; i--) {
    cur = min(cur, nxt[i]);
    ans += cur - i;
  }
  cout << ans << endl;
}
