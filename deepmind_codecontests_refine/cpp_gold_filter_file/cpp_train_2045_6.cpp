#include <bits/stdc++.h>
using namespace std;
const int inf = 0x0f0f0f0f;
template <class S, class T>
inline pair<S, T> MP(S a, T b) {
  return make_pair(a, b);
}
template <class T>
inline auto LX(T &X) -> decltype((X.first)) {
  return X.first;
}
template <class T>
inline auto LX(const T &X) -> const decltype((X.first)) {
  return X.first;
}
template <class T>
inline auto RX(T &X) -> decltype((X.second)) {
  return X.second;
}
template <class T>
inline auto RX(const T &X) -> const decltype((X.second)) {
  return X.second;
}
template <class T>
inline void RST(T &a) {
  memset(a, 0, sizeof(a));
}
template <class T>
inline void RST1(T &a) {
  memset(a, -1, sizeof(a));
}
template <class T>
inline void SINF(T &a) {
  memset(a, 0x0f, sizeof(a));
}
template <class S, class T>
inline void RST(S &a, T b) {
  fill((T *)a, (T *)a + (sizeof(a) / sizeof(b)), b);
}
template <class T>
inline void CLR(T &a) {
  a.clear();
}
template <class S, class T>
inline void CPY(S &a, T &b) {
  memcpy(a, b, sizeof(a));
}
template <class S, class T>
inline bool chkmin(S &a, T b) {
  return b < a ? a = b, 1 : 0;
}
template <class S, class T>
inline bool chkmax(S &a, T b) {
  return a < b ? a = b, 1 : 0;
}
template <class T>
inline T sqr(T x) {
  return x * x;
}
template <class T>
inline int SZ(T &a) {
  return (int)(a.size());
}
template <class T>
inline bool EPT(T &a) {
  return a.empty();
}
template <class T>
inline auto FRT(T &a) -> decltype((a.front())) {
  return a.front();
}
template <class T>
inline auto FRT(const T &a) -> const decltype((a.front())) {
  return a.front();
}
template <class T>
inline auto BK(T &a) -> decltype(a.back()) & {
  return a.back();
}
template <class T>
inline auto BK(const T &a) -> const decltype((a.back())) {
  return a.back();
}
template <class T>
inline auto TOP(T &a) -> decltype((a.top())) {
  return a.top();
}
template <class T>
inline auto TOP(const T &a) -> const decltype((a.top())) {
  return a.top();
}
int n;
int a[100010];
bool v[100010];
vector<vector<int> > ans[6];
vector<int> f, g;
void add(const vector<int> &x) {
  int n = SZ(g);
  g.resize(n + SZ(x));
  for (int i = 0; i < SZ(x); i++)
    f.push_back(x[i]), g[i ? i + n - 1 : SZ(g) - 1] = x[i];
}
void print() {
  printf("%d\n", SZ(f));
  for (int i : f) printf("%d ", i);
  putchar('\n');
  for (int i : g) printf("%d ", i);
  putchar('\n');
  CLR(f);
  CLR(g);
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", a + i);
  for (int i = 1; i <= n; i++)
    while (!v[i]) {
      vector<int> t;
      t.push_back(i);
      int j;
      for (j = a[i]; j != i && SZ(t) < 5; j = a[j]) v[j] = 1, t.push_back(j);
      v[i] = i == j;
      a[i] = j;
      ans[SZ(t)].push_back(t);
    }
  while (SZ(ans[3]) > SZ(ans[2]) + 2) {
    vector<int> x = BK(ans[3]);
    ans[3].pop_back();
    vector<int> y;
    y.push_back(x[0]), y.push_back(x[1]);
    ans[2].push_back(y);
    CLR(y);
    y.push_back(x[1]), y.push_back(x[2]);
    ans[2].push_back(y);
  }
  int ret = SZ(ans[2]) - SZ(ans[3]) + 1;
  ret = ret < 0 ? 0 : ret / 2;
  ret += SZ(ans[5]) + SZ(ans[4]) + SZ(ans[3]);
  printf("%d\n", ret);
  for (auto &x : ans[5]) add(x), print();
  for (auto &x : ans[4]) add(x), print();
  for (auto &x : ans[3]) {
    add(x);
    if (SZ(ans[2])) add(BK(ans[2])), ans[2].pop_back();
    print();
  }
  while (SZ(ans[2])) {
    add(BK(ans[2])), ans[2].pop_back();
    if (SZ(ans[2])) add(BK(ans[2])), ans[2].pop_back();
    print();
  }
  return 0;
}
