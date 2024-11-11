#include <bits/stdc++.h>
using namespace std;
int a[100010], dp[100010], prime[100010], l[100010];
vector<int> pd[100010];
void pf() {
  int n = 1e5 + 10;
  for (int i = 1; i <= n; i++) prime[i] = 1;
  for (int i = 2; i <= sqrt(n) + 1; i++) {
    if (prime[i] == 1) {
      for (int j = i; j <= n; j += i) {
        if ((j % i) == 0) {
          prime[j] = 0;
          pd[j].push_back(i);
        }
      }
    }
  }
}
void solve(int n) {
  pf();
  int mx, res = 0;
  for (int i = 1; i <= n; i++) {
    mx = 0;
    for (int p : pd[a[i]]) mx = max(mx, l[p]);
    dp[i] = mx + 1;
    for (int p : pd[a[i]]) l[p] = max(l[p], dp[i]);
  }
  for (int i = 1; i <= n; i++) res = max(res, dp[i]);
  cout << res << endl;
}
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  solve(n);
}
