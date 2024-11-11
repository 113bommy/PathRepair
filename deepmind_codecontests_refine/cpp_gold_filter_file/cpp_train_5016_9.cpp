#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline void MIN(T &a, T b) {
  if (a > b) a = b;
}
template <typename T>
inline void MAX(T &a, T b) {
  if (a < b) a = b;
}
const int N = 200005;
int n, k, dd[N], p[N];
char ans[N];
pair<int, int> a[N * 2], b[N * 2];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> k;
  for (int i = (1); i <= (n); ++i) {
    cin >> p[i];
    dd[p[i]] = i;
  }
  int prv, now, cnt = 0;
  for (int i = (1); i <= (n); ++i) {
    if (i >= 2) prv = now;
    cin >> now;
    a[++cnt] = make_pair(now, now);
    if ((i >= 2) && (dd[prv] > dd[now])) a[++cnt] = make_pair(dd[now], dd[prv]);
  }
  sort(a + 1, a + cnt + 1, [](pair<int, int> x, pair<int, int> y) {
    return (x.first < y.first) ||
           ((x.first == y.first) && (x.second > y.second));
  });
  int newCnt = 0, id = 1;
  while (id <= cnt) {
    int pv = id;
    for (; id + 1 <= cnt && a[id + 1].second <= a[pv].second; ++id)
      ;
    b[++newCnt] = a[pv];
    ++id;
  }
  int Union = 0;
  id = 1;
  while (id <= newCnt) {
    int pv = id;
    for (; id + 1 <= newCnt && b[id + 1].first <= b[id].second; ++id)
      ;
    b[++Union] = make_pair(b[pv].first, b[id].second);
    ++id;
  }
  if (Union < k) return cout << "NO", 0;
  cout << "YES\n";
  char x = 'a' - 1;
  for (int i = (1); i <= (Union); ++i) {
    x = min(char((int)x + 1), 'z');
    for (int l = (b[i].first); l <= (b[i].second); ++l) ans[p[l]] = char(x);
  }
  for (int i = (1); i <= (n); ++i) cout << ans[i];
  return 0;
}
