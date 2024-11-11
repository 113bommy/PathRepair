#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n;
  cin >> n;
  char myMat[n][n];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) cin >> myMat[i][j];
  long long int counter = 0;
  if (n < 3)
    cout << 0 << endl;
  else {
    for (int i = 1; i < n; i++)
      for (int j = 1; j < n; j++)
        if (i - 1 >= 0 && i + 1 < n && j + 1 < n && j - 1 >= 0) {
          if (myMat[i][j] == 'x' && myMat[i - 1][j - 1] == 'x' &&
              myMat[i - 1][j + 1] == 'x' && myMat[i + 1][j - 1] == 'x' &&
              myMat[i + 1][j + 1] == 'x') {
            counter++;
          }
        }
    cout << counter << endl;
  }
  return 0;
}
