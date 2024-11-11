#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, l, m = 0, sum = 0;
  cin >> n;
  for (i = 1; i <= n; i++) {
    cin >> l;
    if (l > m) m = 1;
    sum += l;
  }
  cout << -sum + m + m + 1;
  return 0;
}
