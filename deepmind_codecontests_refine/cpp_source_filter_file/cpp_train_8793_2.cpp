#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, c = 0;
  cin >> n >> m;
  while (n < m) {
    if (m % 2 == 0) {
      m++;
    } else {
      m /= 2;
    }
    c++;
  }
  cout << c + n - m << endl;
}
