#include <bits/stdc++.h>
using namespace std;
double eps = 1e-9;
const int INF = 1e9 + 7;
const int MAXN = int(5e5 + 7);
long long ans, t[MAXN];
int n, all[MAXN], sz, cnt1, cnt2;
vector<pair<int, pair<int, int> > > v, h;
void add(int x, int val) {
  for (int i = x; i < MAXN; i += i & -i) t[i] += val;
}
long long sum(int x) {
  long long res = 0;
  for (int i = x; i > 0; i -= i & -i) res += t[i];
  return res;
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int x, y, x2, y2;
    scanf("%d%d%d%d", &x, &y, &x2, &y2);
    all[sz++] = x, all[sz++] = y, all[sz++] = x2, all[sz++] = y2;
    if (x > x2) swap(x, x2);
    if (y > y2) swap(y, y2);
    if (x == x2)
      v.push_back((make_pair(x, make_pair(y, y2))));
    else
      h.push_back((make_pair(y, make_pair(x, x2))));
  }
  sort(all, all + sz);
  sz = unique(all, all + sz) - all;
  sort(v.begin(), v.end());
  sort(h.begin(), h.end());
  for (int i = 0; i < h.size(); i++) {
    if (i == 0) continue;
    if (h[i].first != h[i - 1].first) continue;
    if (h[i].second.first == h[i - 1].second.first) {
      h.erase(h.begin() + i);
      i--;
    } else if (h[i].second.first <= h[i - 1].second.second) {
      h[i - 1].second.second = max(h[i - 1].second.second, h[i].second.second);
      h.erase(h.begin() + i);
      i--;
    }
  }
  for (int i = 0; i < v.size(); i++) {
    if (i == 0) continue;
    if (v[i].first != v[i - 1].first) continue;
    if (v[i].second.first == v[i - 1].second.first) {
      v.erase(v.begin() + i);
      i--;
    } else if (v[i].second.first <= v[i - 1].second.second) {
      v[i - 1].second.second = max(v[i - 1].second.second, v[i].second.second);
      v.erase(v.begin() + i);
      i--;
    }
  }
  for (int i = 0; i < h.size(); i++) {
    ans += h[i].second.second - h[i].second.first + 1;
    h[i].first = (lower_bound(all, all + sz, h[i].first) - all) + 1;
    h[i].second.first =
        (lower_bound(all, all + sz, h[i].second.first) - all) + 1;
    h[i].second.second =
        (lower_bound(all, all + sz, h[i].second.second) - all) + 1;
  }
  for (int i = 0; i < v.size(); i++) {
    ans += v[i].second.second - v[i].second.first + 1;
    int x = (lower_bound(all, all + sz, v[i].first) - all) + 1;
    int y = (lower_bound(all, all + sz, v[i].second.first) - all) + 1;
    int y2 = (lower_bound(all, all + sz, v[i].second.second) - all) + 1;
    v[i] = make_pair(y, make_pair(y2, x));
  }
  sort(v.begin(), v.end());
  int pos1 = 0;
  set<pair<int, int> > second;
  set<pair<int, int> >::iterator it;
  for (int i = 0; i < h.size(); i++) {
    for (; pos1 < v.size() && v[pos1].first <= h[i].first; pos1++) {
      add(v[pos1].second.second, 1);
      second.insert(make_pair(v[pos1].second.first, v[pos1].second.second));
    }
    for (it = second.begin(); it != second.end() && it->first < h[i].first;) {
      add(it->second, -1);
      second.erase(it);
      it = second.begin();
    }
    ans -= sum(h[i].second.second) - sum(h[i].second.first - 1);
  }
  printf("%I64d\n", ans);
  return 0;
}
