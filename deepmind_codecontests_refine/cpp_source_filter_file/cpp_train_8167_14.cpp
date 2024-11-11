#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, s = 0, c = 0;
  cin >> n >> m;
  int a[n];
  for (int i = 0; i < n - 1; i++) cin >> a[i];
  for (int i = 0; i < n; i++) {
    if (i + 1 == m) c++;
    i += a[i];
  }
  if (c)
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
