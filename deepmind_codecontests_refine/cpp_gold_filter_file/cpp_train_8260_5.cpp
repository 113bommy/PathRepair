#include <bits/stdc++.h>
using namespace std;
const int N = 100005, M = 2000005;
int n;
int cnt[M];
int v[N];
set<int> s;
bool vis[M];
int main(void) {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &v[i]);
  }
  for (int i = 0; i < n; i++) {
    set<int> s2;
    for (int x : s) {
      s2.insert(x | v[i]);
      vis[x | v[i]] = 1;
    }
    s2.insert(v[i]);
    vis[v[i]] = 1;
    s = s2;
  }
  int ans = 0;
  for (int i = 0; i < M; i++) {
    if (vis[i]) {
      ans++;
    }
  }
  printf("%d\n", ans);
  return 0;
}
