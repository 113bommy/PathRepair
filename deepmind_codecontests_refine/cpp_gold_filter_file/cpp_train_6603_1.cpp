#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x = 0;
  cin >> n;
  char s1, s2, a[305][305];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> a[i][j];
      s1 = a[0][0];
      s2 = a[0][1];
      if ((i == j || i == n - 1 - j) && (a[i][j] != s1))
        x = 1;
      else if (!(i == j || i == n - 1 - j) && (a[i][j] != s2))
        x = 1;
    }
  }
  if (s1 == s2) {
    cout << "NO";
    return 0;
  }
  if (x == 0)
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
