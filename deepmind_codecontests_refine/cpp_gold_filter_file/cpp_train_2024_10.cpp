#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 2;
mt19937 rng(std::chrono::system_clock::now().time_since_epoch().count());
pair<long long, int> bit[N];
vector<int> comp;
int n, q, h[N];
struct query {
  int t, y;
  long long x;
  query(int a = 0, int b = 0, int c = 0) {
    t = a;
    x = b;
    y = c;
  }
  void sc() {
    scanf("%d%lld", &t, &x);
    if (t == 1) {
      x--;
      scanf("%d", &y);
    }
  }
};
vector<query> v;
void add(int at, int val, int by) {
  for (int cur = at; cur < N; cur += cur & -cur)
    bit[cur].first += val, bit[cur].second += by;
}
pair<long long, int> get(int val) {
  pair<long long, int> ret = {0LL, 0};
  for (int cur = val; cur; cur -= cur & -cur)
    ret.first += bit[cur].first, ret.second += bit[cur].second;
  return ret;
}
int main() {
  scanf("%d%d", &n, &q);
  for (int i = 0; i < n; i++) {
    scanf("%d", h + i);
    comp.push_back(h[i]);
  }
  for (int i = 0; i < q; i++) {
    query temp;
    temp.sc();
    v.push_back(temp);
    if (temp.t == 1) comp.push_back(temp.y);
  }
  sort(comp.begin(), comp.end());
  comp.resize(unique(comp.begin(), comp.end()) - comp.begin());
  for (int i = 0; i < n; i++)
    add(lower_bound(comp.begin(), comp.end(), h[i]) - comp.begin() + 1, h[i],
        1);
  for (auto i : v) {
    if (i.t == 1) {
      add(lower_bound(comp.begin(), comp.end(), h[i.x]) - comp.begin() + 1,
          -h[i.x], -1);
      h[i.x] = i.y;
      add(lower_bound(comp.begin(), comp.end(), h[i.x]) - comp.begin() + 1,
          h[i.x], 1);
    } else {
      int l = 0, r = comp.size() - 1, bst = 0, freq = 0;
      long long total = 0;
      while (l <= r) {
        int mid = (l + r) / 2;
        pair<long long, int> temp = get(mid + 1);
        long long tot = temp.second * 1LL * comp[mid];
        if (tot - temp.first <= i.x && tot >= temp.first) {
          l = mid + 1;
          bst = mid;
          total = comp[mid] * 1LL * temp.second - temp.first;
          freq = temp.second;
        } else
          r = mid - 1;
      }
      printf("%.9lf\n", comp[bst] + (i.x - total + .0) / freq);
    }
  }
}
