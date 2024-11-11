#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i;
  cin >> n;
  int a[10000];
  for (i = 0; i < n; i++) {
    cin >> a[i];
    if ((a[i] % 2) == 0) {
      a[i]--;
    }
    cout << a[i];
  }
  return 0;
}
