#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, counter = 0;
  cin >> n >> m;
  for (int a = 0; a <= n; a++) {
    for (int b = 0; b <= n; b++) {
      if (((a * a) + b) == n) {
        if ((a + (b * b)) == m) counter++;
      }
    }
  }
  cout << counter;
  return 0;
}
