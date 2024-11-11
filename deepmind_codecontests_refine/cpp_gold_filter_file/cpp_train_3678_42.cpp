#include <bits/stdc++.h>
using namespace std;
const int maxn = (int)1e5 + 10;
;
const int MOD = (int)1e9 + 7;
;
long long pr[maxn], sz[maxn], n, m, k, mul[maxn];
long long find(long long a) { return (a == pr[a] ? a : pr[a] = find(pr[a])); }
void uni(long long a, long long b) {
  a = find(a);
  b = find(b);
  if (a == b) return;
  if (sz[a] < sz[b]) swap(a, b);
  pr[b] = a;
  sz[a] += sz[b];
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  for (int i = 0; i < maxn; i++) {
    pr[i] = i;
    sz[i] = 1;
  }
  cin >> n >> m >> k;
  for (int i = 0; i < m; i++) {
    long long a, b;
    cin >> a >> b;
    uni(a, b);
  }
  long long cnt = 0, ans = 1;
  for (int i = 1; i < n + 1; i++)
    if (pr[i] == i) {
      mul[cnt++] = sz[i];
      if (sz[i] == n) {
        cout << 1 % k;
        return 0;
      }
    }
  for (int i = 0; i < cnt; i++) ans = (ans * mul[i]) % k;
  for (int i = 0; i < cnt - 2; i++) ans = (ans * n) % k;
  cout << ans;
}
