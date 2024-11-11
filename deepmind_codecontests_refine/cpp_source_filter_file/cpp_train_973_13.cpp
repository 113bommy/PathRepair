#include <bits/stdc++.h>
using namespace std;
string in;
int n;
int matrix[101][101];
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j) scanf("%d", &matrix[i][j]);
  for (int i = 0; i < n; ++i) {
    int number = 0;
    for (int j = 0; j < n; ++j) {
      if (matrix[i][j] > 0) number |= matrix[i][j];
    }
    printf("%d ", number - 1);
  }
  return 0;
}
