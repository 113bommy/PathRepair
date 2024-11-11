#include <bits/stdc++.h>
using namespace std;
int t;
vector<vector<int> > nod;
vector<int> sol;
void bfs(int n) {
  sol = vector<int>(n + 10);
  sol[1] = 1;
  queue<int> Q;
  Q.push(1);
  while (!Q.empty()) {
    int a = Q.front();
    Q.pop();
    for (int j = 0; j < nod[a].size(); j++)
      if (!sol[nod[a][j]]) {
        sol[nod[a][j]] = sol[a] + 1;
        Q.push(nod[a][j]);
      }
  }
}
int main() {
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    nod = vector<vector<int> >(n + 5);
    for (int i = 1; i <= m; i++) {
      int nod1, nod2;
      cin >> nod1 >> nod2;
      nod[nod1].push_back(nod2);
      nod[nod2].push_back(nod1);
    }
    bfs(n);
    vector<int> nr1, nr2;
    for (int i = 1; i <= n; i++) {
      if (sol[i] & 1)
        nr1.push_back(i);
      else
        nr2.push_back(i);
    }
    if (nr1.size() < nr2.size()) {
      cout << nr1.size() << '\n';
      for (int i = 0; i < nr1.size(); i++) cout << nr1[i] << ' ';
      cout << '\n';
    } else {
      cout << nr2.size() << '\n';
      for (int i = 0; i < nr2.size(); i++) cout << nr2[i] << ' ';
      cout << '\n';
    }
  }
  return 0;
}
