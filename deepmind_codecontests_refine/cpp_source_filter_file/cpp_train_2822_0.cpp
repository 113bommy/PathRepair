#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e+5;
struct robo {
  int x, r, q;
} ro[maxn];
struct opt {
  int tim, x, y, l, r, typ;
} q[maxn * 3];
int tot, n, k, cpy[maxn], ptr, len;
std::map<int, int> mp;
long long ans;
struct BIT {
  int b[maxn];
  BIT() { memset(b, 0, sizeof b); }
  inline void add(int x, int c) {
    for (; x <= len; x += (x & -x)) b[x] += c;
  }
  inline int query(int x) {
    int ret = 0;
    for (; x >= 1; x -= (x & -x)) ret += b[x];
    return ret;
  }
} b;
bool cmp_time(opt lhs, opt rhs) { return lhs.tim < rhs.tim; }
bool cmp_pos(opt lhs, opt rhs) {
  return (lhs.x == rhs.x) ? (lhs.typ == 0) : (lhs.x < rhs.x);
}
bool cmp_rob(robo lhs, robo rhs) { return lhs.r > rhs.r; }
void CDQ(int l, int r) {
  if (l >= r) return;
  int mid = (l + r) >> 1;
  CDQ(l, mid);
  sort(q + l, q + 1 + mid, cmp_pos);
  sort(q + 1 + mid, q + 1 + r, cmp_pos);
  int i = l, j = mid + 1;
  while (i <= mid && j <= r) {
    if (q[i].x <= q[j].x) {
      if (q[i].typ == 0) b.add(q[i].y, 1);
      ++i;
    } else {
      if (q[j].typ != 0)
        ans += q[j].typ * (b.query(q[j].l) - b.query(q[j].r - 1));
      ++j;
    }
  }
  for (int k = j; k <= r; ++k)
    ans += q[k].typ * (b.query(q[k].l) - b.query(q[k].r - 1));
  for (int k = l; k < i; ++k)
    if (q[k].typ == 0) b.add(q[k].y, -1);
  sort(q + mid + 1, q + r + 1, cmp_time);
  CDQ(mid + 1, r);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) {
    cin >> ro[i].x >> ro[i].r >> ro[i].q;
    cpy[i] = ro[i].q;
  }
  sort(cpy + 1, cpy + 1 + n);
  len = unique(cpy + 1, cpy + 1 + n) - (cpy + 1);
  for (int i = 1; i <= len; ++i) mp[cpy[i]] = i;
  mp[0x3f3f3f3f] = 1;
  sort(ro + 1, ro + 1 + n, cmp_rob);
  for (int i = 1; i <= n; ++i) {
    map<int, int>::iterator l = mp.upper_bound(ro[i].q + k);
    --l;
    map<int, int>::iterator r = mp.lower_bound(ro[i].q - k);
    ++ptr;
    q[ptr] = (opt){ptr, ro[i].x - ro[i].r - 1, 0, l->second, r->second, -1};
    ++ptr;
    q[ptr] = (opt){ptr, ro[i].x + ro[i].r, 0, l->second, r->second, 1};
    ++ptr;
    q[ptr] = (opt){ptr, ro[i].x, mp[ro[i].q], 0, 0, 0};
  }
  CDQ(1, ptr);
  cout << ans << endl;
  return 0;
}
