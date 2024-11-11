#include <bits/stdc++.h>
using namespace std;
int main() {
  int hashz[300];
  int p, n;
  cin >> p >> n;
  for (int i = 0; i < 300; i++) hashz[i] = 0;
  int tmp, loz = -1;
  bool lozf = false;
  for (int i = 0; i < n; i++) {
    cin >> tmp;
    if (hashz[tmp % p] && !lozf)
      loz = i + 1, lozf = true;
    else
      hashz[tmp % p] = true;
  }
  cout << loz << "\n";
  return 0;
}
