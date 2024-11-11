#include <bits/stdc++.h>
using namespace std;
int main() {
  int b = 0, i, j, n, m;
  cin >> n;
  char a[n + 5];
  for (i = 0; i < n - 1; i++) {
    cin >> a[i];
  }
  for (i = 0; i < n; i++) {
    if ((a[i] == 'U' && a[i + 1] == 'R') || (a[i] == 'R' && a[i + 1] == 'U')) {
      b++;
      i++;
    }
  }
  cout << n - b;
  return 0;
}
