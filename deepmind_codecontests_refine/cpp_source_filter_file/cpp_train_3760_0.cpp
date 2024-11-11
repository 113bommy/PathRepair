#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int L = 0, R = 1000000000;
  cout << L << ' ' << 1 << endl;
  string base;
  cin >> base;
  for (int i = 2; i <= n; ++i) {
    int M = (L + R) >> 1;
    cout << M << " " << 1 << endl;
    fflush(stdout);
    string ss;
    cin >> ss;
    if (ss == base)
      L = M;
    else
      R = M;
  }
  cout << L << " 0 " << R << "2" << endl;
  fflush(stdout);
  return 0;
}
