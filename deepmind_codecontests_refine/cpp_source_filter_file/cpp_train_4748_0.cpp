#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, a, b;
  long long c;
  long long ct = 0;
  cin >> n >> a >> b;
  for (int i = 0; i < n; i++) {
    long long d;
    cin >> d;
    if (d == 1) {
      if (a > 0) {
        a--;
      } else if (b > 0) {
        b--;
        c++;
      } else if (c > 0) {
        c--;
      } else
        ct++;
    } else {
      if (b > 0) {
        b--;
      } else
        ct += 2;
    }
  }
  cout << ct << endl;
  return 0;
}
