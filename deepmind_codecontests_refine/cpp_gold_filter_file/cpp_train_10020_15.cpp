#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  for (; b; a %= b, swap(a, b))
    ;
  return a;
}
int n, x;
vector<int> graph[1001];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> x;
    for (int i = 1; i <= n; i++) graph[i].clear();
    for (int i = 0; i < n - 1; i++) {
      int u, v;
      cin >> u >> v;
      graph[u].push_back(v);
      graph[v].push_back(u);
    }
    if (graph[x].size() <= 1) {
      cout << "Ayush\n";
      continue;
    }
    int edge = n - 3;
    if (edge % 2 == 0)
      cout << "Ashish\n";
    else
      cout << "Ayush\n";
  }
}
