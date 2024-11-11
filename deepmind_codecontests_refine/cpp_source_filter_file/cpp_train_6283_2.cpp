#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100 * 1000 + 10, INF = 1e9, MOD = 1e9 + 7;
int a[MAXN], b[MAXN], idx[MAXN];
int main() {
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  set<pair<int, int> > inc, dec;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    idx[a[i]] = i;
  }
  for (int i = 0; i < n; i++) {
    cin >> b[i];
    if (idx[b[i]] > i)
      inc.insert(make_pair(idx[b[i]] - i, b[i]));
    else
      dec.insert(make_pair(i - idx[b[i]], b[i]));
  }
  dec.insert(make_pair(INF, INF));
  inc.insert(make_pair(INF, INF));
  for (int i = 0; i < n; i++) {
    int ans = min(dec.begin()->first - i, inc.begin()->first + i);
    cout << ans << endl;
    inc.erase(make_pair((idx[b[i]]) - i, b[i]));
    dec.insert(make_pair(n - idx[b[i]] + i, b[i]));
    while (((int)dec.size()) > 1) {
      pair<int, int> t = *dec.begin();
      if (t.first - i > 1) break;
      dec.erase(dec.begin());
      inc.insert(make_pair(-i - 1, t.second));
    }
  }
  return 0;
}
