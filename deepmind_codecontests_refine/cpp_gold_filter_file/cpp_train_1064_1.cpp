#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int size;
  cin >> size;
  vector<vector<int>> adj(size + 1, vector<int>(0, 0));
  queue<pair<int, int>> q;
  for (int i = 0; i < size - 1; i++) {
    int x, y;
    cin >> x >> y;
    q.push(make_pair(x, y));
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  int val[] = {0, 1, 2};
  int flag = 0;
  map<pair<int, int>, int> s;
  int count = 0;
  for (int i = 1; i <= size; i++) {
    if (adj[i].size() == 1) {
      pair<int, int> x = make_pair(i, adj[i][0]);
      s[x]++;
      x = make_pair(adj[i][0], i);
      s[x]++;
      count++;
    }
    if (count == 3) break;
  }
  while (!q.empty()) {
    pair<int, int> x = q.front();
    q.pop();
    if (s[x] >= 1) {
      cout << val[flag++] << "\n";
    } else
      cout << count++ << "\n";
  }
  return 0;
}
