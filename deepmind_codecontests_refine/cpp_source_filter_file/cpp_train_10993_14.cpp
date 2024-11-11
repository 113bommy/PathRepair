#include <bits/stdc++.h>
using namespace std;
int main() {
  string aa[5] = {"Howard", "Rajesh", "penny", "Leonard", "Sheldon"};
  int n, x = 0, i;
  cin >> n;
  int a[50];
  for (i = 0; x <= pow(10, 9); ++i) {
    x = 5 * (pow(2, i + 1) - 1);
    a[i] = x;
    if (a[i] > n) {
      break;
    }
  }
  x = (a[i] - n) / (pow(2, i));
  cout << aa[x];
  return 0;
}
