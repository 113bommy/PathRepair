#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5, sq = 320;
int a[N], nxt[2 * N], st[2 * N], last[2 * N];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = n; i < 2 * N; i++) nxt[i] = N;
  for (int i = n - 1; i >= 0; i--) {
    nxt[i] = (i + a[i]) / sq == i / sq ? nxt[i + a[i]] : i + a[i];
    st[i] =
        ((i + a[i]) / sq == i / sq) || (i + a[i] >= n) ? st[i + a[i]] + 1 : 1;
    last[i] =
        ((i + a[i]) / sq != i / sq) || (i + a[i] >= n) ? i : last[i + a[i]];
  }
  while (m--) {
    int t;
    cin >> t;
    if (!t) {
      int x, b;
      cin >> x >> b;
      x--;
      a[x] = b;
      int l = x / sq * sq + sq - 1;
      int s = x / sq * sq;
      for (int i = min(n - 1, l); i >= s; i--) {
        nxt[i] = (i + a[i]) / sq == i / sq ? nxt[i + a[i]] : i + a[i];
        st[i] = ((i + a[i]) / sq == i / sq) || (i + a[i] >= n)
                    ? st[i + a[i]] + 1
                    : 1;
        last[i] =
            ((i + a[i]) / sq != i / sq) || (i + a[i] >= n) ? i : last[i + a[i]];
      }
    } else {
      int a, ans = 0, indx = 0;
      cin >> a;
      a--;
      for (int i = a; i < n; i = nxt[i]) {
        ans += st[i];
        indx = last[i];
      }
      cout << indx + 1 << " " << ans << '\n';
    }
  }
  return 0;
}
