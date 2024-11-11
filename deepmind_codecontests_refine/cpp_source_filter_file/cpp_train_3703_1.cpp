#include <bits/stdc++.h>
using namespace std;
int n, mp[200000], col[200000] = {0};
vector<pair<int, int> > prs;
void DFS(int v) {
  col[v] = 1;
  v = mp[v];
  col[v] = 2;
  v += !((v & 1) << 1) - 1;
  if (col[v] == 0) DFS(v);
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    a--;
    b--;
    prs.push_back({a, b});
    mp[a] = b;
    mp[b] = a;
  }
  for (int i = 0; i < 2 * n; i++) {
    if (col[i] == 0) {
      DFS(i);
    }
  }
  for (auto x : prs) printf("%d %d\n", col[x.first], col[x.second]);
}
