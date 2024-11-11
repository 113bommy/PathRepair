#include <bits/stdc++.h>
using namespace std;
int n, k, x, y, p;
int v[109][109];
int main() {
  cin >> n >> k;
  p = k;
  while (k) {
    v[x++][y++] = p;
    k--;
  }
  for (int i = 0; i < n; i++) {
    for (int h = 0; h < n; h++) cout << v[i][h] << " ";
    cout << "\n";
  }
  return 0;
}
