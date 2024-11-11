#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, u, i, j, prev = 0;
  double e[100001], mx = -1;
  cin >> n >> u;
  for (i = 0; i < n; i++) cin >> e[i];
  for (i = 0; i + 2 < n; i++) {
    for (j = min(n - 1, max(i + 2, prev)); j < n; j++) {
      if (e[j] - e[i] > u) break;
      mx = max(mx, (e[j] - e[i + 1]) / (e[j] - e[i]));
    }
    prev = j;
  }
  cout.precision(12);
  cout << mx << endl;
  return 0;
}
