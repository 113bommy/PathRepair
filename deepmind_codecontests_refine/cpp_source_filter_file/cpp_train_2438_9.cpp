#include <bits/stdc++.h>
using namespace std;
int n, m, a, i, j, ans[100];
bool h[100][100];
bool check(int a, int b) {
  for (int i = 0; i < 100; i++)
    if (h[b][i])
      if (!h[a][i]) return false;
  return true;
}
int main() {
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> m;
    while (m) {
      cin >> a;
      h[i][a] = 1;
      m--;
    }
  }
  for (i = 0; i < n; i++) {
    a = 2;
    for (j = 0; j < n; j++)
      if (i != j)
        if (check(i, j)) {
          a = 1;
          break;
        }
    ans[i] = a;
  }
  for (i = 0; i < n; i++) switch (ans[i]) {
      case 1:
        cout << "NO\n";
        break;
      case 2:
        cout << "YES\n";
        break;
    }
  return 0;
}
