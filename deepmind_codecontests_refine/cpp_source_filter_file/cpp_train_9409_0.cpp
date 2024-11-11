#include <bits/stdc++.h>
using namespace std;
long long MOD = 1e9 + 7;
int OO = 1e9;
const int N = 5e2 + 10, M = 1e5;
int mat[N][N], nodes[N], vis[N];
int n, m, k, T;
int a, b, c;
vector<long long> ans;
void Floyd() {
  for (int k = 0; k < n; ++k) {
    int mid = nodes[k];
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (!mat[i][j] || !mat[i][mid] || !mat[mid][j]) continue;
        mat[i][j] = min(mat[i][j], mat[i][mid] + mat[mid][j]);
      }
    }
    vis[mid] = true;
    long long ret = 0;
    for (int i = 0; i < n; ++i) {
      if (!vis[i]) continue;
      for (int j = 0; j < n; ++j) {
        if (!vis[j]) continue;
        ret += mat[i][j];
      }
    }
    ans.push_back(ret);
  }
  reverse(ans.begin(), ans.end());
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j) scanf("%d", mat[i] + j);
  for (int i = 0; i < n; ++i) {
    scanf("%d", nodes + i);
    --nodes[i];
  }
  reverse(nodes, nodes + n);
  Floyd();
  for (long long &it : ans) printf("%d ", it);
  return 0;
}
