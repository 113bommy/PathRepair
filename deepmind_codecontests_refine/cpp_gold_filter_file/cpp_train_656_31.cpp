#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  unsigned long long int ans = 0;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    ans += x * i;
  }
  cout << ans;
  return 0;
}
