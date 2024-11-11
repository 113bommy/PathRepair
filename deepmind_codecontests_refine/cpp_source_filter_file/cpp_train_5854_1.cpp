#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
template <class c>
struct rge {
  c b, e;
};
template <class c>
rge<c> range(c i, c j) {
  return rge<c>{i, j};
}
template <class c>
auto dud(c *r) -> decltype(cerr << *r);
template <class c>
char dud(...);
struct muu {
  template <class c>
  muu &operator<<(const c &) {
    return *this;
  }
};
using pii = pair<int, int>;
using ld = long double;
using ll = long long;
const int maxn = 4 * 100007;
vector<int> v[maxn];
int oj[maxn];
int odl[maxn];
int finder(int x) {
  if (oj[x] == x) return x;
  return oj[x] = finder(oj[x]);
}
void unioner(int a, int b) {
  a = finder(a), b = finder(b);
  oj[a] = b;
}
int moj[maxn][20];
int mgl[maxn];
int pre[maxn], pos[maxn];
int zeit = 0;
void dfs(int a, int sk, int gl) {
  moj[a][0] = sk;
  mgl[a] = gl;
  for (int i = 1; i < 20; i++) moj[a][i] = moj[moj[a][i - 1]][i - 1];
  pre[a] = ++zeit;
  for (auto it : v[a])
    if (it != sk) dfs(it, a, gl + 1);
  pos[a] = zeit;
}
bool isOj(int a, int b) { return pre[a] <= pre[b] && pos[b] <= pos[a]; }
int lca(int a, int b) {
  if (isOj(a, b)) return a;
  int ter = 19;
  while (ter >= 0) {
    if (isOj(moj[a][ter], b))
      ter--;
    else
      a = moj[a][ter];
  }
  return moj[a][0];
}
int skacz(int a, int ile) {
  for (int i = 1, ter = 0; i <= ile; i *= 2, ter++)
    if ((i & ile)) a = moj[a][ter];
  return a;
}
int main() {
  int N, K, R;
  scanf("%d%d%d", &N, &K, &R);
  for (int i = 2; i <= N; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    v[a].push_back(i + N);
    v[i + N].push_back(b);
    v[b].push_back(i + N);
    v[i + N].push_back(a);
  }
  for (int i = 1; i <= 2 * N; i++) oj[i] = i;
  queue<int> Q;
  memset(odl, -1, sizeof(odl));
  for (int i = 1; i <= R; i++) {
    int a;
    scanf("%d", &a);
    Q.push(a);
    odl[a] = 0;
  }
  while (!Q.empty()) {
    int a = Q.front();
    Q.pop();
    if (odl[a] == K) continue;
    for (auto it : v[a]) {
      if (odl[it] > odl[a] + 1) {
        odl[it] = odl[a] + 1;
        Q.push(it);
      }
      unioner(a, it);
    }
  }
  dfs(1, 1, 0);
  int T;
  scanf("%d", &T);
  while (T--) {
    int a, b;
    scanf("%d%d", &a, &b);
    int c = lca(a, b);
    int odl = mgl[a] - mgl[c] + mgl[b] - mgl[c];
    if (odl <= 2 * K)
      printf("YES\n");
    else {
      int na;
      if (mgl[a] - mgl[c] < K)
        na = skacz(b, mgl[b] - mgl[c] - (K - (mgl[a] - mgl[c])));
      else
        na = skacz(a, K);
      int nb;
      if (mgl[b] - mgl[c] < K)
        nb = skacz(a, mgl[a] - mgl[c] - (K - (mgl[b] - mgl[c])));
      else
        nb = skacz(b, K);
      printf(finder(na) == finder(nb) ? "YES\n" : "NO\n");
    }
  }
  return 0;
}
