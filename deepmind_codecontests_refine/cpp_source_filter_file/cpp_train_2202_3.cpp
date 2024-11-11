#include <bits/stdc++.h>
using namespace std;
const int maxn = (int)3e5 + 10;
struct node {
  int nxt, to;
} edg[maxn * 2];
int head[maxn], num;
int f[maxn], n, a[maxn];
void add(int a, int b) {
  edg[++num].to = b;
  edg[num].nxt = head[a];
  head[a] = num;
}
int k = 0;
void dfs(int root) {
  if (edg[head[root]].nxt == 0) {
    f[root] = 1;
    k++;
    return;
  }
  if (a[root] == 1) f[root] = 1e7;
  int t = head[root];
  while (t != 0) {
    dfs(edg[t].to);
    if (a[root] == 1) {
      f[root] = min(f[root], f[edg[t].to]);
    } else {
      f[root] += f[edg[t].to];
    }
    t = edg[t].nxt;
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 2; i <= n; i++) {
    int fat;
    cin >> fat;
    add(fat, i);
  }
  dfs(1);
  cout << k + 1 - f[1];
  return 0;
}
