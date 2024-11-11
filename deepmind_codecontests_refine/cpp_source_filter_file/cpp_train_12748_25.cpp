#include <bits/stdc++.h>
using namespace std;
const double EPS = 1E-8;
const int INF = (int)1E+9;
int main() {
  int k;
  int res = 1;
  cin >> k;
  for (int i = 1; i < 100; i++) {
    res += i;
    res = (res - 1) % k + 1;
    cout << res << " ";
  }
  return 0;
}
