#include <bits/stdc++.h>
const int MAXN = 1500;
using namespace std;
struct Node {
  int l, r;
  Node() {}
  Node(int _l, int _r) : l(_l), r(_r) {}
  bool operator<(const Node &rhs) const {
    if (r == rhs.r) {
      return l < rhs.l;
    } else {
      return r < rhs.r;
    }
  }
};
int ans, n, a[MAXN + 5], res;
map<int, vector<Node> > mp;
map<int, vector<Node> >::iterator it;
void init() {
  ios::sync_with_stdio(false);
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  for (int i = 1; i <= n; ++i) {
    int sum = 0;
    for (int j = i; j <= n; ++j) {
      sum += a[j];
      mp[sum].push_back(Node(i, j));
    }
  }
}
int main() {
  init();
  for (it = mp.begin(); it != mp.end(); ++it) {
    sort((it->second).begin(), (it->second).end());
  }
  for (it = mp.begin(); it != mp.end(); ++it) {
    int sum = it->first, cnt = 0, cur = 0;
    for (int i = 0; i < mp[sum].size(); ++i) {
      if (mp[sum][i].l > cur) {
        ++cnt;
        cur = mp[sum][i].r;
      }
    }
    if (cnt > ans) {
      ans = max(ans, cnt);
      res = sum;
    }
  }
  cout << ans << endl;
  int cur = 0;
  for (int i = 0; i < mp[res].size(); ++i) {
    int l = mp[res][i].l, r = mp[res][i].r;
    if (l > cur) {
      cur = r;
      cout << l << ' ' << r << endl;
    }
  }
  return 0;
}
