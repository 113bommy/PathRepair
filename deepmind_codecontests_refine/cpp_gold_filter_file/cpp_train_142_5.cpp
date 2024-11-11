#include <bits/stdc++.h>
using namespace std;
int main() {
  int arr[100] = {0}, con = 0, d = 0;
  ;
  string x;
  cin >> x;
  for (int i = 0; i < x.size(); i++) {
    if (x[i] == '+') {
      for (int j = 0; j < con; j++) {
        arr[d] += (x[i - j - 1] - 48) * pow(10, j);
      }
      d++;
      con = 0;
    } else
      con++;
  }
  for (int j = 0; j < con; j++) {
    arr[d] += (x[x.size() - j - 1] - 48) * pow(10, j);
  }
  sort(arr, arr + d + 1);
  for (int j = 0; j <= d; j++) {
    if (j == d)
      cout << arr[j];
    else
      cout << arr[j] << "+";
  }
  return 0;
}
