#include <bits/stdc++.h>
using namespace std;
bool isPerfectSquare(long double x) {
  long double sr = sqrt(x);
  return ((sr - floor(sr)) == 0);
}
int main() {
  int n, Max = 0;
  long double k;
  cin >> n;
  while (n--) {
    cin >> k;
    if (k > Max && !isPerfectSquare(k)) Max = k;
  }
  cout << Max << endl;
  return 0;
}
