#include <bits/stdc++.h>
using namespace std;
const int N = 1000000;
int main() {
  int a[10000], n;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  bool ok = true;
  if (n == 1 && a[1] == 1)
    cout << "YES" << endl;
  else if (n == 1 && a[1] == 0)
    cout << "NO" << endl;
  else {
    int num0 = 0;
    for (int i = 1; i <= n; i++) num0 += a[i];
    if (num0 == n - 1)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
