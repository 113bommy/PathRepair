#include <bits/stdc++.h>
using namespace std;
const int N = 1e6;
struct query {
  int a;
  int b;
} q[N];
vector<int> vec[N];
int a[N], b[N], p[N], dp1[N], dp2[N], a1[N], a2[N], cnt[N];
int n;
void LIS() {
  for (int i = 0; i < n; i++) p[i] = 1e9 + 9;
  p[0] = 0;
  for (int i = 1; i <= n; i++) {
    dp1[i] = lower_bound(p, p + n, a[i]) - p;
    for (int j = 0; j < vec[i].size(); j++) {
      int id = vec[i][j];
      a1[id] = lower_bound(p, p + n, q[id].b) - p;
    }
    p[dp1[i]] = min(p[dp1[i]], a[i]);
  }
}
void LDS() {
  for (int i = 0; i < n; i++) p[i] = 0;
  p[0] = -1e9 - 9;
  for (int i = 1; i <= n; i++) {
    dp2[i] = lower_bound(p, p + n, b[i]) - p;
    for (int j = 0; j < vec[n + 1 - i].size(); j++) {
      int id = vec[n + 1 - i][j];
      a2[id] = lower_bound(p, p + n, -q[id].b) - p;
    }
    p[dp2[i]] = min(p[dp2[i]], b[i]);
  }
}
int main() {
  int m;
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    b[n + 1 - i] = -a[i];
  }
  for (int i = 0; i < m; i++) {
    scanf("%d %d", &q[i].a, &q[i].b);
    vec[q[i].a].push_back(i);
  }
  LIS();
  LDS();
  int mx = 0;
  for (int i = 1; i <= n; i++) mx = max(mx, dp1[i]);
  for (int i = 1; i <= n; i++) {
    if (dp1[i] + dp2[n + 1 - i] == mx + 1) cnt[dp1[i]]++;
  }
  for (int i = 0; i < m; i++) {
    int t = mx;
    int id = q[i].a;
    if (dp1[id] + dp2[n + 1 - id] == mx + 1 && cnt[dp1[id]] == 1) t--;
    t = max(t, a1[i] + a2[i] - 1);
    printf("%d\n", t);
  }
  return 0;
}
