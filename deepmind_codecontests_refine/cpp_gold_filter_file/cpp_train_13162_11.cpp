#include <bits/stdc++.h>
using namespace std;
int a[120];
int n, m;
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> a[i];
  sort(a + 1, a + n + 1);
  int s = 0;
  int j;
  for (j = 1; j < n; j++) {
    s += a[j];
    if (s > m) break;
  }
  if (j < n)
    cout << "NO";
  else
    cout << "YES";
  return 0;
}
