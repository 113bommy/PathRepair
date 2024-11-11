#include <bits/stdc++.h>
using namespace std;
int solve(int a, int b, int ans) {
  if (a < b) swap(a, b);
  if (a <= 1) return ans;
  return solve(a - 2, b + 1, ans + 1);
}
int main() {
  int a, b;
  while (cin >> a >> b) {
    int ans = max(0, solve(a, b, 0) - 1);
    cout << ans << endl;
  }
}
