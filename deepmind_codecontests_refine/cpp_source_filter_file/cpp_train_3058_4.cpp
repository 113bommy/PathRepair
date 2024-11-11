#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int a[3];
  for (int i = 0; i < 3; i++) {
    cin >> a[i];
  }
  long long int res = a[0];
  if (!(a[0] % a[1])) {
    cout << a[0];
    for (int i = 0; i < a[2]; i++) {
      cout << "0";
    }
  } else {
    long long int temp = res * 10 / a[1];
    if (!((temp + 1) * a[1] - res * 10 < 10)) {
      cout << -1;
    } else {
      res = (temp + 1) * a[1];
      cout << res;
      for (int i = 0; i < a[2] - 1; i++) {
        cout << "0";
      }
    }
  }
  return 0;
}
