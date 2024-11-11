#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, tmp;
  cin >> n >> m;
  bool flag = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      scanf("%d", &tmp);
      if ((i == 1 || i == n || j == 1 || j == m) && tmp) {
        flag = 1;
      }
    }
  }
  if (flag)
    cout << "2" << endl;
  else
    cout << "4" << endl;
  return 0;
}
