#include <bits/stdc++.h>
using namespace std;
const int maxn = 5005;
int a[maxn], b[maxn], c[maxn];
vector<int> v;
int d[maxn] = {0};
multimap<int, int> mm;
priority_queue<int, vector<int>, greater<int>> q;
int main() {
  ios::sync_with_stdio(false);
  int n, m, k;
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) cin >> a[i] >> b[i] >> c[i];
  for (int i = 1; i <= m; i++) {
    int x, y;
    cin >> x >> y;
    d[y] = max(d[y], x);
  }
  for (int i = 1; i <= n; i++) {
    if (d[i]) {
      mm.insert(make_pair(d[i], i));
    } else {
      mm.insert(make_pair(i, i));
    }
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    while (k < a[i]) {
      if (q.empty()) {
        cout << -1 << endl;
        return 0;
      }
      ans -= q.top();
      q.pop();
      k++;
    }
    k += b[i];
    pair<multimap<int, int>::iterator, multimap<int, int>::iterator> pos =
        mm.equal_range(i);
    while (pos.first != pos.second) {
      if (!k) {
        if (!q.empty()) {
          break;
        }
        if (c[pos.first->second] > q.top()) {
          ans -= q.top();
          q.pop();
          q.push(c[pos.first->second]);
          ans += c[pos.first->second];
        }
      } else {
        q.push(c[pos.first->second]);
        ans += c[pos.first->second];
        k--;
      }
      pos.first++;
    }
  }
  cout << ans << endl;
  return 0;
}
