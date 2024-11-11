#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t, s, x;
  cin >> t >> s >> x;
  long long mn = 0, mx = 1e9 + 5, mid;
  while (mx - mn != 1) {
    mid = (mx + mn) / 2;
    if (t + mid * s > x) {
      mx = mid;
    } else if (t + mid * s < x) {
      mn = mid;
    } else {
      cout << "YES" << endl;
      return 0;
    }
  }
  if (t + mx * s == x) {
    cout << "YES" << endl;
    return 0;
  } else if (t + mn * s == x) {
    cout << "YES" << endl;
    return 0;
  }
  mn = 1;
  mx = 1e9 + 5;
  while (mx - mn != 1) {
    mid = (mx + mn) / 2;
    if (t + mid * s + 1 > x) {
      mx = mid;
    } else if (t + mid * s + 1 < x) {
      mn = mid;
    } else {
      cout << "YES" << endl;
      return 0;
    }
  }
  if (t + mx * s + 1 == x) {
    cout << "YES" << endl;
    return 0;
  } else if (t + mn * s + 1 == x) {
    cout << "YES" << endl;
    return 0;
  }
  cout << "NO" << endl;
  return 0;
}
