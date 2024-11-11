#include <bits/stdc++.h>
using namespace std;
int n, a[300300];
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  sort(a + 1, a + n + 1);
  cout << a[n / 2] << endl;
  return 0;
}
