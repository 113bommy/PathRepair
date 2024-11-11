#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int val = n - 10;
  int ans;
  if (val < 0)
    ans = 0;
  else if (val == 10)
    ans = 15;
  else if (val == 0)
    ans = 0;
  else if (val < 10)
    ans = 4;
  else if (val == 21)
    ans = 4;
  else
    ans = 0;
  cout << ans << endl;
  return 0;
}
