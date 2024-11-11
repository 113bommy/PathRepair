#include <bits/stdc++.h>
using namespace std;
int main() {
  int m, n, p, k = 0, con = 0;
  cin >> p;
  while (k < p) {
    cin >> m >> n;
    if (m < n) {
      con += 1;
    }
    k += 1;
  }
  cout << con;
  return 0;
}
