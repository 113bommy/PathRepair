#include <bits/stdc++.h>
using namespace std;
int a[100005], b[100005];
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < m; i++) cin >> b[i];
  sort(a, a + n);
  sort(b, b + m);
  int ok = 0;
  if (n > m) ok = 1;
  for (int i = 0; i < n; i++)
    if (a[i] > b[m - n + i]) ok = 1;
  if (ok)
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
