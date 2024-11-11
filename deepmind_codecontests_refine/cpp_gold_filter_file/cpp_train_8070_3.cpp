#include <bits/stdc++.h>
using namespace std;
inline long double min(long double a, long double b) {
  if (a < b) return a;
  return b;
}
inline long double max(long double a, long double b) {
  if (a < b) return b;
  return a;
}
int m, n;
int arr[1001100];
int arrT[1001100];
int root[1001100];
int val[1001100];
int row[1001100];
int col[1001100];
int find(int i) { return i == root[i] ? i : root[i] = find(root[i]); }
void uni(int u, int v) {
  u = find(u);
  v = find(v);
  root[v] = u;
}
void solve() {
  for (int(i) = (0); (i) < (1001100); ++(i)) root[i] = i;
  for (int(i) = (0); (i) < (m); ++(i)) {
    map<int, int> umap;
    for (int(j) = (0); (j) < (n); ++(j)) {
      if (umap.count(arr[i * n + j]) != 0) {
        uni(i * n + j, umap[arr[i * n + j]]);
      }
      umap[arr[i * n + j]] = i * n + j;
    }
  }
  for (int(j) = (0); (j) < (n); ++(j)) {
    map<int, int> umap;
    for (int(i) = (0); (i) < (m); ++(i)) {
      if (umap.count(arr[i * n + j]) != 0) {
        uni(i * n + j, umap[arr[i * n + j]]);
      }
      umap[arr[i * n + j]] = i * n + j;
    }
  }
  vector<pair<int, int> > tmp;
  for (int(i) = (0); (i) < (m); ++(i))
    for (int(j) = (0); (j) < (n); ++(j))
      tmp.push_back(make_pair(arr[i * n + j], i * n + j));
  sort(tmp.begin(), tmp.end());
  memset(col, 0, sizeof col);
  memset(row, 0, sizeof row);
  memset(val, 0, sizeof val);
  vector<int> buf;
  for (int(i) = (0); (i) < (tmp.size()); ++(i)) {
    int pos = tmp[i].second;
    int v = max(row[pos / n], col[pos % n]) + 1;
    val[find(pos)] = max(val[find(pos)], v);
    if (i == tmp.size() - 1 || tmp[i].first != tmp[i + 1].first) {
      int p = i;
      while (p >= 0 && tmp[p].first == tmp[i].first) {
        int ppos = tmp[p].second;
        row[ppos / n] = max(row[ppos / n], val[find(ppos)]);
        col[ppos % n] = max(col[ppos % n], val[find(ppos)]);
        p--;
      }
    }
  }
}
int main() {
  cin.tie(0);
  cin.sync_with_stdio(false);
  cin >> m >> n;
  for (int(i) = (0); (i) < (m); ++(i))
    for (int(j) = (0); (j) < (n); ++(j)) cin >> arr[i * n + j];
  solve();
  for (int(i) = (0); (i) < (m); ++(i)) {
    for (int(j) = (0); (j) < (n); ++(j)) cout << val[find(i * n + j)] << " ";
    cout << endl;
  }
  return 0;
}
