#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
long long tot, a[N], tr[N * 60][2], num[N * 60], pre[N], post[N], ans;
void insert(long long x) {
  long long u = 0;
  for (int i = 60; i >= 0; i--) {
    int t = ((1ll << i) & x) ? 1 : 0;
    if (!tr[u][t]) tr[u][t] = ++tot;
    u = tr[u][t];
  }
  num[u] = x;
}
long long query(long long x) {
  long long u = 0;
  for (int i = 60; i >= 0; i--) {
    int t = ((1ll << i) & x) ? 1 : 0;
    if (tr[u][t ^ 1])
      u = tr[u][t ^ 1];
    else
      u = tr[u][t];
  }
  return num[u];
}
int main() {
  int n;
  cin.sync_with_stdio(false);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    pre[i] = pre[i - 1] ^ a[i];
  }
  for (int i = n; i >= 1; i--) post[i] = post[i + 1] ^ a[i];
  for (int i = 0; i < n; i++) {
    insert(pre[i]);
    long long tmp = query(post[i + 1]);
    ans = max(ans, tmp ^ post[i + 1]);
  }
  cout << ans << endl;
  return 0;
}
