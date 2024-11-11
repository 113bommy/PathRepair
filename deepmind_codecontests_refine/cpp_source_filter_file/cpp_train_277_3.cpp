#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, x, m, c = 0;
  int d[1000010] = {0};
  cin >> n >> k;
  m = 2000000;
  for (int i = 0; i < n; i++) {
    cin >> x;
    d[x]++;
  }
  for (int i = 1000000; i >= 1; i--)
    if (d[i] > 0) {
      if (m > i + k) c += d[i];
      m = i;
    }
  cout << c;
}
