#include <bits/stdc++.h>
using namespace std;
int graph[101] = {};
long long sum = 0LL;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m;
  cin >> n >> m;
  while (m--) {
    int a, b, c;
    cin >> a >> b >> c;
    graph[a] += c;
    graph[b] -= c;
  }
  for (int i = 0; i < n; i++) {
    if (graph[i] > 0) sum += graph[i];
  }
  cout << sum << endl;
  return 0;
}
