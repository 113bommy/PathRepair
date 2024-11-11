#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, sum = 0, large;
  cin >> n;
  string t;
  for (i = 0; i < n; i++) {
    cin >> t[i];
  }
  large = t[0];
  for (i = 1; i < n; i++) {
    if (large < t[i]) large = t[i];
  }
  for (i = 0; i < n; i++) {
    sum += large - t[i];
  }
  cout << sum << endl;
  return 0;
}
