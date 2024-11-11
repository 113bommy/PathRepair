#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a, i, j, k, max(0), tempMax;
  cin >> n;
  vector<int> numbers, temp;
  for (i = 0; i < n; i++) {
    cin >> a;
    numbers.push_back(a);
  }
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      temp = numbers;
      for (k = i; k <= j; k++) temp[k] = temp[k] ? 0 : 1;
      tempMax = 0;
      for (k = 0; k < n; k++) tempMax += temp[k];
      if (tempMax > max) max = tempMax;
    }
  }
  cout << max << endl;
  return 0;
}
