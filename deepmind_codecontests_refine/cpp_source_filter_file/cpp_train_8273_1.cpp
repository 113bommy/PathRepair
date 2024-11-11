#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5e5 + 5;
long long add[MAXN];
class node {
 public:
  long long first;
  int second;
  bool operator<(const node &other) const { return first < other.first; }
  node() {}
  node(long long first) : first(first) {}
};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  vector<node> v(n);
  for (int i = 0; i < n; i++) cin >> v[i].first, v[i].second = i;
  int sqrtn = sqrt(n);
  auto getgroup = [&](int x) { return x / sqrtn; };
  auto grouplimit = [&](int x) {
    return make_pair(x * sqrtn, min(n, x * sqrtn + sqrtn));
  };
  for (int i = 0; i < n / sqrtn; i++) {
    sort(v.begin() + i * sqrtn, v.begin() + i * sqrtn + sqrtn);
  }
  sort(v.begin() + n / sqrtn * sqrtn, v.end());
  while (q--) {
    int qq;
    cin >> qq;
    if (qq == 1) {
      int l, r;
      long long x;
      cin >> l >> r >> x;
      l--, r--;
      auto groupadd = [&](int groupid) {
        auto [begin, end] = grouplimit(groupid);
        for (int i = begin; i < end; i++) {
          if (v[i].second >= l && v[i].second <= r) v[i].first += x;
        }
        sort(v.begin() + begin, v.begin() + end);
      };
      int lgroup = getgroup(l);
      int rgroup = getgroup(r);
      if (lgroup == rgroup) {
        groupadd(lgroup);
        continue;
      }
      groupadd(lgroup);
      groupadd(rgroup);
      for (int i = lgroup + 1; i < rgroup; i++) add[i] += x;
    } else {
      long long x;
      cin >> x;
      vector<int> indexes;
      auto find = [&](int begin, int end, int add) {
        if (!binary_search(v.begin() + begin, v.begin() + end, node(x - add)))
          return false;
        for (int j = begin; j < end; j++)
          if (v[j].first == x - add) indexes.push_back(v[j].second);
        return true;
      };
      for (int i = 0; i < n / sqrtn; i++) {
        auto [begin, end] = grouplimit(i);
        if (find(begin, end, add[i])) break;
      }
      for (int i = n / sqrtn - 1; i >= 0; i--) {
        auto [begin, end] = grouplimit(i);
        if (find(begin, end, add[i])) break;
      }
      find(n / sqrtn * sqrtn, n, add[n / sqrtn]);
      if (indexes.empty())
        cout << -1 << "\n";
      else {
        auto [max, min] = minmax_element(indexes.begin(), indexes.end());
        cout << abs(*max - *min) << "\n";
      }
    }
  }
  return 0;
}
