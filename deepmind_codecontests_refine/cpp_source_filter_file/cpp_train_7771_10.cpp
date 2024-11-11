#include <bits/stdc++.h>
using namespace std;
int main() {
  int N;
  cin >> N;
  int u, v, path[1000], remote = 0;
  for (int i = 1; i <= N - 1; i++) {
    cin >> u >> v;
    path[u]++;
    path[v]++;
  }
  for (int i = 1; i <= N; i++) {
    if (path[i] == 1) remote++;
  }
  cout << remote << "\n";
  return 0;
}
