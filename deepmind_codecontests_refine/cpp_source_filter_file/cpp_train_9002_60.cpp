#include <bits/stdc++.h>
using namespace std;
int arr[105][105];
int main() {
  for (int i = 0; i < 105; i++) {
    for (int j = 0; j < 105; j++) {
      arr[i][j] = 0;
    }
  }
  int n;
  cin >> n;
  while (n--) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    for (int i = x1; i <= x2; i++) {
      for (int j = y1; j <= y2; j++) {
        arr[100 - i][j] += 1;
      }
    }
  }
  int sum = 0;
  for (int i = 1; i <= 100; i++) {
    for (int j = 1; j < 100; j++) {
      sum += arr[i][j];
    }
  }
  cout << sum << endl;
}
