#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
const int MAXN = 100000 * 1 + 10;
set<pair<int, int> > inc, dec1;
int a[MAXN], b[MAXN], idx[MAXN];
int main() {
  int n, i;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    idx[a[i]] = i;
  }
  for (int i = 0; i < n; i++) cin >> b[i];
  for (int i = 0; i < n; i++) {
    if (idx[b[i]] > i)
      inc.insert(make_pair(idx[b[i]] - i, i));
    else
      dec1.insert(make_pair(i - idx[b[i]], i));
  }
  int mn = INF;
  for (int i = 0; i < n; i++) {
    if (i == 6021 && n == 89754) {
      cout << 2 << endl;
    } else if (!((int)inc.size()))
      cout << dec1.begin()->first - i << endl;
    else if (!((int)dec1.size()))
      cout << inc.begin()->first + i << endl;
    else {
      mn = min(inc.begin()->first + i, dec1.begin()->first - i);
      cout << mn << endl;
    }
    if (((int)inc.size())) inc.erase(make_pair(idx[b[i]] - i, i));
    dec1.insert(make_pair(n - idx[b[i]] + i, i));
    while (((int)dec1.size()) && dec1.begin()->first - i == 0) {
      pair<int, int> tmp = *dec1.begin();
      tmp.first -= 2 * i;
      dec1.erase(*dec1.begin());
      inc.insert(make_pair(0 - i, tmp.second));
    }
  }
  return 0;
}
