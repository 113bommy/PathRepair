#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1.0);
int main() {
  ios_base::sync_with_stdio(false);
  long long int n, m, i, j;
  cin >> n >> m;
  long long int a[n + 1], b[m + 1];
  for (i = 0; i < n; i++) cin >> a[i];
  for (i = 0; i < n; i++) cin >> b[i];
  for (i = 0, j = 0; i < n && j < m; i++)
    if (b[j] >= a[i]) j++;
  cout << j << endl;
  return 0;
}
