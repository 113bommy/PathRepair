#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 10;
const int MOD = 1e9 + 7;
const long long LLMAX = 2e18;
priority_queue<int, vector<int>, greater<int> > qu;
priority_queue<int, vector<int>, less<int> > qd;
int dp[MAXN];
struct node {
  int l, r, x;
  bool operator<(const node &Node) const { return r < Node.r; }
} a[MAXN];
int main(void) {
  int n, q, cnt = 0;
  cin >> n >> q;
  for (int i = 0; i < q; i++) scanf("%d%d%d", &a[i].l, &a[i].r, &a[i].x);
  sort(a, a + q);
  for (int i = 0; i < q; i++) {
    int l = a[i].l, r = a[i].r, x = a[i].x;
    for (int j = n - x; j >= 1; j--)
      if (dp[j] >= l) dp[j + x] = max(dp[j + x], dp[j]);
    dp[x] = r;
  }
  for (int i = 1; i <= n; i++)
    if (dp[i]) cnt++;
  cout << cnt << endl;
  for (int i = 1; i <= n; i++)
    if (dp[i]) cout << i << ' ';
  return 0;
}
