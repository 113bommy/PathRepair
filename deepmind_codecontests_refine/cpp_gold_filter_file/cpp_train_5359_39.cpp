#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  int b, g;
  cin >> b;
  int i;
  int B[n];
  for (i = 0; i < n; i++) {
    B[i] = 0;
  }
  int bb[b];
  for (i = 0; i < b; i++) {
    cin >> bb[i];
    B[bb[i]] = 1;
  }
  cin >> g;
  int G[m];
  for (i = 0; i < m; i++) {
    G[i] = 0;
  }
  int gg[g];
  for (i = 0; i < g; i++) {
    cin >> gg[i];
    G[gg[i]] = 1;
  }
  for (i = 0; i < 10000; i++) {
    if (B[i % n] == 1) {
      G[i % m] = 1;
    }
    if (G[i % m] == 1) {
      B[i % n] = 1;
    }
  }
  i = 0;
  while (i < n) {
    if (B[i] == 0) {
      cout << "No";
      return 0;
    }
    if (B[i] == 1) {
      i++;
    }
  }
  i = 0;
  while (i < m) {
    if (G[i] == 0) {
      cout << "No";
      return 0;
    }
    if (G[i] == 1) {
      i++;
    }
  }
  cout << "Yes";
  return 0;
}
