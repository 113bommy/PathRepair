#include <bits/stdc++.h>
using namespace std;
inline void read(int &x) {
  char ch;
  bool flag = false;
  for (ch = getchar(); !isdigit(ch); ch = getchar())
    if (ch == '-') flag = true;
  for (x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar())
    ;
  x = flag ? -x : x;
}
const int INF = 0x3f3f3f3f;
const int N = 1e6 + 7;
int a[N], l[N], r[N];
int ll[N], rr[N];
int main() {
  int n, x;
  cin >> n >> x;
  memset(l, 0x3f3f3f, sizeof(l));
  memset(ll, 0x3f3f3f, sizeof(ll));
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    l[a[i]] = min(i, l[a[i]]);
    r[a[i]] = i;
  }
  long long ans = 0;
  for (int i = 1; i <= x; i++) rr[i] = max(r[i], rr[i - 1]);
  for (int i = x; i >= 1; i--) ll[i] = min(l[i], ll[i + 1]);
  int d = x;
  while (ll[d] >= r[d - 1] && d >= 1) d--;
  for (int i = 0; i < x; i++) {
    if (i != 0 && l[i] < r[i - 1]) break;
    while (d <= i + 1 || rr[i] > ll[d]) {
      d++;
    }
    ans += x - d + 2;
  }
  cout << ans << endl;
  return 0;
}
