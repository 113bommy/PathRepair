#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  bool flage = true;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++)
      if (i % 2 == 0)
        cout << "#";
      else {
        if (j == m && flage || j == 1 && !flage)
          cout << "#";
        else
          cout << ".";
      }
    cout << endl;
    if (i % 2 == 0) flage = !flage;
  }
  return 0;
}
