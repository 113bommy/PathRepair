#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      pq;
  for (int i = 0; i < n; ++i) {
    int x, y;
    cin >> x >> y;
    --x;
    pq.push({x, 1});
    pq.push({y, -1});
  }
  int ans[m];
  int it = 0;
  for (int i = 0; i < m; ++i) {
    while (pq.size() && pq.top().first == i) {
      it += pq.top().second;
      pq.pop();
    }
    ans[i] = it;
  }
  int inc[m], dec[m];
  vector<int> V;
  for (int i = 0; i < m; ++i) {
    int x = ans[i];
    int j = upper_bound(V.begin(), V.end(), x) - V.begin();
    if (j < V.size()) {
      V[j] = x;
    } else
      V.push_back(x);
    inc[i] = j;
  }
  V.clear();
  for (int i = m - 1; i >= 0; --i) {
    int x = ans[i];
    int j = upper_bound(V.begin(), V.end(), x) - V.begin();
    if (j < V.size()) {
      V[j] = x;
    } else
      V.push_back(x);
    dec[i] = j + 1;
  }
  int pinc[m], pdec[m];
  for (int i = 0; i < m; ++i) {
    if (i)
      pinc[i] = max(inc[i], pinc[i - 1]);
    else
      pinc[i] = inc[i];
  }
  for (int i = m - 1; i >= 0; --i) {
    if (i != m - 1)
      pdec[i] = max(dec[i], pdec[i + 1]);
    else
      pdec[i] = dec[i];
  }
  int res = 0;
  for (int i = 0; i < m - 1; ++i) {
    res = max(res, pinc[i] + pdec[i + 1]);
  }
  cout << res << endl;
}
