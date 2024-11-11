#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, q, w, k = 0;
  cin >> n;
  int a;
  cin >> a;
  int x[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> x[i];
  }
  for (int i = 1; i <= n; i++) {
    if (x[i] == 1) {
      q = i - a;
      w = a - q;
      if (w < 1 || w > n || x[i] == x[w]) {
        k++;
      }
    }
  }
  cout << k;
  return 0;
}
