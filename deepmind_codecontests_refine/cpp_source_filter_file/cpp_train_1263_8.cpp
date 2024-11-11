#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, n;
  cin >> t >> n;
  int x, odd = 0;
  for (int i = 0; i < n; i++) {
    cin >> x;
    if (i == 0 && (x % 2) == 1)
      odd++;
    else if ((t * x) % 2)
      odd++;
  }
  if (odd % 2 == 0)
    cout << "even";
  else
    cout << "odd";
  return 0;
}
