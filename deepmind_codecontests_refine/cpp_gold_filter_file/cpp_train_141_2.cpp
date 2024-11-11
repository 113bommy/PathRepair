#include <bits/stdc++.h>
using namespace std;
const int N = 2050;
int n, k;
int pre[N];
int ith[N];
int cnt[N];
int back[N];
void dfs(int now) {
  if (ith[now]) return;
  if (now == k) back[now] = -1;
  if (pre[now]) {
    dfs(pre[now]);
    if (now == k) back[now] = -1;
    if (back[pre[now]] == -1)
      back[now] = -1;
    else
      back[pre[now]] = now;
    ith[now] = ith[pre[now]] + 1;
  } else {
    ith[now] = 1;
  }
}
int main(void) {
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) cin >> pre[i];
  for (int i = 1; i <= n; ++i) dfs(i);
  vector<int> vec;
  for (int i = 1; i <= n; ++i)
    if (back[i] == 0) vec.push_back(ith[i]);
  cnt[0] = 1;
  for (auto &m : vec) {
    for (int i = n; i >= 0; --i) {
      if (cnt[i]) cnt[i + m] = 1;
    }
  }
  vector<int> ans;
  for (int i = 0; i <= n; ++i)
    if (cnt[i]) ans.push_back(i);
  for (auto &m : ans) cout << m + ith[k] << endl;
  return 0;
}
