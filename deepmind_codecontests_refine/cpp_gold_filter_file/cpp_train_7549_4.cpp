#include <bits/stdc++.h>
using namespace std;
const int inf = ~0U >> 1;
const long long INF = ~0ULL >> 1;
template <class T>
inline void read(T &n) {
  char c;
  int flag = 1;
  for (c = getchar(); !(c >= '0' && c <= '9' || c == '-'); c = getchar())
    ;
  if (c == '-')
    flag = -1, n = 0;
  else
    n = c - '0';
  for (c = getchar(); c >= '0' && c <= '9'; c = getchar()) n = n * 10 + c - '0';
  n *= flag;
}
const int maxn = 120000;
int N, M, x, y;
int inq[maxn], f[maxn];
vector<pair<int, int> > E[maxn];
queue<int> Q;
int check(int K) {
  int ans = 0;
  for (int i = (1); i <= (N); ++i) inq[i] = f[i] = 0;
  for (int i = (1); i <= (N); ++i) {
    for (auto j : E[i])
      if (j.second <= K) ++inq[j.first];
  }
  for (int i = (1); i <= (N); ++i)
    if (!inq[i]) Q.push(i);
  while (Q.size()) {
    int u = Q.front();
    Q.pop();
    ans = max(ans, f[u] + 1);
    for (auto v : E[u])
      if (v.second <= K) {
        --inq[v.first];
        f[v.first] = max(f[v.first], f[u] + 1);
        if (!inq[v.first]) Q.push(v.first);
      }
  }
  return ans == N;
}
int main(int argc, char *argv[]) {
  scanf("%d%d", &N, &M);
  for (int i = (1); i <= (M); ++i)
    scanf("%d%d", &x, &y), E[x].push_back((make_pair(y, i)));
  int l = 1, r = M;
  while (l + 1 < r) {
    int m = l + r >> 1;
    if (check(m))
      r = m;
    else
      l = m + 1;
  }
  while (l <= M && !check(l)) ++l;
  if (l == M + 1) l = -1;
  printf("%d\n", l);
  return 0;
}
