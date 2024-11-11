#include <bits/stdc++.h>
using namespace std;
int ma[200][200];
int main() {
  int n, su = 0, N, co;
  cin >> n;
  co = (n - 1) / 2;
  N = n - 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> ma[i][j];
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i == j) {
        su += ma[i][j];
      }
      if (j == co) {
        su += ma[i][j];
      }
      if (i == co) {
        su += ma[i][j];
      }
      if (j == N) {
        su += ma[i][j];
        N--;
      }
    }
  }
  cout << su - 3 * (ma[co][co]);
}
