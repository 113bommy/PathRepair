#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1000 * 100 + 10;
vector<int> v[MAX_N], a[MAX_N], b[MAX_N], javab, c;
bool check[MAX_N], edge[MAX_N];
map<pair<int, int>, int> m;
int parent[MAX_N];
void DFS(int x) {
  check[x] = true;
  for (int i = 0; i < v[x].size(); i++) {
    if (check[v[x][i]] == false) {
      parent[v[x][i]] = x;
      DFS(v[x][i]);
    } else if (parent[x] != v[x][i] &&
               edge[m[make_pair(x, v[x][i])]] == false) {
      b[x].push_back(v[x][i]);
      edge[m[make_pair(x, v[x][i])]] = true;
      edge[m[make_pair(v[x][i], x)]] = true;
    }
  }
  c.push_back(x);
  if (parent[x] != x) a[x].push_back(parent[x]);
}
int main() {
  int n, mm, x, y;
  ios::sync_with_stdio(false);
  cin >> n >> mm;
  for (int i = 0; i < mm; i++) {
    cin >> x >> y;
    x--;
    y--;
    v[x].push_back(y);
    v[y].push_back(x);
    m[make_pair(x, y)] = i;
    m[make_pair(y, x)] = i;
  }
  if (mm % 2 == 1) {
    cout << "No solution" << endl;
    return 0;
  }
  DFS(0);
  for (int i = 0; i < c.size(); i++) {
    int ras = c[i];
    if ((a[ras].size() + b[ras].size()) % 2 == 0) {
      if (a[ras].size() % 2 == 0) {
        for (int j = 0; j < b[ras].size(); j += 2) {
          javab.push_back(b[ras][j] + 1);
          javab.push_back(ras + 1);
          javab.push_back(b[ras][j + 1] + 1);
        }
        for (int j = 0; j < a[ras].size(); j += 2) {
          javab.push_back(a[ras][j] + 1);
          javab.push_back(ras + 1);
          javab.push_back(a[ras][j + 1] + 1);
        }
      } else {
        for (int j = 0; j < b[ras].size() - 1; j += 2) {
          javab.push_back(b[ras][j] + 1);
          javab.push_back(ras + 1);
          javab.push_back(b[ras][j + 1] + 1);
        }
        for (int j = 0; j < a[ras].size() - 1; j += 2) {
          javab.push_back(a[ras][j] + 1);
          javab.push_back(ras + 1);
          javab.push_back(a[ras][j + 1] + 1);
        }
        javab.push_back(b[ras][b[ras].size() - 1] + 1);
        javab.push_back(ras + 1);
        javab.push_back(a[ras][a[ras].size() - 1] + 1);
      }
    } else {
      if (b[ras].size() % 2 == 0)
        for (int j = 0; j < b[ras].size(); j += 2) {
          javab.push_back(b[ras][j] + 1);
          javab.push_back(ras + 1);
          javab.push_back(b[ras][j + 1] + 1);
        }
      if (b[ras].size() % 2 == 1) {
        for (int j = 0; j < b[ras].size() - 1; j += 2) {
          javab.push_back(b[ras][j] + 1);
          javab.push_back(ras + 1);
          javab.push_back(b[ras][j + 1] + 1);
        }
        javab.push_back(b[ras][b[ras].size() - 1] + 1);
        javab.push_back(ras + 1);
        javab.push_back(a[ras][a[ras].size() - 1] + 1);
        a[ras].pop_back();
      }
      if (a[ras].size() % 2 == 0)
        for (int j = 0; j < a[ras].size(); j += 2) {
          javab.push_back(a[ras][j] + 1);
          javab.push_back(ras + 1);
          javab.push_back(a[ras][j + 1] + 1);
        }
      else
        for (int j = 0; j < a[ras].size() - 1; j += 2) {
          javab.push_back(a[ras][j] + 1);
          javab.push_back(ras + 1);
          javab.push_back(a[ras][j + 1] + 1);
        }
      a[a[ras][a[ras].size() - 1]].push_back(ras);
    }
  }
  for (int i = 0; i < javab.size(); i += 3)
    cout << javab[i] << " " << javab[i + 1] << " " << javab[i + 2] << endl;
  return 0;
}
