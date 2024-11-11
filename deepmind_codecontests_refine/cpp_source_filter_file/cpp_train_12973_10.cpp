#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, finalans = 0;
  cin >> n;
  int ans = sqrt(n);
  int remaining = n - ans * ans;
  int fullrem = remaining / ans;
  int remainderrem = remaining % n;
  if (remainderrem == 0)
    finalans = 0;
  else if (remainderrem == 1)
    finalans = 2;
  else
    finalans = 2;
  finalans += 2 * (ans + ans) + 2 * (fullrem);
  cout << finalans;
  return 0;
}
