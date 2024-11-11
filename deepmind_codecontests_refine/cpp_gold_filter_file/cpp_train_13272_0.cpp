#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
const int MAXN = 2e5 + 4;
bool was[MAXN];
int a;
int cnt(int len) { return (len + 1) / (a + 1); }
set<pair<int, int> > st;
void solve() {
  int n, k, m;
  cin >> n >> k >> a >> m;
  int sum = cnt(n);
  st.insert(make_pair(1, n));
  int x;
  st.insert(make_pair(INF, INF));
  for (int i = 0; i < m; i++) {
    scanf("%d", &x);
    if (was[x]) continue;
    was[x] = 1;
    if ((int)st.size() == 1) break;
    set<pair<int, int> >::iterator it = st.upper_bound(make_pair(x, INF));
    --it;
    pair<int, int> cur = *it;
    st.erase(cur);
    sum -= cnt(cur.second - cur.first + 1);
    if (cur.first == x) {
      if (x + 1 <= cur.second) {
        pair<int, int> to = make_pair(x + 1, cur.second);
        sum += cnt(to.second - to.first + 1);
        st.insert(to);
      }
    } else if (cur.second == x) {
      pair<int, int> to = make_pair(cur.first, x - 1);
      sum += cnt(to.second - to.first + 1);
      st.insert(to);
    } else {
      pair<int, int> to1 = make_pair(cur.first, x - 1);
      pair<int, int> to2 = make_pair(x + 1, cur.second);
      sum += cnt(to1.second - to1.first + 1);
      sum += cnt(to2.second - to2.first + 1);
      st.insert(to1);
      st.insert(to2);
    }
    if (sum < k) {
      printf("%d", i + 1);
      return;
    }
  }
  printf("-1");
}
int main() {
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
