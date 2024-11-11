#include <bits/stdc++.h>
using namespace std;
const int maxn = 5050;
const int inf = 0x3f3f3f3f;
int s[maxn], dp[2][maxn];
double x[maxn];
vector<vector<int> > ret;
int cnt[maxn], n, m;
inline void add(int p, int c) {
  for (; p <= n; p += p & -p) cnt[p] += c;
}
inline int sum(int p) {
  int res = 0;
  for (; p; p -= p & -p) res += cnt[p];
  return res;
}
pair<int, int> tmp[maxn];
int val[maxn];
int main() {
  scanf("%d %d", &n, &m);
  ret.resize(m + 1);
  for (int i = 1; i <= n; ++i) {
    scanf("%d %lf", &s[i], &x[i]);
    tmp[i].first = s[i];
    tmp[i].second = i;
  }
  sort(tmp + 1, tmp + n + 1);
  int l = 0;
  for (int i = 1; i <= n; ++i) {
    int p = lower_bound(val, val + l, tmp[i].second) - val;
    val[p] = tmp[i].second;
    if (p == l) ++l;
  }
  cout << n - l << endl;
  return 0;
}
