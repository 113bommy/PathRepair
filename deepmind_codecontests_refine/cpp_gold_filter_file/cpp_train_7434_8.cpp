#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int a[maxn], part[maxn];
int main() {
  int n, d;
  cin >> n >> d;
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);
  part[0] = a[0];
  for (int i = 1; i < n; i++) part[i] = part[i - 1] + a[i];
  int m;
  cin >> m;
  if (m <= n)
    cout << part[m - 1] << endl;
  else
    cout << part[n - 1] - d * (m - n) << endl;
  return 0;
}
