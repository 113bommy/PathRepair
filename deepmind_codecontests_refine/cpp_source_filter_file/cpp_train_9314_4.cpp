#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int count = 0, temp = 0, x0, y0, n, i;
  cin >> n >> x0 >> y0;
  int arrx[n], arry[n];
  for (i = 0; i < n; i++) {
    cin >> arrx[i] >> arry[i];
    arrx[i] -= x0;
    arry[i] -= y0;
  }
  double slope[n];
  for (i = 0; i < n; i++) {
    if (arrx[i] == 0)
      temp++;
    else
      slope[i] = (double)arry[i] / arrx[i];
  }
  sort(slope, slope + n - temp);
  if (n - temp != 0) count = 1;
  for (i = 1; i < n - temp; i++) {
    if (slope[i] != slope[i - 1]) {
      count++;
    }
  }
  if (temp != 0) count++;
  cout << count << "\n";
}
