#include <bits/stdc++.h>
using namespace std;
int main() {
  int a[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  int m, d;
  cin >> m >> d;
  cout << int(ceil((a[m - 1] + d - 1) / 7.0));
  return 0;
}
