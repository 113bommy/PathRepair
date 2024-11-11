#include <bits/stdc++.h>
using namespace std;
int n;
int a[110];
int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  if (n % 2 == 1) {
    if (a[1] % 2 == 1 && a[n] % 2 == 1)
      cout << "Yes\n";
    else
      cout << "No\n";
    return 0;
  } else {
    cout << "No\n";
    return 0;
  }
  return 0;
}
