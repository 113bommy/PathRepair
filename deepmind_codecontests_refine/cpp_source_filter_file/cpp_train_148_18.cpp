#include <bits/stdc++.h>
using namespace std;
int a, sum;
int main() {
  for (int i = 0; i < 5; i++) {
    cin >> a;
    sum += a;
  }
  if (sum % 5)
    cout << -1 << '\n';
  else
    cout << sum / 5 << '\n';
  return 0;
}
