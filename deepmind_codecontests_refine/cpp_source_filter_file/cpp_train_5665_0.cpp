#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int u_half[n], l_half[n];
  for (int i = 0; i < n; i++) {
    cin >> u_half[i] >> l_half[i];
  }
  int sum = 0, sum1 = 0;
  bool b = false;
  for (int i = 0; i < n; i++) {
    if ((u_half[i] + l_half[i]) % 2 != 0) b = true;
    sum = sum + u_half[i];
    sum1 = sum1 + l_half[i];
  }
  if (sum % 2 == 0 and sum1 % 2 == 0)
    cout << 0 << endl;
  else if ((sum % 2 == 0 and sum1 % 2 != 0) or (sum % 2 != 0 and sum1 % 2 == 0))
    cout << -1 << endl;
  else if (b = true)
    cout << 1 << endl;
  else
    cout << -1 << endl;
}
