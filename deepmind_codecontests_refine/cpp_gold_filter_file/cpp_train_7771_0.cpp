#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int degree[n + 1];
  for (int i = 0; i < n + 1; i++) degree[i] = 0;
  int tmp = n - 1;
  while (tmp--) {
    int u, v;
    cin >> u >> v;
    degree[u]++;
    degree[v]++;
  }
  int count = 0;
  for (int i = 1; i < n + 1; i++) {
    if (degree[i] <= 1) count++;
  }
  cout << count << endl;
  return 0;
}
