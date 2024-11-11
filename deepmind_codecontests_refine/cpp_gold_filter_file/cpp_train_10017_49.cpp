#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a[n], i, odd = 0, even = 0;
  for (i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (i = 0; i < n; i++) {
    if (a[i] % 2 == 0) {
      even++;
    } else {
      odd++;
    }
  }
  if (odd % 2 == 0) {
    cout << even << endl;
  } else {
    cout << odd << endl;
  }
}
