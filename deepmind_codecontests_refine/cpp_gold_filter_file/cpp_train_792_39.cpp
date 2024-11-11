#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  string str[n];
  for (int i = 0; i < n; i++) cin >> str[i];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      int flag = 0;
      for (int a = 0; a < n; a++)
        if (a != i && str[i][j] == str[a][j]) flag = 1;
      for (int a = 0; a < m; a++)
        if (a != j && str[i][j] == str[i][a]) flag = 1;
      if (flag == 0) cout << str[i][j];
    }
}
