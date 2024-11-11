#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int i, j, k, l, m, n;
  cin >> n;
  string s;
  if (n == 1 || n == 2) {
    cout << -1;
    return 0;
  } else if (n == 3) {
    cout << 210;
    return 0;
  }
  long long int a[7] = {0, 200, 110, 50, 80, 170, 20};
  n--;
  for (i = 1; i <= 6; i++) {
    if ((n - i) % 6 == 0) {
      cout << 1;
      for (j = 1; j <= n - 3; j++) {
        cout << 0;
      }
      if (i == 1) {
        cout << "200";
      } else if (i == 2) {
        cout << "110";
      } else if (i == 3) {
        cout << "050";
      } else if (i == 4) {
        cout << "080";
      } else if (i == 5) {
        cout << "170";
      } else if (i == 6) {
        cout << "020";
      }
      return 0;
    }
  }
  cout << -1;
}
