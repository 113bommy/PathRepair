#include <bits/stdc++.h>
using namespace std;
const int maxn = 200002;
int n, cnt;
vector<pair<pair<int, int>, int>> vec;
set<int> axis;
map<int, int> as;
int ans[maxn];
int C[maxn];
inline int lowbit(int x) { return x & (-x); }
inline int sum(int x) {
  int ret = 0;
  while (x > 0) {
    ret += C[x];
    x -= lowbit(x);
  }
  return ret;
}
inline void add(int x, int d) {
  while (x <= cnt) {
    C[x] += d;
    x += lowbit(x);
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    vec.push_back(make_pair(make_pair(x, y), i));
    axis.insert(x);
    axis.insert(y);
  }
  cnt = 0;
  for (int x : axis) {
    as[x] = ++cnt;
  }
  sort(vec.begin(), vec.end());
  for (int i = 0; i < n; i++) {
    vec[i].first = make_pair(as[vec[i].first.first], as[vec[i].first.second]);
  }
  memset((C), 0, sizeof(C));
  for (int i = n - 1; i >= 0; i--) {
    ans[vec[i].second] = sum(vec[i].first.second);
    add(vec[i].first.second, 1);
  }
  for (int i = 0; i < n; i++) {
    cout << ans[i] << endl;
  }
  return 0;
}
