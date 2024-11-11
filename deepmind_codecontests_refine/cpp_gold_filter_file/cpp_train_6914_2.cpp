#include <bits/stdc++.h>
using namespace std;
long long maxm = -1e18;
long long minm = 1e18;
const long double Pi = 3.141592653;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  int a[n];
  string k = "";
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] == 0 && i != n - 1) {
      k += "R";
    } else if (i != n - 1 && a[i] != 0) {
      for (int j = 0; j < a[i] - 1; j++) {
        k += "PRL";
      }
      k += "PR";
    } else if (i == n - 1 && a[i] != 0) {
      for (int j = 0; j < a[i] - 1; j++) {
        k += "PLR";
      }
      k += "P";
    }
  }
  cout << k << endl;
  return 0;
}
