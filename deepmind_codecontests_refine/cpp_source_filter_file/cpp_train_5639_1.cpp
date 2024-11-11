#include <bits/stdc++.h>
using namespace std;
int main() {
  int n = 0, i = 0, o = 0, a = 0, m = 0, temp;
  cin >> n;
  int x[n];
  for (int p = 1; p <= n; p++) {
    cin >> o;
    cin >> i;
    a = a + i;
    a = a - o;
    x[m] = a;
    m++;
    i = 0;
    o = 0;
  }
  for (int j = 0; j < n; j++) {
    if (x[j] > temp) {
      temp = x[j];
    }
  }
  cout << temp;
  return 0;
}
