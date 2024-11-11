#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100;
bool valid[MAXN];
int x = 0;
string cur = "Aaaaaaaaaa";
string gen_next() {
  int i = cur.length() - 1;
  while (cur[i] == 'c') {
    cur[i] = 'a';
    i--;
  }
  cur[i]++;
  return cur;
}
string names[MAXN];
vector<int> G[MAXN];
void add_edge(int i, int j) {
  G[i].push_back(j);
  G[j].push_back(i);
}
int color[MAXN];
void dfs(int v, int c) {
  if (color[v] != -1) {
    return;
  }
  color[v] = c;
  for (int u : G[v]) {
    dfs(u, c);
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cout << setprecision(10) << fixed;
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n - k + 1; i++) {
    string v;
    cin >> v;
    valid[i] = v == "YES";
  }
  for (int i = 0; i < n; i++) {
    if (!valid[i]) {
      add_edge(i, i + k - 1);
    }
  }
  int c = 0;
  fill(color, color + n, -1);
  for (int i = 0; i < n; i++) {
    if (color[i] == -1) {
      dfs(i, c++);
    }
  }
  map<int, string> naming;
  for (int i = 0; i < n; i++) {
    if (naming.find(color[i]) == naming.end()) {
      naming[color[i]] = gen_next();
    }
    names[i] = naming[color[i]];
  }
  for (int i = 0; i < n; i++) {
    cout << names[i] << " ";
  }
}
