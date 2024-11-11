#include <bits/stdc++.h>
using namespace std;
int n, a[100005], bit[100005];
long long ans;
vector<int> adj[100005];
void update(int x, int val) {
  while (x < 100001) {
    bit[x] += val;
    x += (x & (-x));
  }
}
int get(int x) {
  int res = 0;
  while (x > 0) {
    res += bit[x];
    x -= (x & (-x));
  }
  return res;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n;
  for (int i = (1); i <= (n); ++i) {
    cin >> a[i];
    update(i, 1);
    adj[a[i]].push_back(i);
  }
  int lst = 0, cur, pos, sz;
  for (int i = (1); i <= (100000); ++i) {
    sz = adj[i].size();
    int ok = 0;
    if (!sz)
      continue;
    else {
      for (int j = 0; j < (sz); ++j) {
        pos = adj[i][j];
        if (pos > lst) {
          if (!ok) ok = pos;
          cur = pos;
          if (cur > lst)
            ans += (get(cur) - get(lst));
          else
            ans += get(n) - (get(lst) - get(cur));
          update(cur, -1);
          lst = cur;
        }
      }
      for (int j = 0; j < (sz); ++j) {
        pos = adj[i][j];
        if (pos >= ok && ok != 0) break;
        cur = pos;
        if (cur > lst)
          ans += (get(cur) - get(lst));
        else
          ans += get(n) - (get(lst) - get(cur));
        update(cur, -1);
        lst = cur;
      }
    }
  }
  cout << ans;
  return 0;
}
