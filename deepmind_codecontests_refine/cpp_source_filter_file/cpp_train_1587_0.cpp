#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007, MAX = 2000000007, MAXN = 100005;
vector<int> mul[5 * MAXN];
bool visited[5 * MAXN];
int ans[5 * MAXN];
void solve(int n) {
  for (int i = 2; i <= n; i++) {
    visited[i] = false;
    ans[i] = 1;
    for (int j = i + i; j <= n; j++) {
      mul[i].push_back(j);
    }
  }
  int ct = n;
  for (int i = n; i >= 2 && ct > 1; i--) {
    while (!mul[i].empty() && ct > 1) {
      if (visited[mul[i].back()]) {
        mul[i].pop_back();
      } else {
        ans[ct] = i;
        ct--;
        visited[mul[i].back()] = true;
        mul[i].pop_back();
      }
    }
  }
  for (int i = 2; i <= n; i++) cout << ans[i] << ' ';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  solve(n);
  return 0;
}
