#include <bits/stdc++.h>
using namespace std;
void run();
int main() {
  ios::sync_with_stdio(0);
  run();
}
map<int *, int> orig;
map<int, int> renum[100000];
vector<int> edge[300000];
int *mat[100000];
int deps[300000];
vector<int> res;
int rnk;
bool cmp(int *a, int *b) { return a[rnk] < b[rnk]; }
void add(int s, int t) {
  if (s < 0) return;
  edge[s].push_back(t);
  ++deps[t];
}
void run() {
  int n, m;
  cin >> m >> n;
  for (int i = n; i--;) orig[mat[i] = new int[m]] = i;
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++) {
      cin >> mat[j][i];
      if (~mat[j][i]) renum[i][mat[j][i]] = 0;
    }
  int verts = n;
  for (int z = n; (++verts) and (z--);)
    for (auto &i : renum[z]) i.second = verts++;
  for (rnk = 0; rnk < m; ++rnk) {
    sort(mat, mat + n, cmp);
    for (int i = 0; i < n; i++) {
      if (!~mat[i][rnk]) continue;
      int id = orig[mat[i]];
      add(id, renum[rnk][mat[i][rnk]] + 0);
      add(renum[rnk][mat[i][rnk]] - 1, id);
    }
  }
  queue<int> bfs;
  for (int i = verts; i--;)
    if (not deps[i]) bfs.push(i);
  while (not bfs.empty()) {
    int const x = bfs.front();
    bfs.pop();
    if (x < n) res.push_back(x + 1);
    for (int const y : edge[x])
      if (not --deps[y]) bfs.push(y);
  }
  if (res.size() < n) {
    cout << "-1\n";
    return;
  } else
    for (int i = 0; i < res.size(); i++)
      cout << res[i] << (i + 1 == res.size() ? '\n' : ' ');
}
