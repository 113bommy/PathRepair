#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, a;
  cin >> n >> a;
  long long int arra[n + 1];
  long long int sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> arra[i];
    sum = sum + arra[i];
  }
  if (sum >= a) {
    long long int val = 0;
    sort(arra, arra + n);
    for (int i = 1; i < n; i++) {
      val = val + (arra[i] - arra[0]);
    }
    if (val >= a) {
      cout << a << endl;
    } else {
      long long int baki = a - val;
      long long int tota = baki / n;
      if (baki % n != 0) {
        tota = tota + 1;
      }
      cout << arra[0] - (tota) << endl;
    }
  } else {
    cout << "-1" << endl;
  }
  return 0;
}
