#include <bits/stdc++.h>
using namespace std;
int main() {
  int birds[100], n, m, x, y, left, right;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> birds[i];
  cin >> m;
  while (m--) {
    cin >> x >> y;
    left = y - 1;
    right = birds[x - 1] - y;
    if (x == 1)
      birds[x] += right;
    else if (x == n)
      birds[x - 2] += left;
    else {
      birds[x] += right;
      birds[x - 2] += left;
    }
    birds[x - 1] = 0;
  }
  for (int i = 0; i < n; i++) cout << birds[i] << " ";
}
