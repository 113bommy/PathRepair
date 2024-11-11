#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  int i = 0, j = n - 1, sum1 = 0, sum2 = 0, turn = 1;
  ;
  while (i <= j) {
    if (a[i] < a[j]) {
      if (turn == 1) {
        sum1 += a[j];
        turn = 2;
      } else {
        sum2 += a[j];
        turn = 1;
      }
      j--;
    } else {
      if (turn == 1) {
        sum1 += a[i];
        turn = 2;
      } else {
        sum2 += a[i];
        turn = 1;
      }
      i++;
    }
  }
  cout << sum1 << " " << sum2 << endl;
  return 0;
}
