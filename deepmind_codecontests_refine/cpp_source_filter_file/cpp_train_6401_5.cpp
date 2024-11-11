#include <bits/stdc++.h>
using namespace std;
vector<int> f[1000010];
int sum[300040], a[300040], c[300040];
int L[300040], R[300040], pre[300040], nxt[300040];
long long ans;
int n, k;
bool cmp(int x, int y) { return a[x] < a[y] || (a[x] == a[y] && x < y); }
void pre_() {
  for (int i = 1; i <= n; i++) {
    c[i] = i;
    pre[i] = i - 1;
    nxt[i] = i + 1;
  }
  sort(c + 1, c + n + 1, cmp);
  for (int i = 1; i <= n; i++) {
    int p = c[i];
    L[p] = pre[p];
    R[p] = nxt[p];
    pre[nxt[p]] = pre[p];
    nxt[pre[p]] = nxt[p];
  }
}
int ask(int l, int r, int k) {
  return upper_bound(f[k].begin(), f[k].end(), r) -
         lower_bound(f[k].begin(), f[k].end(), l);
}
int main() {
  scanf("%d%d", &n, &k);
  f[0].push_back(0);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    sum[i] = (sum[i - 1] + a[i]) % k;
    f[sum[i]].push_back(i);
  }
  pre_();
  for (int i = 1; i <= n; i++) {
    if (i - L[i] < R[i] - i) {
      for (int j = L[i]; j < i; j++)
        ans += ask(i, R[i] - 1, (sum[j] + a[i]) % k);
    } else {
      for (int j = i; j < R[i]; j++) {
        int x = ask(L[i], i - 1, (sum[j] - a[i] + k) % k);
        ans += x;
      }
    }
  }
  cout << ans - n;
  return 0;
}
