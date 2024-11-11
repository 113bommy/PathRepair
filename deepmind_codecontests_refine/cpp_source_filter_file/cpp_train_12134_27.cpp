#include <bits/stdc++.h>
using namespace std;
int main() {
  unsigned long long last = 0, current, i, counter = 0, maxi = 0, n;
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> current;
    if (i == 0)
      counter = 1;
    else {
      if (current > last)
        counter++;
      else
        counter = 1;
      if (counter > maxi) maxi = counter;
    }
    last = current;
  }
  cout << maxi;
  return 0;
}
