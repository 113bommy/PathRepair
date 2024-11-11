#include <bits/stdc++.h>
using namespace std;
int n, a[300005], b[300005], cnt[10000005], c[10000005][2], siz = 1;
void insert(int x) {
  int now = 1;
  for (int i = 30; ~i; i--) {
    int o = (x >> i) & 1;
    if (!c[now][o]) c[now][o] = ++siz;
    now = c[now][o];
    cnt[now]++;
  }
}
int query(int x) {
  int now = 1, ans = 0;
  for (int i = 30; ~i; i--) {
    int o = (x >> i) & 1;
    if (c[now][o] && cnt[c[now][o]])
      now = c[now][o], cnt[now]--;
    else
      now = c[now][!o], cnt[now]--;
    ans += (1 << i);
  }
  return ans;
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++) cin >> b[i], insert(b[i]);
  for (int i = 1; i <= n; i++) cout << query(a[i]) << ' ';
}
