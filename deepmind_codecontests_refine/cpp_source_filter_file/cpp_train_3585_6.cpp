#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  char arr[n];
  int x = 0, X = 0;
  for (int q = 0; q < n; q++) {
    cin >> arr[q];
    if (arr[q] == 'x')
      x++;
    else
      X++;
  }
  int toChange = X - x;
  cout << abs(toChange / 2) << "\n";
  for (int q = 0; q < n; q++) {
    if (toChange > 0 && arr[x] == 'X') {
      cout << 'x';
      toChange -= 2;
    } else if (toChange < 0 && arr[x] == 'x') {
      cout << 'X';
      toChange += 2;
    } else {
      cout << arr[q];
    }
  }
  cout << "\n";
  cout.flush();
  return 0;
}
