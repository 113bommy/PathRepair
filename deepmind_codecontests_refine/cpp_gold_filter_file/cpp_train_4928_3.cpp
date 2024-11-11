#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a, b;
  cin >> n >> a >> b;
  int x[n];
  for (int i = 0; i < n; i++) {
    cin >> x[i];
  }
  sort(x, x + n);
  int z = x[b] - x[b - 1];
  cout << z;
  return 0;
}
