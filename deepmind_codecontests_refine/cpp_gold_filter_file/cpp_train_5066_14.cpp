#include <bits/stdc++.h>
using namespace std;
long long a[200008], b[200008];
int main() {
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(0);
  long long n, m, x;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i], a[i] += a[i - 1];
  }
  for (int i = 0; i < m; i++) {
    cin >> b[i];
  }
  int i = 0, j = 1;
  long long mx = 0;
  while (1) {
    while (b[i] > a[j]) {
      j++;
      mx = a[j - 1];
    }
    cout << j << " " << b[i] - mx << "\n";
    i++;
    if (i == m) break;
  }
  return 0;
}
