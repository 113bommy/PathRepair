#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  if (n > 34) {
    cout << -1;
    return 0;
  }
  string ans(n / 2, '8');
  if (n % 2) {
    ans += '4';
  }
  cout << ans;
}
