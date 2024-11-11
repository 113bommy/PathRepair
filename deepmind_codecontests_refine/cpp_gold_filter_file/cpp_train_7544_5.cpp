#include <bits/stdc++.h>
using namespace std;
const int N = 200100;
int w, h, n, x, n1, n2, maxH, maxV;
char ch;
int H[N], V[N], preH[N], nextH[N], preV[N], nextV[N];
long long ans[N];
pair<int, int> q[N];
void prepare() {
  H[0] = 0, H[n1 + 1] = h;
  sort(H + 1, H + n1 + 1);
  V[0] = 0, V[n2 + 1] = w;
  sort(V + 1, V + n2 + 1);
  maxH = maxV = 0;
  for (int i = 1; i <= n1 + 1; i++) {
    maxH = max(maxH, H[i] - H[i - 1]);
    preH[i] = i - 1;
    nextH[i] = i + 1;
  }
  for (int i = 1; i <= n2 + 1; i++) {
    maxV = max(maxV, V[i] - V[i - 1]);
    preV[i] = i - 1;
    nextV[i] = i + 1;
  }
  if (!maxH) maxH = h;
  if (!maxV) maxV = w;
  ans[n] = 1ll * maxH * maxV;
}
int main() {
  scanf("%d %d %d\n", &w, &h, &n);
  n1 = n2 = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%c %d\n", &ch, &x);
    q[i].second = x;
    if (ch == 'H') {
      H[++n1] = x;
      q[i].first = 0;
    } else {
      V[++n2] = x;
      q[i].first = 1;
    }
  }
  prepare();
  for (int i = n; i >= 2; i--) {
    int type = q[i].first;
    int val = q[i].second;
    if (!type) {
      int pos = lower_bound(H + 1, H + n1 + 1, val) - H;
      maxH = max(maxH, H[nextH[pos]] - H[preH[pos]]);
      preH[nextH[pos]] = preH[pos];
      nextH[preH[pos]] = nextH[pos];
    } else {
      int pos = lower_bound(V + 1, V + n2 + 1, val) - V;
      maxV = max(maxV, V[nextV[pos]] - V[preV[pos]]);
      preV[nextV[pos]] = preV[pos];
      nextV[preV[pos]] = nextV[pos];
    }
    ans[i - 1] = 1ll * maxH * maxV;
  }
  for (int i = 1; i <= n; i++) printf("%I64d\n", ans[i]);
  return 0;
}
