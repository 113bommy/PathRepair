#include <bits/stdc++.h>
using namespace std;
int n, a[500 + 5];
int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  for (int i = 1; i <= 2 * n; i++) cin >> a[i];
  sort(a + 1, a + 2 * n + 1);
  if (a[n + 1] >= a[n])
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}
