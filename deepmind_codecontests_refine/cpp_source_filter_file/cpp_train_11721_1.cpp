#include <bits/stdc++.h>
using namespace std;
const int N = 100000 + 7;
const int M = 20;
const int inf = 1e9 + 7;
const long long linf = 1e18 + 7;
const double pi = acos(-1);
const double eps = 1e-7;
const bool multipleTest = 0;
int n;
int a[N];
int MAGIC = 1000;
int cnt[N];
int res[N];
int st[N], sl = 0;
int calc(int k) {
  if (res[k] > 0) return res[k];
  int tol = 0;
  int cur = 0;
  sl = 0;
  for (int i = 1; i <= n;) {
    int j = i;
    while (j <= n) {
      if (cnt[a[j]] != 0) {
        ++cnt[a[j]];
        st[sl++] = a[j];
        ++j;
      } else {
        if (cur == k) {
          cur = 0;
          while (sl > 0) {
            --sl;
            --cnt[st[sl]];
          }
          break;
        } else {
          st[sl++] = a[j];
          cnt[a[j]]++;
          cur++;
          j++;
        }
      }
    }
    ++tol;
    i = j;
  }
  while (sl > 0) {
    --sl;
    --cnt[st[sl]];
  }
  return res[k] = tol;
}
void solve() {
  cin >> n;
  for (int i = (1); i < (n + 1); i++) {
    scanf("%d", a + i);
  }
  for (int k = (1); k < (min(n + 1, MAGIC)); k++) calc(k);
  if (MAGIC < n) {
    int tmp = ::calc(MAGIC);
    int lo = MAGIC;
    while (lo <= n) {
      int l = lo + 1, r = n, rr = lo;
      while (l <= r) {
        int g = (l + r) >> 1;
        if (calc(g) == tmp) {
          rr = g;
          l = g + 1;
        } else
          r = g - 1;
      }
      while (lo <= rr) res[lo++] = tmp;
      if (lo <= n) tmp = calc(lo);
    }
  }
  for (int i = (1); i < (n + 1); i++) printf("%d ", res[i]);
}
int main() {
  int Test = 1;
  if (multipleTest) {
    cin >> Test;
  }
  for (int i = 0; i < Test; ++i) {
    solve();
  }
}
