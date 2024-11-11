#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, l, r;
  cin >> n >> l >> r;
  long long int min = 0, max = 0;
  l--;
  for (int i = 0; i < n; i++) {
    if (l != 0) {
      min += pow(2, i);
      l--;
    } else {
      min += 1;
    }
  }
  int flag = 0;
  for (int i = 0; i < n; i++) {
    if (r != 0) {
      max += pow(2, i);
      r--;
      flag = pow(2, i);
    } else {
      max += flag;
    }
  }
  cout << min << " " << max;
}
