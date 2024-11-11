#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 1;
int n, m, s, cnt;
int q[N], a[N];
int main() {
  ios_base ::sync_with_stdio(0);
  cin >> m;
  for (int i = 1; i <= m; i++) cin >> q[i];
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  sort(q + 1, q + m + 1);
  sort(a + 1, a + n + 1);
  for (int i = n; i >= 1;) {
    if (cnt == q[1]) {
      i -= 2;
      cnt = 0;
    } else {
      cnt++;
      s += a[i--];
    }
  }
  cout << s;
  return 0;
}
