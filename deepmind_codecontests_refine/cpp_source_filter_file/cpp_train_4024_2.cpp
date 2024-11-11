#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, c, flag = 1, flag2 = 1, p = 0;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 1; i < n; i++) {
    if (a[i - 1] != a[i]) {
      flag = 0;
      p++;
    }
  }
  if (flag || p == n - 1) {
    cout << "YES" << endl;
    return 0;
  }
  for (int i = 0; i < n; i++)
    if (i && a[i - 1] != a[i]) {
      c = i;
      break;
    }
  for (int i = 0; i <= n - c; i++)
    if (a[i] == a[i + c]) {
      flag2 = 0;
      break;
    }
  if (n % c != 0 && flag2)
    cout << "NO" << endl;
  else if (flag2)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}
