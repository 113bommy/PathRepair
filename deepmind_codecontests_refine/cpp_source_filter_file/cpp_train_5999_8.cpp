#include <bits/stdc++.h>
using namespace std;
int main() {
  int k;
  cin >> k;
  long long ans, temp = 0, zero = 0;
  for (int i = 0; i < k; i++) {
    cin >> temp;
    ans = max(temp - 25, zero);
  }
  cout << ans;
  return 0;
}
