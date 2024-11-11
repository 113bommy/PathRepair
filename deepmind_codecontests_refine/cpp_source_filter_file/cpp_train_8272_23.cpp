#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 7;
string s;
int f[N];
int st[N], ft[N], tim;
int cnt[N];
vector<int> child[N];
void dfs(int v) {
  st[v] = tim++;
  for (auto u : child[v]) dfs(u);
  ft[v] = tim;
}
int main() {
  ios::sync_with_stdio(false);
  int n, k;
  cin >> n >> k;
  cin >> s;
  for (int i = 1; i < n; i++) {
    int cur = f[i];
    while (cur && s[cur] != s[i]) cur = f[cur];
    if (s[i] == s[cur]) cur++;
    f[i + 1] = cur;
  }
  for (int i = 1; i <= n; i++) child[f[i]].push_back(i);
  dfs(0);
  for (int i = 1; i * k <= n; i++) {
    bool flag = true;
    for (int j = 1; j <= k; j++)
      if (!(st[i] <= st[j * i] && st[j * i] < ft[i])) flag = false;
    if (!flag) continue;
    int l = 0, r = min(n - i * k, i) + 1;
    while (r - l > 1) {
      int mid = (l + r) / 2;
      if (st[mid] <= st[i * k + mid] && st[i * k + mid] <= ft[mid])
        l = mid;
      else
        r = mid;
    }
    cnt[i * k - 1]++;
    cnt[i * k + r - 1]--;
  }
  int all = 0;
  for (int i = 0; i < n; i++) {
    all += cnt[i];
    if (all > 0)
      cout << 1;
    else
      cout << 0;
  }
  cout << "\n";
  return 0;
}
