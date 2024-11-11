#include <bits/stdc++.h>
using namespace std;
vector<long double> lift;
vector<long double> land;
int n;
long double m;
bool go(long double fuel) {
  for (int i = 0; i < n; i++) {
    if (fuel < 0) {
      return false;
    }
    if (i == 0) {
      long double rem = (m + fuel) / lift[i] * 1.0;
      fuel -= rem;
      continue;
    }
    long double rem = (m + fuel) / land[i] * 1.0;
    fuel -= rem;
    if (fuel < 0) {
      return false;
    }
    rem = (m + fuel) / lift[i] * 1.0;
    fuel -= rem;
    if (fuel < 0) {
      return false;
    }
  }
  long double rem = (m + fuel) / land[0] * 1.0;
  fuel -= rem;
  if (fuel < 0) {
    return false;
  }
  return true;
}
int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    long double a;
    cin >> a;
    lift.push_back(a);
  }
  for (int i = 0; i < n; i++) {
    long double b;
    cin >> b;
    land.push_back(b);
  }
  long double low = 0;
  long double high = 1000000001;
  if (!go(high)) {
    cout << -1 << endl;
    return 0;
  }
  for (int i = 0; i < 1000; i++) {
    long double average = (low + high) / 2.0;
    if (go(average)) {
      high = average;
    } else {
      low = average;
    }
  }
  cout << setprecision(9) << fixed << low << endl;
}
