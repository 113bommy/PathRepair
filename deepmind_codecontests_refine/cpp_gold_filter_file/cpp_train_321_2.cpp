#include <bits/stdc++.h>
using namespace std;
const int N = 200500;
vector<int> g[N];
vector<int> k[2];
int ask(char c, int x) {
  cout << c << " " << x + 1 << endl;
  int y;
  cin >> y;
  y--;
  return y;
}
int dist[N];
int main() {
  int tn;
  cin >> tn;
  for (int tc = 0, qwerty = tn; tc < qwerty; tc++) {
    int n;
    cin >> n;
    for (int i = 0, qwerty = n; i < qwerty; i++) g[i].clear();
    for (int i = 1, qwerty = n; i < qwerty; i++) {
      int x, y;
      cin >> x >> y;
      x--;
      y--;
      g[x].push_back(y);
      g[y].push_back(x);
    }
    for (int i = 0, qwerty = 2; i < qwerty; i++) {
      k[i].clear();
      int m;
      cin >> m;
      for (int j = 0, qwerty = m; j < qwerty; j++) {
        int x;
        cin >> x;
        x--;
        k[i].push_back(x);
      }
    }
    int root = ask('B', k[1][0]);
    for (int i = 0, qwerty = n; i < qwerty; i++) dist[i] = 1e9;
    queue<int> q;
    q.push(root);
    dist[root] = 0;
    while (!q.empty()) {
      int x = q.front();
      q.pop();
      for (int y : g[x]) {
        if (dist[y] > dist[x] + 1) {
          dist[y] = dist[x] + 1;
          q.push(y);
        }
      }
    }
    int less = -1, d = n;
    for (int x : k[0]) {
      if (dist[x] < d) {
        d = dist[x];
        less = x;
      }
    }
    if (d == 0) {
      cout << "C " << less + 1 << endl;
    } else {
      int v = ask('A', less);
      bool can = 0;
      for (int x : k[1]) {
        if (x == v) {
          can = 1;
        }
      }
      if (can) {
        cout << "C " << less + 1 << endl;
      } else {
        cout << "C -1" << endl;
      }
    }
  }
}
