#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, m, i, j, f = 0;
  char str[200][200];
  cin >> n >> m;
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      cin >> str[i][j];
      if (str[i][j] == 'C' || str[i][j] == 'M' || str[i][j] == 'Y') f++;
    }
  }
  if (f > 0)
    cout << "#Color";
  else
    cout << "Black&White";
  return 0;
}
