#include <bits/stdc++.h>
using namespace std;
int n, k, cur, ans = 0;
vector<int> v, cnt;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> k;
  if (n % 2 == 0)
    cur = n;
  else
    cur = n + 1;
  v.resize(n);
  cnt.resize(k + 1);
  for (int i = 0; i < n; i++) cin >> v[i], cnt[v[i]] += 1;
  for (int i = 1; i <= k; i++) ans += cnt[i] / 2, cur -= cnt[i] / 2;
  ans += cur / 2;
  cout << ans;
  return 0;
}
