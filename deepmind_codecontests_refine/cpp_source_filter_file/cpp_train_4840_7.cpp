#include <bits/stdc++.h>
using namespace std;
long long int x, y, z, n, m, i, j;
long long int mat[1000][1000], ans[1000000], mat2[1000000];
int main() {
  cin >> n;
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      cin >> mat[i][j];
      if (mat[i][j] == 1 || mat[i][j] == 3) ans[i] = 1;
    }
    if (ans[i]) x++;
  }
  cout << x << endl;
  for (i = 0; i < n; i++) {
    if (!ans[i]) cout << i + 1 << " ";
  }
  return 0;
}
