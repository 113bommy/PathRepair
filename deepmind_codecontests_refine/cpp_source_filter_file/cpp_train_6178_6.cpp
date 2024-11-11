#include <bits/stdc++.h>
using namespace std;
const int maxn = 300;
int a[maxn], b[maxn];
vector<pair<int, int> > ans;
int main() {
  int n, m;
  cin >> n >> m;
  int tot = 0;
  for (int i = 0; i < m; i++) {
    int t, k;
    cin >> t;
    for (int j = 0; j < t; j++) {
      cin >> k;
      a[++tot] = k;
      b[k] = tot;
    }
  }
  int k = -1;
  for (int i = 1; i <= n; i++)
    if (b[i] == 0) {
      k = i;
      break;
    }
  for (int i = 1; i <= tot; i++)
    if (a[i] == i)
      continue;
    else {
      if (i != k) ans.push_back(make_pair(i, k));
      ans.push_back(make_pair(a[i], i));
      a[k] = a[i];
      b[a[k]] = k;
      k = b[i];
      a[i] = b[i] = i;
    }
  cout << ans.size() << endl;
  for (__typeof(ans.begin()) i = ans.begin(); i != ans.end(); ++i)
    cout << i->first << " " << i->second << endl;
  return 0;
}
