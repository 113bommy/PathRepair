#include <bits/stdc++.h>
using namespace std;
int A[51][51], B[51][51], na, ma, nb, mb;
int main() {
  int i, j, x, y;
  char c;
  cin >> na >> ma;
  for (i = 1; i <= na; i++)
    for (j = 1; j <= ma; j++) {
      cin >> c;
      A[i][j] = c - '0';
    }
  cin >> nb >> mb;
  for (i = 1; i <= nb; i++)
    for (j = 1; j <= mb; j++) {
      cin >> c;
      B[i][j] = c - '0';
    }
  int sum = 0, maxsum = -1;
  int ansx, ansy;
  for (x = -nb; x <= nb; x++)
    for (y = -mb; y <= mb; y++) {
      sum = 0;
      for (i = 1; i <= na; i++)
        for (j = 1; j <= nb; j++)
          if ((i + x) <= nb && (j + y) <= mb && (i + x) >= 1 && (j + y) >= 1)
            sum += A[i][j] * B[i + x][j + y];
      if (sum > maxsum) {
        maxsum = sum;
        ansx = x;
        ansy = y;
      }
    }
  cout << ansx << ' ' << ansy << endl;
}
