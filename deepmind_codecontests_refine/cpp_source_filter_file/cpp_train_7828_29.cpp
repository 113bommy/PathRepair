#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, c = 0, k, v[100] = {0}, i;
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> k;
    v[k]++;
    if (v[k] % 2 == 0) c++;
  }
  cout << c / 4;
  return 0;
}
