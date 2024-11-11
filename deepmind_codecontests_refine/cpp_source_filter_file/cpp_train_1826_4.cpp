#include <bits/stdc++.h>
using namespace std;
int main() {
  const int linesMax = 100;
  int arr[5][linesMax];
  int amount, lines;
  cin >> lines >> amount;
  for (int i = 1; i <= lines; i++) {
    arr[0][i] = i * 2 - 1;
    arr[1][i] = lines * 2 + i * 2 - 1;
    arr[2][i] = lines * 2 + i * 2;
    arr[3][i] = i * 2;
  }
  for (int i = 1; i <= lines; i++) {
    if (arr[1][i] < amount) cout << arr[1][i] << " ";
    if (arr[0][i] < amount) cout << arr[0][i] << " ";
    if (arr[2][i] < amount) cout << arr[2][i] << " ";
    if (arr[3][i] < amount) cout << arr[3][i] << " ";
  }
  return 0;
}
