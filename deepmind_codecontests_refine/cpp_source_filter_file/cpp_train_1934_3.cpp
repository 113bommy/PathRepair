#include <bits/stdc++.h>
using namespace std;
int calculate() {
  int n;
  cin >> n;
  if (n == 2) return 2;
  unsigned long long dif = 2 * (ceil(pow(2, n / 2)) - 1);
  return dif;
}
int main() {
  int n;
  cin >> n;
  cout << n / 2 << endl;
  if (n % 2) {
    for (int i = 0; i < n / 2 - 1; ++i) cout << '2 ';
    cout << '3' << endl;
  } else {
    for (int i = 0; i < n / 2; ++i) cout << '2 ';
  }
  return 0;
}
