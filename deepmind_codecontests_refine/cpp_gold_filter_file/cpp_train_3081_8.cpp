#include <bits/stdc++.h>
using namespace std;
int main() {
  char mat[9][9];
  int arr[17];
  for (int i = 1; i <= 8; i++)
    for (int j = 1; j <= 8; j++) cin >> mat[i][j];
  for (int i = 1; i <= 8; i++) {
    int h = 0, c = 0;
    for (int j = 1; j <= 8; j++) {
      if (mat[i][j] == 'B') h++;
      if (mat[j][i] == 'B') c++;
    }
    arr[i] = c;
    arr[17 - i] = h;
  }
  int sum = 0;
  for (int i = 1; i <= 17; i++)
    if (arr[i] == 8) sum++;
  if (sum == 16)
    cout << 8;
  else
    cout << sum;
}
