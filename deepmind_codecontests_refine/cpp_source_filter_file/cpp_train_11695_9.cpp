#include <bits/stdc++.h>
using namespace std;
const int N = 1E5 + 2;
int mat[200][200];
bool b[100][100];
int main() {
  int n;
  cin >> n;
  memset(b, true, sizeof(b));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) cin >> mat[i][j];
  }
  long long sum = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i == j || i == (n - 1) / 2 || j == (n - 1) / 2) {
        sum += mat[i][j];
        b[i][j] = false;
      }
    }
  }
  for (int i = n - 1, j = 0; i >= 0, j < n; i--, j++) {
    if (b[j][i] == false)
      continue;
    else
      sum += mat[j][i];
  }
  cout << sum << endl;
  return 0;
}
