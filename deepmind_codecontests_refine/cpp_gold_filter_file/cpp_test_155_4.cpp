#include <bits/stdc++.h>
using namespace std;
int a[200002], b[200002], c[200002];
void solve() {
  int n, m;
  string s;
  m = 1;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  cin >> s;
  for (int i = 1; i <= n; i++) b[a[i]] = i;
  for (int i = 1; i <= n; i++) {
    if (s[b[i] - 1] == '0') {
      c[m] = b[i];
      m++;
    }
  }
  for (int i = 1; i <= n; i++) {
    if (s[b[i] - 1] == '1') {
      c[m] = b[i];
      m++;
    }
  }
  for (int i = 1; i <= n; i++) {
    a[c[i]] = i;
  }
  for (int i = 1; i <= n; i++) {
    printf("%d ", a[i]);
  }
  printf("\n");
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tc;
  cin >> tc;
  while (tc--) {
    solve();
  }
}
