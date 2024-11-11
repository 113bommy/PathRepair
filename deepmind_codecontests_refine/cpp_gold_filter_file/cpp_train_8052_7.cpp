#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x;
  cin >> n >> x;
  int a[n], b[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
  }
  int ans = 7 - x;
  for (int i = 0; i < n; i++) {
    if (a[i] == ans || a[i] == x || b[i] == x || b[i] == ans) {
      cout << "NO";
      return 0;
    }
  }
  cout << "YES";
}
