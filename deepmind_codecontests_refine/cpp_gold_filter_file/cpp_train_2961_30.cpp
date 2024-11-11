#include <bits/stdc++.h>
#pragma GCC optimize("O2")
using namespace std;
long long power(long long a, long long b, long long md) {
  return (!b ? 1
             : (b & 1 ? a * power(a * a % md, b / 2, md) % md
                      : power(a * a % md, b / 2, md) % md));
}
const int xn = 2e5 + 10;
const int xm = -20 + 10;
const int sq = 500;
const int inf = 1e9 + 10;
const long long INF = 1e18 + 10;
const int mod = 998244353;
const int base = 257;
int n, q, a[xn], last[xn], ans[xn];
int c[xn], cnt[xn], ptr, fen[xn];
pair<int, pair<int, int> > b[xn];
unordered_map<int, int> mp;
vector<int> query[xn], compress;
void modify(int pos, int x) {
  for (; pos < xn; pos += pos & -pos) fen[pos] += x;
}
int get(int pos) {
  int sum = 0;
  for (; pos > 0; pos -= pos & -pos) sum += fen[pos];
  return sum;
}
void add(int x, int y) {
  modify(cnt[x] + 1, -1);
  cnt[x] += y;
  modify(cnt[x] + 1, 1);
}
void solve(int l) {
  for (int i = 1; i <= n; ++i) {
    add(a[i], 1);
    for (int ind : query[i]) {
      for (int j = l; j < ind; ++j) {
        if (b[j].first == 2 || b[j].second.second > i) continue;
        last[j] = a[b[j].second.second];
        add(last[j], -1);
        a[b[j].second.second] = b[j].second.first;
        add(b[j].second.first, 1);
      }
      if (b[ind].second.first == 1)
        ans[ind] = c[a[i]];
      else if (b[ind].second.first % 2 == 0)
        ans[ind] = cnt[a[i]];
      else
        ans[ind] = ptr - get(cnt[a[i]]);
      for (int j = ind - 1; j >= l; --j) {
        if (b[j].first == 2 || b[j].second.second > i) continue;
        add(a[b[j].second.second], -1);
        a[b[j].second.second] = last[j];
        add(last[j], 1);
      }
    }
    query[i].clear();
  }
  for (int i = 1; i <= n; ++i) add(a[i], -1);
  for (int i = l; i < min(q + 1, l + sq); ++i)
    if (b[i].first == 1) a[b[i].second.second] = b[i].second.first;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i], compress.push_back(a[i]);
  cin >> q;
  for (int i = 1; i <= q; ++i) {
    cin >> b[i].first >> b[i].second.first >> b[i].second.second;
    if (b[i].first == 1) compress.push_back(b[i].second.first);
  }
  sort(compress.begin(), compress.end());
  for (int i = 0; i < int(compress.size()); ++i) {
    if (i && compress[i] == compress[i - 1]) continue;
    mp[compress[i]] = ++ptr;
    c[ptr] = compress[i];
  }
  for (int i = 1; i <= n; ++i) a[i] = mp[a[i]];
  for (int i = 1; i <= q; ++i)
    if (b[i].first == 1) b[i].second.first = mp[b[i].second.first];
  modify(1, ptr);
  for (int i = 1; i <= q; ++i) {
    if (b[i].first == 2) query[b[i].second.second].push_back(i);
    if (i % sq == 0) solve(i - sq + 1);
  }
  if (q % sq) solve(q - q % sq + 1);
  for (int i = 1; i <= q; ++i)
    if (b[i].first == 2) cout << ans[i] << '\n';
  return 0;
}
