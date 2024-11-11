#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100000 * 1 + 10;
set<pair<int, int> > inc, dec1;
int a[MAXN], b[MAXN], idx[MAXN];
const int INF = 1e9;
int main() {
  int n, i;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    idx[a[i]] = i;
  }
  for (int i = 0; i < n; i++) cin >> b[i];
  for (int i = 0; i < n; i++) {
    if (idx[b[i]] >= i)
      inc.insert(make_pair(idx[b[i]] - i, i));
    else
      dec1.insert(make_pair(i - idx[b[i]], i));
  }
  int mn = 1e9;
  inc.insert(pair<int, int>(1e9, 1e9));
  dec1.insert(pair<int, int>(1e9, 1e9));
  for (int i = 0; i < n; i++) {
    mn = min(inc.begin()->first + i, dec1.begin()->first - i);
    cout << mn << endl;
    inc.erase(make_pair(idx[b[i]] - i, i));
    dec1.insert(make_pair(n - idx[b[i]] + i, i));
    while ((int)dec1.size() > 1 && dec1.begin()->first - i <= 1) {
      pair<int, int> tmp = *dec1.begin();
      dec1.erase(*dec1.begin());
      inc.insert(make_pair(0 - i - 1, tmp.second));
    }
  }
  return 0;
}
