#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, i, j, fl = 0;
  char A[50][50];
  int R[50] = {0}, C[50] = {0};
  cin >> n >> m;
  i = 0;
  while (i < n) {
    scanf("%s", &A[i]);
    i++;
  }
  i = 0;
  while (i < n) {
    if (R[i] == 0) {
      R[i] = 1;
      j = i + 1;
      while (j < n) {
        if (strcmp(A[i], A[j]) == 0) R[j] = 1;
        j++;
      }
      j = 0;
      while (j < m) {
        if (A[i][j] == '#' && C[j] == 0)
          C[j] = 1;
        else if (A[i][j] == '#') {
          fl = 1;
          break;
        }
        j++;
      }
    }
    if (fl == 1) break;
    i++;
  }
  if (fl == 0)
    cout << "Yes";
  else
    cout << "No";
  return 0;
}
