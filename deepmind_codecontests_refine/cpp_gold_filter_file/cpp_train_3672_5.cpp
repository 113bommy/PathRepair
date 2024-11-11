#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;
const int inf = 0x7f7f7f7f;
const int Mod = 1e9 + 7;
int n, h[maxn], dp[maxn];
vector<int> v;
vector<int> jump[maxn];
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) scanf("%d", &h[i]);
  memset(dp, 0x3f, sizeof(dp));
  dp[1] = 0;
  for (int i = 1; i <= n; i++) {
    while (!v.empty() && h[v.back()] < h[i]) v.pop_back();
    if (!v.empty()) jump[i].push_back(v.back());
    v.push_back(i);
  }
  v.clear();
  for (int i = 1; i <= n; i++) {
    while (!v.empty() && h[v.back()] > h[i]) v.pop_back();
    if (!v.empty()) jump[i].push_back(v.back());
    v.push_back(i);
  }
  v.clear();
  for (int i = n; i >= 1; --i) {
    while (!v.empty() && h[v.back()] < h[i]) v.pop_back();
    if (!v.empty()) jump[v.back()].push_back(i);
    v.push_back(i);
  }
  v.clear();
  for (int i = n; i >= 1; --i) {
    while (!v.empty() && h[v.back()] > h[i]) v.pop_back();
    if (!v.empty()) jump[v.back()].push_back(i);
    v.push_back(i);
  }
  for (int i = 2; i <= n; i++) {
    for (int j = 0; j < (int)jump[i].size(); j++) {
      dp[i] = min(dp[i], dp[jump[i][j]] + 1);
    }
  }
  printf("%d\n", dp[n]);
  return 0;
}
