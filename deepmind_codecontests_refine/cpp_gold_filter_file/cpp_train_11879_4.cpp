#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 50, inf = 1e9;
int n, k, a[N], b[N], val[N], mx;
long long ans;
struct node {
  int l, r, t;
  bool operator<(const node &b) const { return l < b.l; }
};
set<node> s;
set<node>::iterator it;
vector<pair<int, int> > v[N];
void split(int x) {
  it = --s.upper_bound((node){x, 0, 0});
  node p = *it;
  if (p.l == x) return;
  s.erase(it);
  s.insert((node){p.l, x - 1, p.t});
  s.insert((node){x, p.r, p.t});
}
bool check(int x) {
  long long sum = 0, now = 0, ans1 = 0, ans2 = 0;
  memset(val, 0, sizeof(val));
  for (int i = 1, p = 0; i <= n; i++) {
    for (int j = 0; j < v[i].size(); j++)
      if (v[i][j].second <= p) {
        now += v[i][j].first;
        sum += 1ll * v[i][j].first * (p - v[i][j].second + 1);
      } else
        val[v[i][j].second] += v[i][j].first;
    while (now + val[p + 1] >= x) sum += (now += val[++p]);
    ans1 += p;
    ans2 += sum;
  }
  if (ans1 < k) return 0;
  ans = ans2 - x * (ans1 - k);
  return 1;
}
int main() {
  scanf("%d%d", &n, &k);
  s.insert((node){1, inf, 0});
  for (int i = 1, l, r; i <= n; i++) {
    scanf("%d%d", &l, &r);
    r--;
    split(l);
    split(r + 1);
    mx = max(mx, r);
    for (it = s.lower_bound((node){l, 0, 0}); it->r <= r;) {
      v[i].push_back(make_pair(it->r - it->l + 1, it->t + 1));
      s.erase(it);
      it = s.lower_bound((node){l, 0, 0});
    }
    s.insert((node){l, r, i});
    v[i].push_back(make_pair(-(r - l + 1), i + 1));
  }
  for (int i = 29, now = 0; ~i; i--)
    if (check(now | 1 << i)) now |= 1 << i;
  cout << ans;
}
