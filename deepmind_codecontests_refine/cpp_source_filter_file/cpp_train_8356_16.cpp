#include <bits/stdc++.h>
using namespace std;
using ll = long long;
bool dp[1001];
int ans3 = -1, ans5 = -1, ans7 = -1;
void go(int n, int a3, int a5, int a7) {
  if (dp[n]) return;
  dp[n] = true;
  if (n == 0) {
    ans3 = a3;
    ans5 = a5;
    ans7 = a7;
    return;
  }
  if (n - 3 >= 0) go(n - 3, a3 + 1, a5, a7);
  if (n - 5 >= 0) go(n - 5, a3, a5 + 1, a7);
  if (n - 7 >= 0) go(n - 7, a3, a5, a7 + 1);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
      dp[i] = false;
    }
    ans3 = -1, ans5 = -1, ans7 = -1;
    go(n, 0, 0, 0);
    if (ans3 == -1) {
      cout << "-1\n";
    } else {
      cout << ans3 << " " << ans5 << " " << ans7 << "\n";
    }
  }
  return 0;
}
