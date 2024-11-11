#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, b, ans = 0;
  cin >> n >> b;
  if (n % b)
    ans = n + n / (b - 1);
  else
    ans = -1 + n + n / (b - 1);
  cout << ans;
  return 0;
}
