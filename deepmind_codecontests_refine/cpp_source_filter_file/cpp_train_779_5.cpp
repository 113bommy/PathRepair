#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;
const int maxn5 = 5e5 + 10;
const int maxnt = 1.2e6 + 10;
const int maxn3 = 1e3 + 10;
const long long mod = 1e9 + 7;
const long long inf = 2e18;
int mx[maxnt], x[maxn5], t[maxn5];
int cnt[maxn5], rev[maxn5];
long long stay[maxn5], val[maxn5];
vector<pair<long long, long long>> fr;
set<pair<long long, long long>> wait;
map<int, int> ind;
void build(int l, int r, int v) {
  if (r - l == 1) {
    mx[v] = l;
    return;
  }
  int mid = (l + r) >> 1;
  build(l, mid, v * 2);
  build(mid, r, v * 2 + 1);
  int a = mx[v * 2], b = mx[v * 2 + 1];
  if (stay[a] + val[a] > stay[b] + val[b])
    mx[v] = a;
  else
    mx[v] = b;
  return;
}
void update(int l, int r, int ind, long long s, int v) {
  if (r - l == 1) {
    val[l] += s;
    return;
  }
  int mid = (l + r) >> 1;
  if (ind < mid)
    update(l, mid, ind, s, v * 2);
  else
    update(mid, r, ind, s, v * 2 + 1);
  int a = mx[v * 2], b = mx[v * 2 + 1];
  if (stay[a] + val[a] > stay[b] + val[b])
    mx[v] = a;
  else
    mx[v] = b;
  return;
}
int get_ans(int l, int r, int lq, int rq, long long pos, int v) {
  if (lq >= rq) return -1;
  if (lq == l and rq == r) {
    if (stay[mx[v]] + val[mx[v]] < pos) return -1;
  }
  if (r - l == 1) return mx[v];
  int mid = (l + r) >> 1;
  int ans1 = get_ans(l, mid, lq, min(rq, mid), pos, v * 2);
  if (ans1 != -1) return ans1;
  return get_ans(mid, r, max(lq, mid), rq, pos, v * 2 + 1);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> t[i];
    fr.push_back({x[i], i});
  }
  sort(fr.begin(), fr.end());
  int num = 0;
  for (auto [p, i] : fr) {
    rev[i] = num;
    ind[p] = num++;
  }
  for (int i = 0; i < n; i++) {
    int a = ind[x[i]];
    stay[a] = x[i];
    val[a] = t[i];
  }
  build(0, num, 1);
  for (int i = 0; i < m; i++) {
    int pos, s;
    cin >> pos >> s;
    int p1 =
        upper_bound(fr.begin(), fr.end(), make_pair(pos * 1LL, maxn * 1LL)) -
        fr.begin() - 1;
    int ans = get_ans(0, num, 0, p1 + 1, pos, 1);
    if (ans != -1) {
      update(0, num, ans, s, 1);
      cnt[ans]++;
      while (!wait.empty()) {
        auto it = wait.lower_bound({stay[ans], 0});
        if (it == wait.end()) break;
        pair<long long, long long> p = *it;
        if (stay[ans] + val[ans] >= p.first) {
          wait.erase(it);
          update(0, num, ans, p.second, 1);
          cnt[ans]++;
        } else
          break;
      }
    } else
      wait.insert({pos, s});
  }
  for (int i = 0; i < n; i++) cout << cnt[rev[i]] << ' ' << val[rev[i]] << '\n';
  return 0;
}
