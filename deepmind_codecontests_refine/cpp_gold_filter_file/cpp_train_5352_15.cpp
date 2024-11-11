#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize( \
    "O3,Ofast,no-stack-protector,unroll-loops,fast-math,-ffp-contract=off")
const int N = 1e5 + 12, SQ = 317, sq = 317;
int n, q;
int a[N], ls[N], nx[N], cnt_2[N];
int cnt[N], pl1[N], pl2[N];
int qu[N], r[N], l[N], ans[N];
vector<int> vec[N], vec2[N];
inline bool cmp(int, int);
inline int in(int id, int val) {
  val = abs(val);
  return lower_bound(vec[id].begin(), vec[id].end(), val) - vec[id].begin();
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  scanf("%d", &q);
  for (int i = 0; i < q; i++) {
    scanf("%d%d", &l[i], &r[i]);
    qu[i] = i;
  }
  sort(qu, qu + q, cmp);
  for (int i = 1; i <= n; i++) {
    ls[i] = pl1[a[i]];
    pl1[a[i]] = i;
  }
  for (int i = n; i > 0; i--) {
    nx[i] = pl2[a[i]];
    pl2[a[i]] = i;
  }
  for (int i = 1; i <= n; i++)
    if (ls[i] != 0) vec[a[i]].push_back(i - ls[i]);
  for (int i = 0; i < N; i++) {
    if (vec[i].size() == 0) continue;
    sort(vec[i].begin(), vec[i].end());
    vec[i].resize(unique(vec[i].begin(), vec[i].end()) - vec[i].begin());
    vec2[i].resize(vec[i].size());
  }
  int L = 1, R = 1;
  int good = 1, dif = 1;
  cnt[a[1]]++;
  for (int ii = 0; ii < q; ii++) {
    int i = qu[ii];
    while (R < r[i]) {
      R++;
      int X = a[R];
      cnt[X]++;
      if (cnt[X] == 1) {
        dif++;
        good++;
      } else if (ls[R]) {
        int val = cnt_2[X];
        int ind = in(X, R - ls[R]);
        vec2[X][ind]++;
        if (vec2[X][ind] == 1) cnt_2[X]++;
        if (val <= 1 && cnt_2[X] > 1) good--;
      }
    }
    while (L > l[i]) {
      L--;
      int X = a[L];
      cnt[X]++;
      if (cnt[X] == 1) {
        dif++;
        good++;
      } else if (nx[L]) {
        int val = cnt_2[X];
        int ind = in(X, nx[L] - L);
        vec2[X][ind]++;
        if (vec2[X][ind] == 1) cnt_2[X]++;
        if (val <= 1 && cnt_2[X] > 1) good--;
      }
    }
    while (R > r[i]) {
      int X = a[R];
      cnt[X]--;
      if (cnt[X] == 0) {
        good--;
        dif--;
      } else if (ls[R]) {
        int val = cnt_2[X];
        int ind = in(X, R - ls[R]);
        vec2[X][ind]--;
        if (vec2[X][ind] == 0) cnt_2[X]--;
        if (cnt_2[X] <= 1 && val > 1) good++;
      }
      R--;
    }
    while (L < l[i]) {
      int X = a[L];
      cnt[X]--;
      if (cnt[X] == 0) {
        good--;
        dif--;
      } else if (nx[L]) {
        int val = cnt_2[X];
        int ind = in(X, nx[L] - L);
        vec2[X][ind]--;
        if (vec2[X][ind] == 0) cnt_2[X]--;
        if (cnt_2[X] <= 1 && val > 1) good++;
      }
      L++;
    }
    ans[i] = dif + (!((bool)(good)));
  }
  for (int i = 0; i < q; i++) printf("%d\n", ans[i]);
  return 0;
}
inline bool cmp(int f, int s) {
  if (f == s) return 0;
  if ((l[f] / SQ) != (l[s] / SQ)) return l[f] < l[s];
  if ((l[f] / sq) % 2 == 0) return r[f] < r[s];
  return r[s] < r[f];
}
