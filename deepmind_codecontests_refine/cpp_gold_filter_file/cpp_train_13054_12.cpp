#include <bits/stdc++.h>
using namespace std;
vector<int> v[10010];
map<int, bool> mp;
void DFS(int x) {
  if (v[x].size()) return;
  v[x].push_back(x);
  for (int bit = 10; bit < x; bit *= 10) {
    int a = x % bit, b = x / bit;
    DFS(a);
    DFS(b);
    for (int i = 0; i < v[a].size(); i++)
      for (int j = 0; j < v[b].size(); j++) {
        v[x].push_back(v[a][i] + v[b][j]);
        v[x].push_back(v[a][i] - v[b][j]);
        v[x].push_back(v[b][j] - v[a][i]);
        v[x].push_back(v[a][i] * v[b][j]);
      }
  }
  sort(v[x].begin(), v[x].end());
  vector<int>::iterator it = unique(v[x].begin(), v[x].end());
  v[x].resize(distance(v[x].begin(), it));
}
bool outit(int y, int x) {
  if (y < 0 || y >= 10000) return false;
  int tmp = y * 10000 + x;
  if (mp[tmp]) return false;
  mp[tmp] = 1;
  printf("%04d%04d\n", y, x);
  return 1;
}
int main() {
  int K, m;
  cin >> K >> m;
  for (int x = 1; x < 10000; x++) {
    DFS(x);
    for (int i = 0; i < v[x].size(); i++) {
      if (outit(K - v[x][i], x)) --m;
      if (!m) return 0;
      if (v[x][i] && outit(K + v[x][i], x)) --m;
      if (!m) return 0;
    }
  }
}
