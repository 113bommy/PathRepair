#include <bits/stdc++.h>
using namespace std;
const int maxn = 50;
int a[maxn];
int n;
int b[maxn];
pair<int, int> Q[maxn];
int ans[maxn];
int main() {
  while (~scanf("%d", &n)) {
    for (int i = 0; i < n; i++) {
      scanf("%d", &Q[i].first);
      Q[i].second = i;
    }
    sort(Q, Q + n);
    for (int i = 0; i < n; i++) {
      if (i == n - 1) {
        ans[Q[i].second] = Q[0].first;
      } else {
        ans[Q[i].second] = Q[i + 1].first;
      }
    }
    for (int i = 0; i < n; i++) {
      printf("%d%c", ans[i], i == n - 1 ? '\n' : ' ');
    }
  }
}
