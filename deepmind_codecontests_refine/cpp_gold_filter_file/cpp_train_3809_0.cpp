#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int e, b;
  int n;
  cin >> n;
  vector<int> a[n + 1];
  std::vector<int> colors(n + 1, 0);
  int parent[n + 1];
  for (int i = 0; i < n - 1; i++) {
    cin >> e >> b;
    a[e].push_back(b);
    a[b].push_back(e);
  }
  parent[1] = 0;
  colors[1] = 1;
  queue<int> q;
  q.push(1);
  int tmp;
  while (!q.empty()) {
    tmp = q.front();
    q.pop();
    int color = 1;
    for (auto k : a[tmp]) {
      if (colors[k]) continue;
      while (color == colors[tmp] || color == colors[parent[tmp]]) {
        color++;
      }
      parent[k] = tmp;
      colors[k] = color;
      color++;
      q.push(k);
    }
  }
  set<int> s;
  for (int i = 1; i < n + 1; i++) s.insert(colors[i]);
  cout << s.size() << endl;
  for (int i = 1; i < n + 1; i++) cout << colors[i] << " ";
}
