#include <bits/stdc++.h>
using namespace std;
int q[1000001] = {0};
int main() {
  int i, n, m, a, b, c;
  cin >> n >> m;
  for (i = 0; i < m; i++) {
    cin >> a >> b >> c;
    if (q[a] == 0 && q[b] == 0 && q[c] == 0) {
      q[a] = 1;
      q[b] = 2;
      q[c] = 3;
      continue;
    }
    if (q[a] == 1) {
      q[b] = 2;
      q[c] = 3;
      continue;
    }
    if (q[a] == 2) {
      q[b] = 1;
      q[c] = 3;
      continue;
    }
    if (q[a] == 3) {
      q[b] = 1;
      q[c] = 2;
      continue;
    }
    if (q[b] == 1) {
      q[a] = 2;
      q[c] = 3;
      continue;
    }
    if (q[b] == 2) {
      q[a] = 1;
      q[c] = 3;
      continue;
    }
    if (q[b] == 3) {
      q[a] = 1;
      q[c] = 2;
      continue;
    }
    if (q[c] == 1) {
      q[b] = 2;
      q[a] = 3;
      continue;
    }
    if (q[c] == 2) {
      q[b] = 1;
      q[a] = 3;
      continue;
    }
    if (q[c] == 3) {
      q[b] = 1;
      q[a] = 2;
      continue;
    }
  }
  for (i = 1; i <= n; i++) cout << q[i] << " ";
  return 0;
}
