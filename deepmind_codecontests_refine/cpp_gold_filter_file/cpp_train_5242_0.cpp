#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int i;
  for (i = 1; (i * i + 1) / 2 < n; i += 2)
    ;
  if (n == 3)
    cout << 5 << "\n";
  else if (n == 2)
    cout << 3 << "\n";
  else
    cout << i << "\n";
  return 0;
}
