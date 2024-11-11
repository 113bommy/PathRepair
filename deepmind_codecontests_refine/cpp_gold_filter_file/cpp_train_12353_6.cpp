#include <bits/stdc++.h>
using namespace std;
int n;
int a[200010];
pair<int, int> b[200010];
int tree[200010];
void update(int pos) {
  while (pos <= n) {
    tree[pos]++;
    pos += pos & (-pos);
  }
}
int get(int pos) {
  int ans = 0;
  while (pos) {
    ans += tree[pos];
    pos -= pos & (-pos);
  }
  return ans;
}
int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i], b[i] = make_pair(a[i], i);
  sort(b + 1, b + n + 1);
  int cur = n + 1;
  long long ans = 0ll;
  for (int i = n; i >= 1; --i) {
    while (cur > 1 && b[cur - 1].first >= i) cur--, update(b[cur].second);
    ans += 1ll * get(min(a[i], n));
    if (a[i] >= i) ans--;
  }
  cout << ans / 2 << endl;
  return 0;
}
