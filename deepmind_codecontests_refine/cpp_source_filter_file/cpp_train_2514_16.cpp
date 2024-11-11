#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, i;
  cin >> n;
  string s;
  cin >> s;
  long long int a[n + 1], b[10];
  for (i = 0; i < n; i++) {
    a[i + 1] = s[i] - 48;
  }
  for (i = 1; i <= 9; i++) {
    cin >> b[i];
  }
  long long int j = 0, z = 0;
  for (i = 1; i <= n; i++) {
    if (b[a[i]] > a[i]) {
      a[i] = b[a[i]];
      z = 1;
      for (j = i + 1; j <= n; j++) {
        if (b[a[j]] > a[j])
          a[j] = b[a[j]];
        else
          break;
      }
    }
    if (z == 1) break;
  }
  for (i = 1; i <= n; i++) cout << a[i];
}
