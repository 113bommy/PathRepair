#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int i, t, c, sum = 0;
  cin >> t;
  long long int a[t];
  for (i = 0; i < t; i++) {
    cin >> a[i];
  }
  for (i = 0; i < t; i++) {
    sum += a[i];
  }
  if (sum % 2 == 0) {
    cout << sum << endl;
  } else {
    long long int min = a[0];
    for (i = 0; i < t; i++) {
      if (a[i] <= min && a[i] % 2 != 0) {
        min = a[i];
      }
    }
    sum = sum - min;
    cout << sum << endl;
  }
  return 0;
}
