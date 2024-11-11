#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x, sum = 0;
  cin >> n >> x;
  for (int i = 0; i < n; i++) {
    int q;
    cin >> q;
    sum += q;
  }
  sum = abs(sum);
  int ans = sum / x;
  if (sum % x != 0) {
    ans++;
  }
  cout << ans << endl;
}
