#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a[n];
  int i = 0;
  while (i < n) {
    cin >> a[i];
    i++;
  }
  i = 0;
  int cost, mi = 1000009;
  while (i < n) {
    int j = 0;
    cost = 0;
    while (j < n) {
      cost += 2 * (max(i, j) - min(i, j) + j + i) * a[j];
      j++;
    }
    if (cost < mi) {
      mi = cost;
    }
    i++;
  }
  cout << mi;
}
