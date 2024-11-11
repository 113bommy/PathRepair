#include <bits/stdc++.h>
using namespace std;
pair<int, int> a[200005];
int x[200005];
int n, d, m;
stack<int> curr;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cerr.tie(0);
  cin >> d >> n >> m;
  for (int i = 1; i <= m; i++) cin >> a[i].first >> a[i].second;
  sort(a + 1, a + m + 1);
  a[m].first = d;
  curr.push(m);
  for (int i = m; i >= 1; i--) {
    while (curr.size() > 1 && a[curr.top()].second >= a[i].second) curr.pop();
    x[i] = curr.top();
    curr.push(i);
  }
  int gorivo = n;
  long long cena = 0;
  a[0].first = 0;
  for (int i = 1; i <= m + 1; i++) {
    gorivo -= a[i].first - a[i - 1].first;
    if (gorivo < 0) {
      cout << -1 << endl;
      return 0;
    }
    if (i == m + 1) break;
    long long xc = min(n - gorivo, max(0, a[x[i]].first - a[i].first - gorivo));
    gorivo += xc;
    cena += a[i].second * xc;
  }
  cout << cena << endl;
  return 0;
}
