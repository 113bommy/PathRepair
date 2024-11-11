#include <bits/stdc++.h>
using namespace std;
const int maxn = 3010;
int a[maxn];
struct node {
  int pos, val;
} num[maxn];
bool operator<(const node &x, const node &y) { return x.val > y.val; }
int nowi = 1, nowj = 2, nowk = 3;
int lg[maxn], st[maxn][maxn];
int n;
int ans[maxn];
void ST() {
  num[n + 1].val = 0;
  for (int i = 1; i <= n; i++) {
    st[i][i] = i;
    int mx = num[i].val - num[i + 1].val;
    for (int j = i + 1; j <= n; j++) {
      int v = num[j].val - num[j + 1].val;
      if (v > mx)
        mx = v, st[i][j] = j;
      else
        st[i][j] = st[i][j - 1];
    }
  }
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &num[i].val);
    num[i].pos = i;
  }
  sort(num + 1, num + 1 + n);
  ST();
  for (int i = 1; i <= n / 2; i++) {
    if (num[i].val - num[i + 1].val < num[nowi].val - num[nowi + 1].val)
      continue;
    int lj = i + (i + 1) / 2, rj = min(n - (i + 1) / 2, 3 * i);
    for (int j = lj; j <= rj; j++) {
      int lk = j + max((i + 1) / 2, (j - i + 1) / 2),
          rk = min(j + min(i * 2, (j - i) * 2), n);
      if (lk > rk) continue;
      int k = st[lk][rk];
      int a = num[i].val - num[i + 1].val;
      int b = num[j].val - num[j + 1].val;
      int c = num[k].val - num[k + 1].val;
      int ansa = num[nowi].val - num[nowi + 1].val;
      int ansb = num[nowj].val - num[nowj + 1].val;
      int ansc = num[nowk].val - num[nowk + 1].val;
      if (a > ansa || a == ansa && b > ansb ||
          a == ansa && b == ansb && c > ansc)
        nowi = i, nowj = j, nowk = k;
    }
  }
  for (int i = 1; i <= nowi; i++) ans[num[i].pos] = 1;
  for (int i = nowi + 1; i <= nowj; i++) ans[num[i].pos] = 2;
  for (int i = nowj + 1; i <= nowk; i++) ans[num[i].pos] = 3;
  for (int i = nowk + 1; i <= n; i++) ans[num[i].pos] = -1;
  for (int i = 1; i <= n; i++) {
    printf("%d ", ans[i]);
  }
  return 0;
}
