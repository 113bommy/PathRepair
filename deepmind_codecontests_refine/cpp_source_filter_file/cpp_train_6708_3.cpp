#include <bits/stdc++.h>
using namespace std;
const long long N = 1e6 + 5;
long long m, n;
long long t[100], a[100];
int main() {
  cin >> m >> n;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) cin >> a[j];
    t[0] = t[0] + a[0];
    for (int j = 1; j < n; j++) t[j] = max(t[0], t[j]) + a[j];
    cout << t[n - 1] << " ";
  }
  return 0;
}
