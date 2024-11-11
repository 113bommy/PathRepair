#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  long long int array[n];
  for (int i = 0; i < n; i++) {
    cin >> array[i];
  }
  for (int i = 0; i < n; i++) {
    while (array[i] % 2 == 0) {
      array[i] = array[i] / 2;
    }
    while (array[i] % 3 == 0) {
      array[i] = array[i] / 3;
    }
  }
  for (int i = 1; i < n; i++) {
    if (array[i] != array[n - 1]) {
      cout << "No";
      return 0;
    }
  }
  cout << "Yes";
  return 0;
}
