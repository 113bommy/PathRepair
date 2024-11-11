#include <bits/stdc++.h>
using namespace std;
int ans[2000000], n;
int complement(int n) {
  int ans = 0, p = 1;
  while (n) {
    ans = ans + (1 - n % 2) * p;
    n /= 2;
    p *= 2;
  }
  return ans;
}
int main() {
  ios::sync_with_stdio(0);
  cin >> n;
  for (int i = n; i > -1; i--)
    if (!ans[i]) {
      ans[i] = complement(i);
      ans[complement(i)] = i;
    }
  cout << n * (n + 1) << endl;
  for (int i = 0; i <= n; i++) cout << ans[i] << " ";
  cout << endl;
}
