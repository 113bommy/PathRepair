#include <bits/stdc++.h>
using namespace std;
namespace debug {
void __(short x) { cout << x; }
void __(unsigned x) { cout << x; }
void __(int x) { cout << x; }
void __(long long x) { cout << x; }
void __(unsigned long long x) { cout << x; }
void __(double x) { cout << x; }
void __(long double x) { cout << x; }
void __(char x) { cout << x; }
void __(const char* x) { cout << x; }
void __(const string& x) { cout << x; }
void __(bool x) { cout << (x ? "true" : "false"); }
template <class P1, class P2>
void __(const pair<P1, P2>& x) {
  __("("), __(x.first), __(", "), __(x.second), __(")");
}
template <class T>
void __(const vector<T>& x) {
  __("{");
  bool _ffs = 0;
  for (const auto& v : x) __(_ffs ? ", " : ""), __(v), _ffs = 1;
  __("}");
}
template <class T>
void __(const set<T>& x) {
  __("{");
  bool _ffs = 0;
  for (const auto& v : x) __(_ffs ? ", " : ""), __(v), _ffs = 1;
  __("}");
}
template <class T, class T2>
void __(const map<T, T2>& x) {
  __("{");
  bool _ffs = 0;
  for (const auto& v : x)
    __(_ffs ? ", " : ""), __(make_pair(v.first, v.second)), _ffs = 1;
  __("}");
}
void screm() { __("\n"); }
template <class T1, class... T2>
void screm(const T1& t1, const T2&... t2) {
  __(t1);
  if (sizeof...(t2))
    __(" | "), screm(t2...);
  else
    __("\n");
}
void pr() { __("\n"); }
template <class T1, class... T2>
void pr(const T1& t1, const T2&... t2) {
  __(t1);
  if (sizeof...(t2))
    __(" "), pr(t2...);
  else
    __("\n");
}
}  // namespace debug
using namespace debug;
const int MN = 3e5 + 5;
int T, N, arr[MN], i, j, x, id[MN], nxt, cnt[MN];
long long ans;
map<int, int> mp[MN];
int main() {
  scanf("%d", &T);
  for (int q = (1); q <= (T); q++) {
    scanf("%d", &N);
    for (int i = (1); i <= (N); i++) scanf("%d", &arr[i]);
    for (int i = (1); i <= (min(N * 3 + 1, MN - 1)); i++)
      id[i] = 0, cnt[i] = 0, mp[i].clear();
    ans = nxt = i = j = x = 0;
    id[1] = ++nxt;
    mp[id[1]][arr[1]] = 1;
    for (int i = (2); i <= (N); i++) {
      if (mp[id[i - 1]].count(arr[i])) {
        x = mp[id[i - 1]][arr[i]];
        cnt[i] = cnt[x - 1] + 1;
        ans += cnt[i];
        id[i] = id[x - 1];
        mp[id[i]][arr[i]] = i;
      } else {
        id[i] = ++nxt;
        mp[id[i]][arr[i]] = i;
      }
    }
    printf("%lld\n", ans);
  }
  return 0;
}
