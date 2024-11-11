#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, odds = 0, evens = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int temp;
    cin >> temp;
    if (temp % 2 == 0)
      evens++;
    else
      odds++;
  }
  int ans = 0, minval = min(evens, odds);
  ans = ans + minval;
  minval = odds - minval;
  ans = ans + minval / 2;
  cout << ans;
}
