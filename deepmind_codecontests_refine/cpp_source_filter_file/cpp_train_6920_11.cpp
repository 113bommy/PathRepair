#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  int c = 0;
  while (n >= 2 && m >= 2) {
    if (n > m) {
      c++;
      n = n - 2;
      m--;
    } else {
      c++;
      m = m - 2;
      n--;
    }
  }
  if (n == 1 && m == 2) c++;
  if (n == 2 && m == 1) c++;
  cout << c << endl;
  return 0;
}
