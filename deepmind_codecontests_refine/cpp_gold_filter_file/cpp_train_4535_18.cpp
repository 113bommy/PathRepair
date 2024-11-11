#include <bits/stdc++.h>
using namespace std;
int x[300010];
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x[i];
  }
  sort(x, x + n);
  cout << x[(n - 1) >> 1];
  return 0;
}
