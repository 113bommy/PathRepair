#include <bits/stdc++.h>
using namespace std;
int getint() {
  int s = 0, o = 1;
  char c;
  for (c = getchar(); c < '0' || c > '9'; c = getchar())
    if (c == '-') o = -1;
  for (; c >= '0' && c <= '9'; c = getchar()) s *= 10, s += c - '0';
  return s * o;
}
const long long MOD = (long long)1e9 + 7;
const unsigned long long inf = (long long)1e18;
const int maxn = 100001;
std::vector<int> e[maxn];
std::vector<int> ans;
int cnt[maxn][2], CNT[maxn][2], bad[maxn];
int n, m, k;
bool check(double p) {
  int l = 0, r = 0;
  static int q[maxn], tmp[maxn];
  memset(tmp, 0, sizeof(tmp));
  for (int i = 1; i < 1 + n; i++) cnt[i][0] = CNT[i][0], cnt[i][1] = CNT[i][1];
  for (int i = 1; i < 1 + n; i++)
    if (!bad[i] && cnt[i][0] * (1 - p) < cnt[i][1] * p) {
      q[r++] = i;
      tmp[i] = 1;
    }
  while (l < r) {
    int u = q[l++];
    for (int i = 0; i < e[u].size(); i++) {
      int v = e[u][i];
      cnt[v][0]--, cnt[v][1]++;
      if (!tmp[v] && !bad[v] && cnt[v][0] * (1 - p) < cnt[v][1] * p) {
        q[r++] = v;
        tmp[v] = 1;
      }
    }
  }
  std::vector<int> v;
  for (int i = 1; i < 1 + n; i++)
    if (!bad[i] && !tmp[i]) v.push_back(i);
  if (((int)(v).size())) {
    ans = v;
    return 1;
  } else
    return 0;
}
int main(int argc, char const *argv[]) {
  cin >> n >> m >> k;
  for (int i = 1; i < 1 + k; i++) bad[getint()] = 1;
  for (int mm = 0; mm < m; mm++) {
    int x, y;
    cin >> x >> y;
    e[x].push_back(y), e[y].push_back(x);
    CNT[x][bad[y]]++;
    CNT[y][bad[x]]++;
  }
  double l = 0, r = 1.1;
  for (int step = 0; step < 50; step++) {
    double p = (l + r) / 2;
    if (check(p))
      l = p;
    else
      r = p;
  }
  check(l);
  printf("%d\n", ((int)(ans).size()));
  for (int i = 0; i < ((int)(ans).size()); i++) printf("%d ", ans[i]);
}
