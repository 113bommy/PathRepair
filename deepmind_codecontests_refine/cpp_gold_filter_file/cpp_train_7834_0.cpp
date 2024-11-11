#include <bits/stdc++.h>
using namespace std;
void setIO(string str, bool dbg) {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  cout.tie(nullptr);
  if (!dbg) {
    freopen((str + ".in").c_str(), "r", stdin);
    freopen((str + ".out").c_str(), "w", stdout);
  }
}
const int MAX = 3e5 + 5;
const int LEN = 3e1 + 0;
const int LVL = 2e1 + 0;
const long long int MOD = 998244353;
const long long int INF = 9e17;
int xyz = 1;
int n, q;
int a[MAX];
int d[MAX];
int p[MAX];
int s[MAX];
pair<int, int> que[MAX];
int ord[MAX];
int bit[MAX];
int ans[MAX];
bool cmp(int a, int b) { return que[a].second > que[b].second; }
int get(int i) {
  int res = 0;
  for (; i >= 1; i -= (-i & i)) res += bit[i];
  return res;
}
void add(int i, int v) {
  if (!i) return;
  for (; i <= n; i += (-i & i)) bit[i] += v;
}
int src(int l, int r, int i) {
  while (l < r) {
    int mid = (l + r) / 2;
    bool can = get(i) - get(mid) < d[i];
    if (can == 0) l = mid + 1;
    if (can == 1) r = mid;
  }
  return l;
}
void run() {
  cin >> n >> q;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++) d[i] = i - a[i] < 0 ? n + 1 : i - a[i];
  int cur = 0;
  for (int i = 1; i <= n; i++) s[i] = (cur += d[i] <= cur);
  for (int i = 1; i <= n; i++) {
    if (d[i] > n || s[i] == s[i - 1]) continue;
    add(p[i] = src(1, i, i), 1);
  }
  for (int i = 1; i <= q; i++)
    cin >> que[i].first >> que[i].second, ord[i] = i,
                                          que[i].second = n - que[i].second + 1;
  sort(ord + 1, ord + 1 + q, cmp);
  for (int i = 1; i <= q; i++) ans[i] += get(n) - get(que[i].first);
  for (int i = 1; i <= n; i++) bit[i] = 0;
  int j = n;
  for (int i = 1; i <= q; i++) {
    while (j && j >= que[ord[i]].second) add(p[j--], 1);
    ans[ord[i]] -= get(n) - get(que[ord[i]].first);
  }
  for (int i = 1; i <= q; i++) cout << ans[i] << "\n";
}
int main() {
  setIO("", 1);
  while (xyz--) run();
  return 0;
}
