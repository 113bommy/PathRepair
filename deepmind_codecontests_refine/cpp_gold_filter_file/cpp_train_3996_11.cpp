#include <bits/stdc++.h>
using namespace std;
long long int n, m, i, h[100001], w[100001], a[100001], l;
int main() {
  cin >> n;
  for (i = 0; i < n; i++) cin >> a[i];
  cin >> m;
  for (i = 0; i < m; i++) {
    cin >> w[i] >> h[i];
  }
  l = 0;
  for (i = 0; i < m; i++) {
    l = max(l + h[i - 1], a[w[i] - 1]);
    cout << l << endl;
  }
  return 0;
}
