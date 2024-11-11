#include <bits/stdc++.h>
using namespace std;
int mas[111];
int main() {
  int n, r = 1;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> mas[i];
  }
  if (mas[0] % 2 && mas[n - 1] % 2 && n % 2) {
    cout << "Yes";
  } else {
    cout << "No";
  }
  return 0;
}
