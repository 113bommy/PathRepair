#include <bits/stdc++.h>
using namespace std;
const int N = 4e5 + 10;
int a[N];
vector<int> b;
int n, nn;
int dppre[N], dpsuf[N], sufmx[N];
int mx[N << 2];
void update(int pos, int val, int l, int r, int rt) {
  if (l == r) {
    mx[rt] = max(mx[rt], val);
    return;
  }
  int m = l + r >> 1;
  if (pos <= m)
    update(pos, val, l, m, rt << 1);
  else
    update(pos, val, m + 1, r, rt << 1 | 1);
  mx[rt] = max(mx[rt << 1], mx[rt << 1 | 1]);
}
int querymx(int L, int R, int l, int r, int rt) {
  if (L <= l && R >= r) return mx[rt];
  int ans = 0;
  int m = l + r >> 1;
  if (L <= m) ans = max(ans, querymx(L, R, l, m, rt << 1));
  if (R > m) ans = max(ans, querymx(L, R, m + 1, r, rt << 1 | 1));
  return ans;
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
    b.push_back(a[i] - i);
    b.push_back(a[i] - i + 1);
  }
  sort(b.begin(), b.end());
  b.erase(unique(b.begin(), b.end()), b.end());
  nn = b.size();
  for (int i = n; i >= 1; i--) {
    int pos = lower_bound(b.begin(), b.end(), a[i - 1] - i + 1) - b.begin() + 1;
    if (i == 1) pos = 1;
    sufmx[i - 1] = querymx(pos, nn, 1, nn, 1);
    pos = lower_bound(b.begin(), b.end(), a[i] - i + 1) - b.begin() + 1;
    int v = querymx(pos, nn, 1, nn, 1);
    dpsuf[i] = v + 1;
    update(pos, dpsuf[i], 1, nn, 1);
  }
  for (int i = 1; i <= (nn << 2); i++) {
    mx[i] = 0;
  }
  int ans = sufmx[0];
  for (int i = 1; i <= n; i++) {
    int pos = lower_bound(b.begin(), b.end(), a[i] - i) - b.begin() + 1;
    int v = querymx(1, pos, 1, nn, 1);
    dppre[i] = v + 1;
    ans = max(dppre[i] + sufmx[i], ans);
    update(pos, dppre[i], 1, nn, 1);
  }
  cout << n - 1 - ans << endl;
  return 0;
}
