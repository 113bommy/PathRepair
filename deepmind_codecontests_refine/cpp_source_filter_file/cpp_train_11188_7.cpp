#include <bits/stdc++.h>
using namespace std;
const int N = 2010;
map<string, int> mp;
int vis[N], pre[N];
char handle[N][25], ans[N][25];
struct DSU {
  void Init(int n) {
    for (int i = 1; i <= n; i++) pre[i] = i;
  }
  int Find(int x) {
    vis[pre[x]] = 1;
    return x == pre[x] ? x : Find(pre[x]);
  }
  void Union(int a, int b) {
    int x = Find(a);
    int y = Find(b);
    if (x == y) return;
    pre[y] = x;
  }
} dsu;
int main() {
  int n;
  while (cin >> n) {
    dsu.Init(n);
    mp.clear();
    int pos = 0;
    for (int i = 1; i <= n; i++) {
      char first[25], second[25];
      cin >> first >> second;
      if (!mp[first]) mp[first] = ++pos, strcpy(handle[pos], first);
      if (!mp[second]) mp[second] = ++pos, strcpy(handle[pos], second);
      pre[mp[first]] = mp[second];
    }
    int num = 0;
    for (int l = 1; l <= pos; l++) {
      if (!vis[l]) {
        vis[l] = 1;
        int r = dsu.Find(l);
        strcpy(ans[num++], handle[l]);
        strcpy(ans[num++], handle[r]);
      }
    }
    cout << num / 2 << endl;
    for (int i = 0; i < num; i++) {
      cout << ans[i] << (i % 2 ? '\n' : ' ');
    }
  }
  return 0;
}
