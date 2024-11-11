#include <bits/stdc++.h>
using namespace std;
int n, a[1050];
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  int tens = a[0];
  set<int> answer;
  for (int rem = 0; rem < 10000; rem++) {
    double fuel = tens * 10 + static_cast<double>(rem) / 1000;
    double addend = fuel;
    bool isValid = true;
    for (int i = 0; isValid and i < n; i++) {
      fuel -= (a[i] - (i == 0 ? 0 : a[i - 1])) * 10;
      if (fuel < 0 or fuel >= 10 - 1e-6) {
        isValid = false;
      }
      fuel += addend;
    }
    if (isValid) {
      answer.insert(static_cast<int>(fuel) / 10 + a[n - 1]);
    }
  }
  if (answer.size() > 1)
    cout << "not unique" << endl;
  else
    cout << "unique" << endl << *answer.begin() << endl;
  return 0;
}
