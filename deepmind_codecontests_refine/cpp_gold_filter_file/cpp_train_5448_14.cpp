#include <bits/stdc++.h>
using namespace std;
const int Maxn = 1000 * 1000 + 10;
int d[Maxn];
int a[Maxn], b[Maxn];
int sa, sb, mx;
queue<int> q;
int main() {
  ios::sync_with_stdio(false);
  cin >> sa >> sb;
  for (int i = 0; i < sa; i++) cin >> a[i];
  for (int i = 0; i < sb; i++) cin >> b[i], d[b[i]] = i + 1;
  for (int i = 0; i < 2 * sa; i++) {
    bool f = 0;
    while (!f) {
      if (!q.size()) f++;
      int h = d[a[i % sa]];
      if (h && q.size() < 2) {
        q.push(h);
        f = 1;
      } else if (h && q.back() > q.front() && (h < q.front() || h > q.back())) {
        q.push(h);
        f = 1;
      } else if (h && q.back() < q.front() && h < q.front() && h > q.back()) {
        q.push(h);
        f = 1;
      }
      if (!f) q.pop();
    }
    mx = max(mx, (int)q.size());
  }
  cout << min(mx, sa) << endl;
}
