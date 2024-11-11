#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int n, m;
struct P {
  int x, y;
  P(int a = 0, int b = 0) : x(a), y(b) {}
  bool operator<(const P& tt) const {
    if (x == tt.x) return y < tt.y;
    return x < tt.x;
  }
};
vector<pair<P, int> > vec;
vector<pair<int, int> > v2;
multiset<int> st;
long long ans[N];
bool cmp(pair<P, int> a, pair<P, int> b) {
  if (a.first.x != b.first.x) return a.first.x < b.first.x;
  if (a.second != b.second) return a.second < b.second;
  return a.first.y < b.first.y;
}
int in[N][3];
int main() {
  int a, b, c;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; ++i) {
    scanf("%d%d%d", &a, &b, &c);
    in[i][0] = a;
    in[i][1] = b;
    in[i][2] = c;
    vec.push_back(make_pair(P(a, c), -1));
    vec.push_back(make_pair(P(b, c), 0));
  }
  sort(vec.begin(), vec.end(), cmp);
  for (const auto& t : vec)
    if (t.second == -1) {
      if (st.empty() || *st.begin() > t.first.y) {
        v2.emplace_back(t.first.y - t.first.x, -1);
        auto it = st.upper_bound(t.first.y);
        if (it != st.end()) v2.emplace_back(*it - t.first.x, 0);
      }
      st.insert(t.first.y);
    } else
      st.erase(st.find(t.first.y));
  vec.clear();
  for (int i = 1; i <= m; ++i) {
    a = -in[i][1];
    b = -in[i][0];
    c = in[i][2];
    vec.push_back(make_pair(P(a, c), -1));
    vec.push_back(make_pair(P(b, c), 0));
  }
  sort(vec.begin(), vec.end(), cmp);
  st.clear();
  for (const auto& t : vec)
    if (t.second == -1) {
      if (st.empty() || *st.begin() > t.first.y) {
        v2.emplace_back(t.first.y + t.first.x, 0);
        auto it = st.upper_bound(t.first.y);
        if (it != st.end()) v2.emplace_back(*it + t.first.x, -1);
      }
      st.insert(t.first.y);
    } else
      st.erase(st.find(t.first.y));
  for (int i = 1; i <= n; ++i) scanf("%d", &a), v2.emplace_back(a, i);
  sort(v2.begin(), v2.end());
  long long sum = 0, dx = 0, last = v2.front().first, cur;
  for (const auto& t : v2) {
    cur = t.first;
    sum += (cur - last) * dx;
    last = cur;
    if (t.second > 0)
      ans[t.second] = sum;
    else if (!t.second)
      ++dx;
    else
      --dx;
  }
  for (int i = 1; i <= n; ++i) printf("%I64d\n", ans[i]);
  return 0;
}
