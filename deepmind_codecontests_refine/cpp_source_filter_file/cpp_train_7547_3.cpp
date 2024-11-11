#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;
const int INF = 0x7FFFFFFF;
const int MOD = 1e9 + 7;
const double EPS = 1e-10;
const double PI = 2 * acos(0.0);
const int maxn = 1e6 + 66;
int aa[maxn], bb[maxn], Left[maxn], Right[maxn];
int main() {
  int n, q;
  while (scanf("%d %d", &n, &q) != EOF) {
    for (int i = 1; i <= n; i++) scanf("%d", &aa[i]);
    for (int i = 1; i <= n - 1; i++) bb[i] = abs(aa[i + 1] - aa[i]);
    stack<pair<int, int> > sta;
    sta.push(pair<int, int>(0, INF));
    for (int i = 1; i <= n - 1; i++) {
      while (!sta.empty() && bb[i] > sta.top().second) sta.pop();
      Left[i] = sta.top().first;
      sta.push(pair<int, int>(i, bb[i]));
    }
    while (!sta.empty()) sta.pop();
    sta.push(pair<int, int>(n, INF));
    for (int i = n - 1; i >= 1; i--) {
      while (!sta.empty() && bb[i] >= sta.top().second) sta.pop();
      Right[i] = sta.top().first;
      sta.push(pair<int, int>(i, bb[i]));
    }
    int l, r;
    for (int i = 1; i <= q; i++) {
      scanf("%d%d", &l, &r);
      long long res = 0;
      for (int j = l; j <= r - 1; j++) {
        int a = max(Left[j], l - 1);
        int b = min(Right[j], r);
        res += (long long)bb[j] * ((j - a) * (b - j));
      }
      printf("%I64d\n", res);
    }
  }
  return 0;
}
