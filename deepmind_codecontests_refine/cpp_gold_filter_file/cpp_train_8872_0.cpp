#include <bits/stdc++.h>
using namespace std;
int helper(int n) {
  if (n == 1 || n == 2) return n;
  int ans = helper(n - 1);
  return ans + 1;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int ans = helper(n);
    cout << ans << endl;
  }
}
