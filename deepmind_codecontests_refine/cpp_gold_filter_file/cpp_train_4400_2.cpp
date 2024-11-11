#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a[101], i;
  cin >> n;
  for (i = 0; i < n; i++) cin >> a[i];
  for (int j = 1; j <= n; j++) {
    for (i = 0; i < n; i++) {
      if (a[i] == j) cout << i + 1 << " ";
    }
  }
  return 0;
}
