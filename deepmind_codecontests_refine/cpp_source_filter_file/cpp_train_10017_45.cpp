#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a[n];
  int even = 0, odd = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] % 2 == 0) {
      even++;
    } else {
      odd++;
    }
  }
  if (odd % 2 == 0) {
    cout << even << "\n";
  } else {
    cout << 1 << "\n";
  }
  return 0;
}
