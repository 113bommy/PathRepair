#include <bits/stdc++.h>
using namespace std;
const int maxn = 200005;
const int mlog = 32;
int n;
int p[maxn];
int L[maxn][35], R[maxn][35];
int posL[maxn], posR[maxn];
int a[maxn];
set<int> s;
bool cmp(int x, int y) { return p[x] > p[y]; }
int main() {
  long long ans = 0;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &p[i]);
  for (int i = 0; i <= mlog; i++) L[0][i] = 0, R[n + 1][i] = n + 1;
  for (int i = 1; i <= n; i++) posL[i] = 0, posR[i] = n + 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= mlog; j++) L[i][j] = L[i - 1][j];
    for (int j = 0; j <= mlog; j++)
      if (p[i] & (1 << j)) L[i][j] = i;
    for (int j = 0; j <= mlog; j++)
      if ((p[i] & (1 << j)) == 0) posL[i] = max(posL[i], L[i][j]);
  }
  for (int i = n; i >= 1; i--) {
    for (int j = 0; j <= mlog; j++) R[i][j] = R[i + 1][j];
    for (int j = 0; j <= mlog; j++)
      if (p[i] & (1 << j)) R[i][j] = i;
    for (int j = 0; j <= mlog; j++)
      if ((p[i] & (1 << j)) == 0) posR[i] = min(posR[i], R[i][j]);
  }
  for (int i = 1; i <= n; i++) a[i] = i;
  sort(&a[1], &a[n + 1], cmp);
  s.insert(0);
  s.insert(n + 1);
  for (int i = 1; i <= n; i++) {
    int x = a[i];
    s.insert(x);
    auto it = s.find(x);
    auto il = it, ir = it;
    il--;
    ir++;
    ans += (long long)(x - *il) * (*ir - x) -
           (long long)(x - max(*il, posL[x])) * (min(*ir, posR[x]) - x);
  }
  printf("%I64d", ans);
}
