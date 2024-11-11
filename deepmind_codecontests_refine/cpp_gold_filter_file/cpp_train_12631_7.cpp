#include <bits/stdc++.h>
using namespace std;
int n, m, i, j;
char s, a;
int main() {
  cin >> n >> m;
  cin >> s;
  a = s;
  for (i = 2; i <= m; i++) {
    cin >> s;
    if (s != a) {
      cout << "NO";
      return 0;
    }
  }
  for (i = 2; i <= n; i++) {
    cin >> s;
    if (s == a) {
      cout << "NO";
      return 0;
    }
    a = s;
    for (j = 2; j <= m; j++) {
      cin >> s;
      if (s != a) {
        cout << "NO";
        return 0;
      }
    }
  }
  cout << "YES";
  return 0;
}
