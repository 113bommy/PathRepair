#include <bits/stdc++.h>
using namespace std;
struct Arista {
  int u;
  int v;
  Arista(int a, int b) {
    u = a;
    v = b;
  }
};
bool ord(vector<int> a, vector<int> b) { return a.size() < b.size(); }
int main() {
  int n;
  cin >> n;
  int p[n + 1];
  bool vis[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> p[i];
    vis[i] = false;
  }
  vector<vector<int> > cycles;
  vector<int> aCycle;
  for (int i = 1; i < n; i++) {
    aCycle.clear();
    while (!vis[i]) {
      aCycle.push_back(i);
      vis[i] = true;
      i = p[i];
    }
    if (!aCycle.empty()) {
      cycles.push_back(aCycle);
    }
  }
  sort(cycles.begin(), cycles.end(), ord);
  vector<Arista> res;
  if (cycles[0].size() <= 2) {
    int s = cycles[0].size();
    int node;
    if (s == 2) {
      res.push_back(Arista(cycles[0][0], cycles[0][1]));
    }
    node = cycles[0][0];
    for (int i = 1; i < cycles.size(); i++) {
      if (s == 2 && cycles[i].size() % 2) {
        cout << "NO" << endl;
        return 0;
      }
      for (int j = 0; j < cycles[i].size(); j++) {
        res.push_back(Arista(node, cycles[i][j]));
        node = p[node];
      }
    }
    cout << "YES" << endl;
    for (int i = 0; i < res.size(); i++) {
      cout << res[i].u << " " << res[i].v << endl;
    }
  } else
    cout << "NO" << endl;
  return 0;
}
