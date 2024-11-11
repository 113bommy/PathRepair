#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i;
  cin >> n;
  int x[n], y[n], z[n], sumi = 0, sumy = 0, sumz = 0;
  for (i = 0; i < n; i++) {
    cin >> x[i] >> y[i] >> z[i];
  }
  for (i = 0; i < n; i++) {
    sumi = sumi + x[i];
    sumy = sumy + y[i];
    sumz = sumz + z[i];
  }
  if (sumi == 0 && sumy == 0 && sumz == 0)
    cout << "yes";
  else
    cout << "no";
  return 0;
}
