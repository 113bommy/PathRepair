#include <bits/stdc++.h>
using namespace std;
const int N = 100009;
vector<int> vec[2009], seq[2009];
int c[2009], flag = true;
void dfs(int node) {
  int j, i, v, sz = vec[node].size(), id = 0;
  for (i = 0; i < sz && flag; i++) {
    v = vec[node][i];
    dfs(v);
    int szv = seq[v].size();
    for (j = 0; j < szv; j++) {
      if (id == c[node]) seq[node].push_back(node), id++;
      seq[node].push_back(seq[v][j]);
      id++;
    }
  }
  if (id == c[node])
    seq[node].push_back(node);
  else if (id < c[i])
    flag = false;
}
int main() {
  int n, i, p, root, ar[2009];
  scanf("%d", &n);
  for (i = 1; i <= n; i++) {
    scanf("%d %d", &p, &c[i]);
    if (p == 0) {
      root = i;
      continue;
    }
    vec[p].push_back(i);
  }
  dfs(root);
  if (flag) {
    printf("YES\n");
    int sz = seq[root].size();
    for (i = 0; i < sz; i++) {
      ar[seq[root][i]] = i + 1;
    }
    for (i = 1; i <= n; i++) {
      printf("%d ", ar[i]);
    }
    printf("\n");
  } else
    printf("NO\n");
  return 0;
}
