#include <bits/stdc++.h>
using namespace std;
template <class T>
inline bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
inline bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}
template <typename A, size_t N, typename T>
void Fill(A (&array)[N], const T& val) {
  fill((T*)array, (T*)(array + N), val);
}
const int inf = INT_MAX / 2;
const long long int INF = LLONG_MAX / 2;
vector<int> g[100010];
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  vector<pair<long long int, long long int> > check(m);
  for (int i = (0); i < (m); i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    x--;
    y--;
    g[x].push_back(y);
    g[y].push_back(x);
    check[i] = {x, y};
  }
  int ans[100010] = {};
  int idx = 0;
  for (int st = (1); st < (4); st++) {
    while (idx < n && ans[idx]) idx++;
    if (idx == n) {
      printf("-1\n");
      return 0;
    }
    ans[idx] = st;
    bool used[100010] = {};
    used[idx] = 1;
    for (int nxt : g[idx]) {
      used[nxt] = 1;
    }
    for (int i = (0); i < (n); i++)
      if (!used[i]) {
        if (ans[i] && ans[i] != st) {
          printf("-1\n");
          return 0;
        }
        ans[i] = st;
      }
  }
  bool f = 1;
  int cnt[3] = {};
  for (int i = (0); i < (n); i++) {
    if (ans[i] == 0) f = 0;
    cnt[ans[i]]++;
  }
  for (int i = (0); i < (m); i++) {
    if (ans[check[i].first] == ans[check[i].second]) f = 0;
  }
  if (m != cnt[0] * cnt[1] + cnt[1] * cnt[2] + cnt[2] * cnt[0]) f = 0;
  if (f)
    for (int i = (0); i < (n); i++) printf("%d\n", ans[i]);
  else
    printf("-1\n");
  return 0;
}
