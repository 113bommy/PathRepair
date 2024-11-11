#include <bits/stdc++.h>
using namespace std;
int A[15][15] = {0};
int main() {
  short k;
  cin >> k;
  int a, b;
  a = 0;
  b = 0;
  int temp;
  int x = 0;
  for (int i = 1; i < k; i++) A[0][i] = i + 1;
  for (int i = 1; i < k; i++) A[i][0] = i + 1;
  A[0][0] = 1;
  for (int i = 2, a = 1; i < k; i++, a++)
    for (int j = 2, b = 1; j < k; j++, b++) {
      int res = 0;
      temp = i * j;
      if (temp >= k) {
        x = temp / k;
        res = temp - (x * k);
        res = res + 10 * x;
        temp = res;
      }
      A[a][b] = temp;
    }
  for (int a = 0; a < k - 1; a++) {
    for (int b = 0; b < k - 1; b++) cout << A[a][b] << " ";
    cout << endl;
  }
  return 0;
}
