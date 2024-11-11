#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  int i, j;
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= n; j++) {
      if (i == j)
        cout << k << " ";
      else
        cout << 0 << " ";
    }
    cout << endl;
  }
  return 0;
}
