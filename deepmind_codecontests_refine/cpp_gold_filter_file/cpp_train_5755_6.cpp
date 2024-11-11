#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 9;
const long long inf = 1e18 + 1;
int t;
int x[maxn], y[maxn];
int ml[maxn], mr[maxn];
int mml[maxn], mmr[maxn];
int cnt = 0;
deque<int> dq;
void solve() {
  int n, k;
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++) scanf("%d", &x[i]);
  for (int i = 1; i <= n; i++) scanf("%d", &y[i]);
  sort(x + 1, x + n + 1);
  for (int i = 0; i <= n + 2; i++) {
    ml[i] = mr[i] = 0;
    mml[i] = mmr[i] = 0;
  }
  int sum = 0;
  dq.clear();
  for (int i = 1; i <= n; i++) {
    dq.push_back(i);
    sum++;
    while (!dq.empty() && x[i] - x[dq.front()] > k) {
      sum--;
      dq.pop_front();
    }
    ml[i] = sum;
    mml[i] = max(mml[i - 1], ml[i]);
  }
  dq.clear();
  sum = 0;
  for (int i = n; i >= 1; i--) {
    dq.push_back(i);
    sum++;
    while (!dq.empty() && x[dq.front()] - x[i] > k) {
      sum--;
      dq.pop_front();
    }
    mr[i] = sum;
    mmr[i] = max(mmr[i + 1], mr[i]);
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    ans = max(ans, mml[i] + mmr[i + 1]);
  }
  cout << ans << '\n';
}
int main() {
  cin >> t;
  while (t--) solve();
  return 0;
}
