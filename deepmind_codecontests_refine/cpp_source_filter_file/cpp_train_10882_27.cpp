#include <bits/stdc++.h>
using namespace std;
int x[1000000], y[1000000];
int main() {
  int n, m;
  cin >> n >> m;
  int a, b;
  a = b = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a;
    if (a < 99999) x[a] = 1;
  }
  int i = 1;
  while (m - i >= 0) {
    if (!x[i]) {
      y[b] = i;
      b++;
      m -= i;
    }
    i++;
  }
  cout << b << endl;
  for (int j = 0; j < b; j++) cout << y[j] << " ";
}
