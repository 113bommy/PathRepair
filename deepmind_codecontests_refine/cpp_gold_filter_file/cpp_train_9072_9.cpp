#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int n;
  cin >> n;
  int ans;
  if (n % 2 != 0) {
    int x = (n + 1) / 2;
    cout << x << '\n';
    int r = 1;
    int j = 1;
    for (int i = 1; i <= n; i++) {
      if (i < (n + 1) / 2)
        cout << r << ' ' << i << '\n';
      else {
        cout << x << ' ' << j << '\n';
        j++;
      }
    }
  } else {
    int x = (n / 2) + 1;
    cout << x << '\n';
    int r = 1;
    int j = 1;
    for (int i = 1; i <= n; i++) {
      if (i <= (n / 2))
        cout << r << ' ' << i << '\n';
      else {
        cout << x << ' ' << j << '\n';
        j++;
      }
    }
  }
  return 0;
}
