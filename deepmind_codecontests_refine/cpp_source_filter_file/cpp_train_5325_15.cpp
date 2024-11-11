#include <bits/stdc++.h>
using namespace std;
int n, a[55];
int main() {
  cin >> n;
  int mn = 55;
  for (int i = 0; i <= n; i++) {
    cin >> a[i];
    mn = min(mn, a[i]);
  }
  int ct = 0;
  for (int i = 0; i <= n; i++) {
    if (a[i] == mn) ct++;
  }
  if (ct > n / 2)
    cout << "Bob";
  else
    cout << "Alice";
  return 0;
}
