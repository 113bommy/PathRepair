#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, max = 0, m, l = 0, o;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> m;
    o = l - m;
    if (o > max) max = o;
    l = m;
  }
  if (max <= 0) {
    max = 0;
    k = 0;
  }
  cout << (max - k);
  return 0;
}
