#include <bits/stdc++.h>
using namespace std;
vector<vector<long long int> > tree;
vector<long long int> dist, deep, used;
long long int dia;
void dfs(long long int nd, long long int p = -1) {
  used[nd] = 1;
  deep[nd] = dist[nd];
  for (long long int i = 0; i < (long long int)tree[nd].size(); i++) {
    long long int nxt = tree[nd][i];
    if (used[nxt] == 0) {
      dist[nxt] = dist[nd] + 1;
      dfs(nxt, nd);
      deep[nd] = max(deep[nd], deep[nxt]);
    }
  }
  long long int big = 0, second_big = 0;
  for (long long int i = 0; i < (long long int)tree[nd].size(); i++) {
    long long int nxt = tree[nd][i];
    if (nxt != p) {
      if (deep[nxt] - dist[nd] > big) {
        second_big = big;
        big = deep[nxt] - dist[nd];
      } else {
        second_big = max(second_big, deep[nxt] - dist[nd]);
      }
    }
  }
  dia = max(dia, big + second_big + 1);
}
int main() {
  long long int T;
  cin >> T;
  while (T--) {
    long long int n, a, b, da, db;
    cin >> n >> a >> b >> da >> db;
    vector<vector<long long int> > new_tree(n);
    for (long long int i = 0; i < n - 1; i++) {
      long long int x, y;
      cin >> x >> y;
      x--;
      y--;
      new_tree[x].push_back(y);
      new_tree[y].push_back(x);
    }
    tree = new_tree;
    dist = vector<long long int>(n);
    deep = vector<long long int>(n);
    used = vector<long long int>(n);
    dia = 0;
    dfs(a - 1);
    dia = max(dia, deep[a - 1] + 1);
    long long int diff = dist[b - 1] - dist[a - 1];
    if (diff <= da) {
      cout << "Alice\n";
      continue;
    }
    if (dia <= 2 * da) {
      cout << "Alice\n";
      continue;
    }
    if (db <= 2 * da)
      cout << "Alice\n";
    else
      cout << "Bob\n";
  }
}
