#include <bits/stdc++.h>
using namespace std;
int n, m;
int ppl[105];
int main() {
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int from, to, dep;
    cin >> from >> to >> dep;
    ppl[from] -= dep;
    ppl[to] += dep;
  }
  int total = 0;
  for (int i = 1; i <= n; i++)
    if (ppl[i] > 0) total += ppl[i];
  cout << total;
  return 0;
}
