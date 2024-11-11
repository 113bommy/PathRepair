#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i;
  cin >> n;
  int a[n];
  for (i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (i = 0; i < n; i++) {
    a[i] = a[i] % 2;
    if (a[i] == 1 && i < n) {
      a[i]--;
      a[i + 1]--;
    }
  }
  for (i = 0; i < n; i++) {
    if (a[i] != 0) {
      cout << "NO";
      return 0;
    }
  }
  cout << "YES";
}
