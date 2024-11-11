#include <bits/stdc++.h>
using namespace std;
void solve(long double d) {
  long double D = sqrt(d * (d - 4));
  long double a = (d - D) / 2;
  long double b = (d + D) / 2;
  cout << "Y " << setprecision(15) << b << " " << setprecision(15) << a << endl;
}
int main() {
  int t;
  cin >> t;
  long double arr[t];
  for (int i = 0; i < t; i++) {
    cin >> arr[i];
    if (arr[i] == 0)
      cout << "Y 0.000000000 0.000000000" << endl;
    else if (arr[i] < 4)
      cout << "N" << endl;
    else
      solve(arr[i]);
  }
  return 0;
}
