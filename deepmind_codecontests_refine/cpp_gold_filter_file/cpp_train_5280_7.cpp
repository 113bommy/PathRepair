#include <bits/stdc++.h>
using namespace std;
int N;
int count1[100005];
vector<int> adj[100005];
void numberOfNodes(int s, int e) {
  vector<int>::iterator u;
  count1[s] = 1;
  for (u = adj[s].begin(); u != adj[s].end(); u++) {
    if (*u == e) continue;
    numberOfNodes(*u, s);
    count1[s] += count1[*u];
  }
}
void addEdge(int a, int b) {
  adj[a].push_back(b);
  adj[b].push_back(a);
}
int main() {
  cin >> N;
  for (int i = 0; i < N - 1; i++) {
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    addEdge(x, y);
  }
  numberOfNodes(0, -1);
  int ans = 0;
  for (int i = 0; i < N; i++) {
    if (count1[i] % 2 == 0) ans++;
  }
  ans--;
  if (N % 2 == 1)
    cout << "-1\n";
  else
    cout << ans << "\n";
  return 0;
}
