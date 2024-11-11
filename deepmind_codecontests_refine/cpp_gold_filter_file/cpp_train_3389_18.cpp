#include <bits/stdc++.h>
using namespace std;
char a;
int main(void) {
  int n, m;
  cin >> n >> m;
  bool k = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> a;
      if (a != 'B' && a != 'W' && a != 'G') {
        k = 0;
        break;
      }
    }
  }
  if (k == 0)
    cout << "#Color";
  else
    cout << "#Black&White";
  return 0;
}
