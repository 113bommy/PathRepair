#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1010;
int root[MAXN];
int find(int x) {
  if (x == root[x]) return x;
  return find(root[x]);
}
bool Union(int a, int b) {
  int fa = find(a);
  int fb = find(b);
  if (fa == fb && a != b) return false;
  root[fb] = fa;
  return true;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, m, u, v;
  bool flag = true;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) root[i] = i;
  for (int i = 0; i < m; i++) {
    cin >> u >> v;
    if (!Union(u, v)) flag = false;
  }
  int father = find(1);
  if (!flag) {
    for (int i = 2; i <= n; i++) {
      if (find(i) != father) {
        flag = false;
        break;
      }
    }
  }
  puts(flag ? "yes" : "no");
}
