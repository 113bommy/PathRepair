#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, j, n, m, k;
  cin >> n >> m >> k;
  int a[105];
  for (i = 0; i < n; i++) {
    cin >> a[i];
  }
  int sum = 0;
  for (i = 0; i < n - m; i++) {
    sum += a[i];
  }
  for (i = n - m; i < n; i++) {
    sum += k;
  }
  cout << sum << endl;
}
