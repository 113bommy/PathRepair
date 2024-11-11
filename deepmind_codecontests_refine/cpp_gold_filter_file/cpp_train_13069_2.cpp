#include <bits/stdc++.h>
using namespace std;
int L[200005];
vector<int> v[200005];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>
    q;
void bfs() {
  int cnt = 0;
  L[1] = 0;
  q.push(pair<int, int>(0, 1));
  while (!q.empty()) {
    int u = q.top().second;
    q.pop();
    for (int i : v[u]) {
      if (L[i] > L[u] + 1) {
        L[i] = L[u] + 1;
        q.push(pair<int, int>(L[i], i));
      }
    }
  }
}
int main() {
  int t, tc = 0;
  int n;
  cin >> n;
  for (int i = 1; i < n; i++) v[i].push_back(i + 1), v[i + 1].push_back(i);
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    if (i != x) v[i].push_back(x);
    L[i] = 200005;
  }
  bfs();
  for (int i = 1; i <= n; i++) cout << L[i] << " ";
  cout << endl;
  return 0;
}
