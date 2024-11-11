#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000007;
const double eps = 1e-10;
const int MAXN = 100010;
int n;
int t[MAXN];
int a[MAXN], b[MAXN], c[MAXN], d[MAXN];
int main() {
  while (cin >> n) {
    for (int i = 0; i < (n); ++i) scanf("%d", &t[i]);
    for (int i = (0); i <= (n); ++i) a[i] = 1e6, d[i] = 1;
    int maxb = 1;
    for (int i = 0; i < (n); ++i) {
      int x = lower_bound(a, a + i + 1, t[i]) - a;
      a[x] = t[i];
      b[i] = x + 1;
      maxb = max(maxb, b[i]);
    }
    for (int i = (0); i <= (maxb); ++i) c[i] = -1;
    c[maxb + 1] = 1e6;
    for (int i = 0; i < (n + 1); ++i) a[i] = 0;
    for (int i = (n - 1); i >= (0); --i) {
      if (t[i] < c[b[i] + 1]) {
        d[i] = 2;
        c[b[i]] = max(t[i], c[b[i]]);
      }
    }
    for (int i = 0; i < (n); ++i) {
      if (d[i] == 2) {
        a[b[i]]++;
      }
    }
    for (int i = 0; i < (n); ++i) {
      if (d[i] == 2 && a[b[i]] == 1) d[i]++;
      printf("%d", d[i]);
    }
    puts("");
  }
  return 0;
}
