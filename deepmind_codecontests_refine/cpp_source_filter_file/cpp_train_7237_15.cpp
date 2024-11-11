#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a;
  cin >> n >> a;
  int ans;
  if (a % 2) {
    ans = ans / 2 + 1;
  } else {
    ans = n / 2 - a / 2 + 1;
  }
  cout << ans << endl;
  return 0;
}
