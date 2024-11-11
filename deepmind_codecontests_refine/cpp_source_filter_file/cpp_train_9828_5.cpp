#include <bits/stdc++.h>
using namespace std;
const int Maxn = 500010, Maxm = 100010;
int n, a, v, sum, p, nt, j, k, l[Maxn];
long long ans;
map<int, int> m;
multiset<int> q;
int main() {
  ios::sync_with_stdio(0);
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a, m[a]++, ans += a;
  map<int, int>::reverse_iterator i = m.rbegin();
  for (; i != m.rend(); i++) {
    v = i->first;
    n = i->second;
    nt = max((n + sum) / 2, sum);
    p = max(nt - n, 0);
    for (j = nt - 1; j >= p; j--)
      if (j < q.size()) {
        l[j] = *q.begin();
        q.erase(q.begin());
      } else
        l[j] = 0;
    for (j = p, k = sum - j; j < k && j < nt; j++)
      if (l[j] > v) {
        if (k - 1 < nt) l[k - 1] = max(0, 2 * v - l[j]);
        k--;
      } else
        l[j] = v;
    q.insert(l + p, l + nt);
    sum += n;
  }
  for (set<int, int>::iterator i = q.begin(); i != q.end(); i++) ans -= *i;
  cout << ans << endl;
}
