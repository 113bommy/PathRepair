#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 5;
struct union_find {
  int parent[maxn];
  union_find() {
    for (int i = 0; i < maxn; i++) {
      parent[i] = i;
    }
  }
  int find(int x) {
    if (parent[x] == x) {
      return x;
    }
    return parent[x] = find(parent[x]);
  }
  void update(int x, int y) {
    if (rand() & 1) {
      swap(x, y);
    }
    parent[find(x)] = find(y);
  }
  bool query(int x, int y) { return find(x) == find(y); }
};
union_find U;
vector<int> ms[maxn];
bitset<maxn> b;
bitset<maxn> svi;
int boja[maxn];
bitset<maxn> bio;
void namjesti(int x) {
  bio[x] = 1;
  for (int i = 0; i < (int)ms[x].size(); i++) {
    svi[ms[x][i]] = 1;
  }
  int y;
  int br;
  for (int i = 0; i < (int)ms[x].size(); i++) {
    if (!bio[ms[x][i]]) {
      y = ms[x][i];
      if (ms[x].size() != ms[y].size()) {
        continue;
      }
      br = 0;
      for (int j = 0; j < (int)ms[y].size(); j++) {
        if (svi[ms[y][j]]) {
          br++;
        }
      }
      if (br == (int)ms[x].size() - 1) {
        U.update(x, y);
        bio[y] = 1;
      }
    }
  }
  for (int i = 0; i < (int)ms[x].size(); i++) {
    svi[ms[x][i]] = 0;
  }
}
void siri(int x, int col, int raz) {
  bio[x] = 1;
  boja[x] = col;
  int y;
  for (int i = 0; i < (int)ms[x].size(); i++) {
    y = U.find(ms[x][i]);
    if (!bio[y]) {
      siri(y, col + raz, raz);
      raz *= -1;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  srand(time(NULL));
  int n, m;
  cin >> n >> m;
  int a, b;
  for (int i = 0; i < m; i++) {
    cin >> a >> b;
    a--;
    b--;
    ms[a].push_back(b);
    ms[b].push_back(a);
  }
  for (int i = 0; i < n; i++) {
    if (!bio[i]) {
      namjesti(i);
    }
  }
  int x;
  bool p = 0;
  set<int> s;
  for (int i = 0; i < n; i++) {
    x = U.find(i);
    for (int j = 0; j < (int)ms[x].size(); j++) {
      s.insert(U.find(ms[x][j]));
    }
    s.erase(x);
    if (s.size() > 2) {
      cout << "NO\n";
      return 0;
    }
    if (s.size() == 1) {
      p = 1;
    }
    s.clear();
  }
  if (!p) {
    cout << "NO\n";
    return 0;
  }
  cout << "YES\n";
  bio.reset();
  siri(0, 1e6, -1);
  for (int i = 0; i < n; i++) {
    cout << boja[U.find(i)] << ' ';
  }
  cout << '\n';
  return 0;
}
