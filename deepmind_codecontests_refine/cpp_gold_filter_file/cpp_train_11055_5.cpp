#include <bits/stdc++.h>
using namespace std;
const int N = 500005;
int n, m, c, w, t, a, b, q, cur;
struct SNode {
  int c;
  mutable int w;
  SNode(int _c = 0, int _w = 0) : c(_c), w(_w) {}
  inline bool operator<(const SNode &oth) const { return c < oth.c; }
};
vector<pair<int, SNode>> ve;
multiset<SNode> second;
long long solve() {
  long long ans = 0;
  ve.clear();
  second.clear();
  cin >> n >> m >> c >> cur;
  ve.push_back({0, SNode(0, cur)});
  ve.push_back({m, SNode(0, c)});
  while (n--) {
    cin >> t >> a >> b;
    ve.push_back({t, SNode(b, a)});
  }
  sort(ve.begin(), ve.end());
  second.insert(SNode(0, cur));
  for (int i = 1; i < ve.size(); i++) {
    int tim = ve[i].first - ve[i - 1].first;
    cur -= tim;
    if (cur < 0) {
      return -1;
    }
    while (tim > 0) {
      if (second.begin()->w <= tim) {
        tim -= second.begin()->w;
        second.erase(second.begin());
      } else {
        second.begin()->w -= tim;
        tim = 0;
      }
    }
    SNode add = ve[i].second;
    if (add.w <= c - cur) {
      second.insert(add);
      cur += add.w;
      ans += 1LL * add.w * add.c;
    } else {
      second.insert(SNode(add.c, c - cur));
      ans += 1LL * add.c * (c - cur);
      add.w -= c - cur;
      cur = c;
      while (prev(second.end())->c > add.c && add.w > 0) {
        auto rep = prev(second.end());
        if (rep->w <= add.w) {
          int w = rep->w;
          ans -= 1LL * rep->c * w;
          ans += 1LL * add.c * w;
          second.erase(rep);
          second.insert(SNode(add.c, w));
          add.w -= w;
        } else {
          int w = add.w;
          ans -= 1LL * rep->c * w;
          ans += 1LL * add.c * w;
          rep->w -= w;
          second.insert(add);
          break;
        }
      }
    }
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> q;
  while (q--) {
    cout << solve() << '\n';
  }
}
