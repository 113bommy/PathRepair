#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int ans = 0;
  while (n) {
    ans += (n % 7 == 1);
    n /= 10;
  }
  cout << ans << endl;
}
