#include <bits/stdc++.h>
using namespace std;
int sum = 0;
int main() {
  for (int i = 0, t; i < 5; i++) {
    cin >> t;
    sum += t;
  }
  if (sum % 5 && sum != 0)
    cout << -1;
  else
    cout << sum / 5;
  return 0;
}
