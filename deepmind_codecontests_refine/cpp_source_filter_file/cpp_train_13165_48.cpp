#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1001;
int main() {
  int a[10];
  a[0] = 2;
  a[1] = 6;
  a[2] = 2;
  a[3] = 3;
  a[4] = 3;
  a[5] = 4;
  a[6] = 2;
  a[7] = 5;
  a[8] = 1;
  a[9] = 2;
  int o = 1;
  char c;
  while (cin >> c) o *= a[c - '0'];
  cout << o << '\n';
}
