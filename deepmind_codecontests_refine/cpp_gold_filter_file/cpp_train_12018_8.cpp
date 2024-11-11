#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x, k;
  cin >> n;
  int a[1000000] = {0};
  if (n == 1) {
    cin >> x >> k;
    if (x != 0) {
      cout << "NO";
      return 0;
    } else
      cout << "YES";
    return 0;
  }
  for (int i = 1; i <= n; i++) {
    cin >> x >> k;
    if (a[k] < x) {
      cout << "NO";
      return 0;
    }
    if (x == a[k]) a[k]++;
  }
  cout << "YES";
}
