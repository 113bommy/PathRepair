#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x, even = 0, odd = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x;
    if (x % 2 == 0)
      even++;
    else
      odd++;
  }
  if (odd % 2 == 0)
    cout << even << endl;
  else
    cout << odd << endl;
  return 0;
}
