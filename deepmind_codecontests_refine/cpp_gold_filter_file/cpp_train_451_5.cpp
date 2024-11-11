#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, temp, l = 0, r = 0;
  cin >> t;
  for (int i = 0; i < t; i++) {
    cin >> temp;
    if (temp == 1) l++;
    cin >> temp;
    if (temp == 1) r++;
  }
  l = min(l, t - l);
  r = min(r, t - r);
  cout << l + r;
}
