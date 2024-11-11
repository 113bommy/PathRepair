#include <bits/stdc++.h>
using namespace std;
int n, v[105], i, j, maxi = -12312, a;
int main() {
  cin >> n;
  for (i = 1; i <= n; i++) {
    cin >> a;
    if (i == 1) {
      v[i] = a;
    } else
      v[i] = v[i - 1] ^ a;
  }
  for (i = 1; i < n; i++) {
    for (j = n; j > i; j--) {
      if (maxi < (v[i - 1] ^ v[j])) {
        maxi = v[i - 1] ^ v[j];
      }
    }
  }
  cout << maxi << '\n';
  return 0;
}
