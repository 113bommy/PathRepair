#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, k;
  cin >> n >> k;
  long long ct = (n * (n - 1)) / 2;
  if (k > ct)
    cout << "no solution\n";
  else {
    long long x = 0, y = 0;
    long long incr = 1;
    for (int e = 0; e < n; e++) {
      cout << x << " " << y << endl;
      y++;
    }
  }
  return 0;
}
