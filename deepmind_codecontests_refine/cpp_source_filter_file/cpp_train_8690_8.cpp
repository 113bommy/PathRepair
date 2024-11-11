#include <bits/stdc++.h>
#pragma GCC optimize("O2")
using namespace std;
int power(int x, unsigned int y) {
  int res = 1;
  while (y > 0) {
    if (y & 1) res = res * x;
    y = y >> 1;
    x = x * x;
  }
  return res;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  int i = 1;
  int j = n;
  while (i <= j / 2) {
    cout << i << " " << j << " ";
    i++;
    j--;
  }
  if (n & 1) {
    cout << ceil(n / 2.0);
  }
  return 0;
}
