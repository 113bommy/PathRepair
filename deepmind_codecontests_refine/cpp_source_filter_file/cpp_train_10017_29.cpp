#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int numb, odd = 0;
  for (int i = 0; i < n; i++) {
    cin >> numb;
    if (numb % 2 == 1) odd++;
  }
  if (odd % 2 == 1)
    cout << 1;
  else
    cout << n - odd;
}
