#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x, a[30001];
  cin >> n >> x;
  for (int i = 1; i < n; i++) {
    cin >> a[i];
  }
  int i = 1;
  while (i < n) {
    i += a[i];
    if (a[i] + i == x) {
      cout << "YES";
      return 0;
    }
  }
  cout << "NO";
  return 0;
}
