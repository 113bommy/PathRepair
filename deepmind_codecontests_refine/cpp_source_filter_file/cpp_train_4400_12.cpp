#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a[n + 1], b[n + 1];
  int i;
  int j;
  for (i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= n; j++) {
      if (a[i] == j) cout << j << " ";
    }
  }
  return 0;
}
