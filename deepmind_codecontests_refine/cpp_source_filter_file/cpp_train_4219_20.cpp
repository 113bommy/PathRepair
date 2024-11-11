#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, i, mat[110], cont = 0;
  cin >> a >> b;
  for (i = 1; i <= a; i++) cin >> mat[i];
  sort(mat, mat + a);
  for (i = a; i > 0; i--) {
    if (b <= 0) {
      break;
    }
    b -= mat[i];
    cont++;
  }
  cout << cont << endl;
  return 0;
}
