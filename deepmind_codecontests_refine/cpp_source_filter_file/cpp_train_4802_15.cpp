#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3f;
template <typename T, typename T2>
inline void _max(T &a, T2 b) {
  a = max((T)a, (T)b);
}
template <typename T, typename T2>
inline void _min(T &a, T2 b) {
  a = min((T)a, (T)b);
}
const int MAXV = 3.5 * 1e6;
const int MAX = 2e5 + 10;
int n, x[MAX];
map<int, int> m[MAX];
void clear() {}
void read() {
  for (int i = 0; i < n / 2; i++) scanf("%d", &x[i]);
}
map<int, int> getSplit(int a) {
  vector<pair<int, int> > res;
  for (int m1 = 1; m1 * m1 < a; m1++) {
    if (a % m1) continue;
    int m2 = a / m1;
    if ((m1 + m2) % 2) continue;
    int x = (m2 - m1) / 2;
    int y = (m1 + m2) / 2;
    assert(y > x);
    assert(x > 0);
    assert(y > 0);
    res.push_back({x, y});
  }
  return map<int, int>(res.begin(), res.end());
}
void solve() {
  for (int i = 0; i < n / 2; i++) m[i] = getSplit(x[i]);
  for (int i = n / 2 - 1; i > 0; i--) {
    auto &l = m[i - 1], &r = m[i];
    if (r.size() == 0) return void(printf("No\n"));
    auto mx = prev(r.end())->first;
    vector<int> keys;
    for (auto &p : l) keys.push_back(p.first);
    for (auto &x : keys)
      if (l[x] >= mx) l.erase(x);
  }
  if (m[0].size() == 0) return void(printf("No\n"));
  printf("Yes\n");
  vector<int> b;
  for (int i = 0; i < n / 2; i++) {
    auto &p = *prev(m[i].end());
    b.push_back(p.first);
    b.push_back(p.second);
  }
  vector<long long> res;
  res.push_back(1ll * b[0] * b[0]);
  for (int i = 1; i < b.size(); i++)
    res.push_back(1ll * b[i] * b[i] - 1ll * b[i - 1] * b[i - 1]);
  for (auto &x : res) printf("%d ", x);
  printf("\n");
}
int main() {
  while (scanf("%d", &n) == 1) {
    clear();
    read();
    solve();
    return 0;
  }
  return 0;
}
