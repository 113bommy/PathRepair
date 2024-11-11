#include <bits/stdc++.h>
using namespace std;
int s(int n) {
  int ans = 0;
  while (n) {
    ans += n % 10;
    n /= 10;
  }
  return ans;
}
int main() {
  int k;
  cin >> k;
  int inte = 0;
  while (k) {
    inte++;
    if (s(inte) == 10) k--;
  }
  cout << inte << "\n";
  return 0;
}
