#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 20;
const int maxq = 1e6 + 20 + maxn;
const int maxa = 6e6 + 20;
int l[maxq], r[maxq], a[maxn], ans[maxq];
int p[maxa], id[maxa];
bool has[maxa];
vector<int> query[maxn];
vector<pair<int, int> > shit[maxa];
int fen[maxn];
void update(int p, int val) {
  for (p = maxn - 10 - p; p < maxn; p += ((p) & (-(p))))
    fen[p] = min(fen[p], val);
}
int get(int p) {
  int res = 1e9;
  for (p = maxn - 10 - p; p > 0; p -= ((p) & (-(p)))) res = min(res, fen[p]);
  return res;
}
void add(int x, int ind) {
  vector<int> tmp;
  int y = id[x];
  while (y > 1) {
    tmp.push_back(p[y]);
    y /= p[y];
  }
  int m = tmp.size();
  for (int mask = 0; mask < (1 << m); mask++) {
    int mul = 1, t = 0;
    for (int i = 0; i < m; i++)
      if ((((mask) >> (i)) & 1)) mul *= tmp[i], t++;
    for (auto ker : shit[mul]) update(ker.second, m + ker.first - 2 * t);
    while (!shit[mul].empty() && shit[mul].back().first >= m)
      shit[mul].pop_back();
    shit[mul].push_back(make_pair(m, ind));
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, q;
  cin >> n >> q;
  for (int i = 0; i < n; i++) cin >> a[i], has[a[i]] = 1;
  fill(id, id + maxa, 1);
  memset(fen, 63, sizeof fen);
  for (int i = 2; i < maxa; i++)
    if (!p[i])
      for (int j = i; j < maxa; j += i) {
        p[j] = i;
        if (has[j]) {
          int cur = 0, now = j;
          while (now % i == 0) now /= i, cur ^= 1;
          if (cur) id[j] *= i;
        }
      }
  for (int i = 0; i < q; i++) {
    cin >> l[i] >> r[i];
    l[i]--;
    r[i]--;
    query[r[i]].push_back(i);
  }
  for (int i = 0; i < n; i++) {
    add(a[i], i);
    for (auto ind : query[i]) ans[ind] = get(l[ind]);
  }
  for (int i = 0; i < q; i++) cout << ans[i] << endl;
}
