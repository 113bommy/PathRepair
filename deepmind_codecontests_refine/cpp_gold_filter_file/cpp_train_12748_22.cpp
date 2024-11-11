#include <bits/stdc++.h>
using namespace std;
const double EPS = 1E-8;
const int INF = (int)1E+9;
int main() {
  int n;
  int res = 1;
  cin >> n;
  for (int i = 1; i < n; i++) {
    res += i;
    res = (res - 1) % n + 1;
    cout << res << " ";
  }
  return 0;
}
