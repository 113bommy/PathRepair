#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a, b, i, j, k, l;
  while (cin >> n) {
    int ar[n - 1];
    for (i = 0; i < n - 1; i++) {
      cin >> ar[i];
    }
    cin >> a >> b;
    l = 0;
    for (i = a; i < b; i++) {
      l += ar[i - 1];
    }
    cout << l << endl;
  }
  return 0;
}
