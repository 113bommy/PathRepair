#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100000 + 5;
vector<int> e[MAXN];
int unstable(vector<int>& cur, int l, int r) {
  int ret = 0;
  vector<int>& lhs = e[l];
  vector<int>& rhs = e[r];
  for (int i = 1; i < cur.size() - 1; ++i) {
    int a = lower_bound(lhs.begin(), lhs.end(), cur[i]) - lhs.begin();
    int b = upper_bound(lhs.begin(), lhs.end(), cur[i + 1]) - lhs.begin() - 1;
    int c = lower_bound(rhs.begin(), rhs.end(), cur[i]) - rhs.begin();
    int d = upper_bound(rhs.begin(), rhs.end(), cur[i + 1]) - rhs.begin() - 1;
    int c1 = 0, c2 = 0;
    if (a != lhs.size() && lhs[a] >= cur[i] && lhs[a] <= cur[i + 1] && b >= a) {
      c1 = b - a + 1;
    }
    if (c != rhs.size() && rhs[c] >= cur[i] && rhs[c] <= cur[i + 1] && d >= c) {
      c2 = d - c + 1;
    }
    ret += (c1 != c2);
  }
  return ret;
}
int main() {
  int n, k, a;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> k;
    e[i].push_back(0);
    while (k--) {
      cin >> a;
      e[i].push_back(a);
    }
    sort(e[i].begin(), e[i].end());
  }
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    ans += unstable(e[i], ((i - 1) + 7) % 7, (i + 1) % 7);
  }
  cout << ans << endl;
}
