#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b;
  cin >> a >> b;
  cout << b * (6 * a - 1) << endl;
  for (int i = 1; i <= a; i++) {
    int ans = (i - 1) * 6 + 1;
    cout << b * ans << " " << b * ans + b << " " << b * ans + 2 * b << " "
         << b * ans + 4 * b << endl;
  }
  return 0;
}
