#include <bits/stdc++.h>
using namespace std;
long long a[100010];
int main() {
  string s;
  long long ans = 0, k1 = 0, k2 = 0, k3 = 0, i, j, n;
  cin >> n >> s;
  for (i = 0; i < s.size(); i++) {
    if (s[i] == 'B')
      k1++;
    else if (s[i] == 'G')
      k2++;
    else
      k3++;
  }
  if (k1 > 0 && k2 > 0 && k3 > 0) {
    cout << "BGR";
    return 0;
  }
  if ((k1 > 0 && k2 == 0 && k3 == 0) || (k2 == 1 && k3 == 1)) {
    cout << "B";
    return 0;
  }
  if ((k1 == 0 && k2 > 0 && k3 == 0) || (k1 == 1 && k3 == 1)) {
    cout << "G";
    return 0;
  }
  if ((k1 == 0 && k2 == 0 && k3 > 0) || (k2 == 1 && k1 == 1)) {
    cout << "R";
    return 0;
  }
  if (k1 == 1 && k2 >= 2) {
    cout << "BR";
    return 0;
  }
  if (k2 == 1 && k3 >= 2) {
    cout << "BG";
    return 0;
  }
  if (k2 == 1 && k1 >= 2) {
    cout << "GR";
    return 0;
  }
  if (k1 == 1 && k3 >= 2) {
    cout << "BG";
    return 0;
  }
  if (k3 == 1 && k1 >= 2) {
    cout << "GR";
    return 0;
  }
  if (k3 == 1 && k2 >= 2) {
    cout << "BR";
    return 0;
  }
  cout << "BGR";
}
