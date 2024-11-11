#include <bits/stdc++.h>
using namespace std;
int main() {
  int crime, n, sum = 0, x;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> crime;
    if (crime < 0)
      sum += crime;
    else {
      if (sum > 0)
        sum--;
      else
        x++;
    }
  }
  cout << x;
}
