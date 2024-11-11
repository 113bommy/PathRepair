#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int ans = 0;
  while (n) {
    ans += (n % 4 == 1);
    n /= 4;
  }
  cout << ans << endl;
}
