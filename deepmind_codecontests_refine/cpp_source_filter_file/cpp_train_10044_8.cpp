#include <bits/stdc++.h>
using namespace std;
namespace my {
pair<int, int> operator+(const pair<int, int> &a, const pair<int, int> &b) {
  return {a.first + b.first, a.second + b.second};
}
pair<int, int> operator-(const pair<int, int> &a, const pair<int, int> &b) {
  return {a.first - b.first, a.second - b.second};
}
pair<int, int> operator*(const pair<int, int> &a, const pair<int, int> &b) {
  return {a.first * b.first - a.second * b.second,
          a.first * b.second + a.second * b.first};
}
pair<int, int> operator*(const pair<int, int> &a, const int &b) {
  return {a.first * b, a.second * b};
}
pair<int, int> operator/(const pair<int, int> &a, const int &b) {
  return {a.first / b, a.second / b};
}
ostream &operator<<(ostream &s, const pair<int, int> &p) {
  s << '(' << p.first << ", " << p.second << ')';
  return s;
}
}  // namespace my
using namespace my;
int n, dp[200000], t[800000], ans = 1;
vector<pair<int, int> > v;
void update(const int &v, const int &tl, const int &tr, const int &pos,
            const int &val) {
  if (pos <= tl && tr <= pos) {
    t[v] = val;
    return;
  }
  if (pos < tl || pos > tr) return;
  int tm = (tl + tr) / 2;
  update(v * 2, tl, tm, pos, val);
  update(v * 2 + 1, tm + 1, tr, pos, val);
  t[v] = max(t[v * 2], t[v * 2 + 1]);
}
int get(const int &v, const int &tl, const int &tr, const int &l,
        const int &r) {
  if (l <= tl && tr <= r) return t[v];
  if (l > tr || r < tl) return 0;
  int tm = (tl + tr) / 2;
  return max(get(v * 2, tl, tm, l, r), get(v * 2 + 1, tm + 1, tr, l, r));
}
void solve() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int first, w;
    scanf("%d %d", &first, &w);
    v.push_back({first - w, first + w});
  }
  sort(v.begin(), v.end(),
       [](const pair<int, int> &p1, const pair<int, int> &p2) {
         return p1.second < p2.second;
       });
  dp[0] = 1;
  update(1, 0, n - 1, 0, dp[0]);
  for (int i = 1; i < n; i++) {
    int pos = lower_bound(v.begin(), v.end(), v[i].first,
                          [](const pair<int, int> &p, const int &val) {
                            return p.second < val;
                          }) -
              v.begin();
    if ((pos == v.size() || v[pos].second > v[i].first) && pos - 1 >= 0)
      dp[i] = get(1, 0, n - 1, 0, pos - 1) + 1;
    else if (v[pos].second == v[i].first)
      dp[i] = get(1, 0, n - 1, 0, pos) + 1;
    else
      dp[i] = 1;
    ans = max(ans, dp[i]);
    update(1, 0, n - 1, i, dp[i]);
  }
  printf("%d", ans);
}
int main() {
  if (1) {
  } else {
    freopen("input.txt", "r", stdin);
  }
  solve();
  return 0;
}
