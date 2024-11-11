#include <bits/stdc++.h>
using namespace std;
long long int ans;
long long int k;
void dfs(long long int n, long long int turn) {
  if (n <= 0) {
    return;
  }
  if (n % 2 == 0 && k == 0) {
    if (turn == 1) {
      ans += 1;
      k = 1;
      dfs(n - 1, turn * -1);
    } else if (turn == -1) {
      k = 1;
      dfs(n / 2, turn * -1);
    }
  } else if (n % 2 == 0) {
    if (turn == 1) {
      ans += n / 2;
    }
    dfs(n / 2, turn * -1);
  } else {
    if (turn == 1) {
      ans += 1;
    }
    dfs(n - 1, turn * -1);
  }
}
int32_t main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    k = 0;
    ans = 0;
    if (n == 4) {
      cout << 3 << "\n";
    } else {
      dfs(n, 1);
      cout << ans << "\n";
    }
  }
}
