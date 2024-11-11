#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  int d[21] = {0}, c = 0, i, k, m;
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> k;
    d[k + 10]++;
  }
  for (i = 0; i < 10; i++) {
    c += (d[i] * d[20 - i]);
  }
  c += ((d[10] * (d[10] - 1)) / 2);
  cout << c;
}
