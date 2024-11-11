#include <bits/stdc++.h>
using namespace std;
int a[100010];
int main() {
  ios_base::sync_with_stdio(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    while (a[i] && a[i] % 2 == 0) a[i] /= 2;
    while (a[i] && a[i] % 3 == 0) a[i] /= 3;
  }
  for (int i = 0; i < n - 1; i++)
    if (a[i] != a[i + 1]) {
      cout << "No\n";
      return 0;
    }
  cout << "Yes\n";
  return 0;
}
