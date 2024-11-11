#include <bits/stdc++.h>
using namespace std;
const int p = 998244353;
const int maxn = 3e5 + 5;
int a[maxn];
int n, q;
int st[maxn], top;
map<unsigned long long, int> mp;
unsigned long long Hash[maxn];
long long ans;
void solve(int l, int r) {
  if (l >= r) return;
  mp.clear();
  int mid = l + r >> 1;
  Hash[top = 0] = 0;
  for (int i = mid + 1; i <= r; i++) {
    if (top > 0 && st[top] == a[i])
      top--;
    else {
      st[++top] = a[i];
      Hash[top] = Hash[top - 1] * p + a[i];
    }
    mp[Hash[top]]++;
  }
  Hash[top = 0] = 0;
  for (int i = mid; i >= l; i--) {
    if (top > 0 && st[top] == a[i])
      top--;
    else {
      st[++top] = a[i];
      Hash[top] = Hash[top - 1] * p + a[i];
    }
    if (mp.count(Hash[top])) ans += mp[Hash[top]];
  }
  solve(l, mid);
  solve(mid + 1, r);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  cin >> q;
  while (q--) {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    ans = 0;
    solve(1, n);
    cout << ans << '\n';
  }
}
