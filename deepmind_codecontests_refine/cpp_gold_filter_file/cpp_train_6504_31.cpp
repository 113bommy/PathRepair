#include <bits/stdc++.h>
using namespace std;
int t, n, a[10001], maxi = 0, store, dp[10001], dp2[10001], answer[10001],
                    ans = 0;
void dfs(int h, bool visited[], int count) {
  count = count + a[h - 1];
  dp2[h] = count;
  if (h >= (pow(2, n))) {
    if (count > maxi) {
      maxi = count;
      store = h;
    }
    return;
  }
  if (visited[h] == false) {
    visited[h] = true;
    dfs(2 * h, visited, count);
    dfs(2 * h + 1, visited, count);
  }
}
int dfsm(int m) {
  if (m > t + 1) return 0;
  dp[m] = max(a[2 * m - 1] + dfsm(2 * m), a[2 * m] + dfsm(2 * m + 1));
  return (dp[m]);
}
void answera(int k, int cou) {
  if (k > t + 1) return;
  int you = maxi - dp[k] - dp2[k] - cou;
  ans = ans + you;
  answera(2 * k, cou + you);
  answera(2 * k + 1, cou + you);
}
int main() {
  bool visited[10001];
  cin >> n;
  t = pow(2, n + 1) - 2;
  a[0] = 0;
  for (int i = 1; i <= t; i++) {
    cin >> a[i];
    visited[i] = false;
  }
  dfs(1, visited, 0);
  int x = dfsm(1);
  answera(1, 0);
  cout << ans;
  return 0;
}
