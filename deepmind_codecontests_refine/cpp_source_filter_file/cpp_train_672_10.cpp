#include <bits/stdc++.h>
using namespace std;
vector<int> G[5 * 100010];
int cnt[5 * 100010], a[5 * 100010];
bool in[5 * 100010];
int query(int x) {
  int ans = 0;
  int s = G[x].size();
  for (int i = 0; i < (1 << s); i++) {
    int v = 1;
    int sign = 1;
    for (int k = 0; k < s; k++) {
      if (i >> k & 1) v *= G[x][k], sign *= -1;
    }
    ans += sign * cnt[v];
  }
  return ans;
}
void add(int x, int w) {
  int s = G[x].size();
  for (int i = 0; i < (1 << s); i++) {
    int v = 1;
    for (int k = 0; k < s; k++) {
      if (i >> k & 1) v *= G[x][k];
    }
    cnt[v] += w;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  for (int j = 2; j < 5 * 100010; j++)
    if (G[j].empty())
      for (int i = j; i < 5 * 100010; i += j) G[i].push_back(j);
  int n, q;
  cin >> n >> q;
  for (int i = 0; i < n; i++) cin >> a[i];
  long long ans = 0;
  while (q--) {
    int i;
    cin >> i;
    i--;
    if (in[i]) {
      add(a[i], -1);
      ans -= query(a[i]);
      in[i] = 0;
    } else {
      ans += query(a[i]);
      add(a[i], 1);
      in[i] = 1;
    }
    cout << ans;
  }
  return 0;
}
