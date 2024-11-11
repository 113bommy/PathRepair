#include <bits/stdc++.h>
using namespace std;
vector<int> adj[100005];
int n;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  queue<int> b;
  queue<int> book;
  vector<bool> visited(n, false);
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    b.push(x);
  }
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    book.push(x);
  }
  while (!book.empty()) {
    int v = book.front();
    book.pop();
    int counts = 0;
    if (!visited[v]) {
      while (!b.empty()) {
        int u = b.front();
        b.pop();
        visited[u] = true;
        counts++;
        if (u == v) break;
      }
    }
    cout << counts << " ";
  }
  return 0;
}
