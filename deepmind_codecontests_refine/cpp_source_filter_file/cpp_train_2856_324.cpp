#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:65777216")
const int INF = 1000000000;
const long long MOD = 1000000000 + 7;
using namespace std;
int main() {
  bool a[16];
  a[0] = 1;
  a[1] = 0;
  a[2] = 1;
  a[3] = 0;
  a[4] = 0;
  a[5] = 1;
  a[6] = 0;
  a[7] = 1;
  a[8] = 1;
  a[9] = 1;
  a[10] = 0;
  a[11] = 1;
  a[12] = 1;
  a[13] = 0;
  a[14] = 1;
  a[15] = 0;
  int t;
  cin >> t;
  cout << a[t - 1];
}
