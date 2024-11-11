#include <bits/stdc++.h>
using namespace std;
int read() {
  int ans = 0, sign = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') sign = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    ans = (ans << 1) + (ans << 3) + (ch ^ 48);
    ch = getchar();
  }
  return ans * sign;
}
long long gcd(long long x, long long y) { return y == 0 ? x : (gcd(y, x % y)); }
int main() {
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    int num[1005];
    memset(num, 0, sizeof(num));
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      if (!num[x]) num[x]++;
    }
    for (int i = 0; i < m; i++) {
      int x;
      cin >> x;
      if (num[x]) num[x]++;
    }
    bool flag = 1;
    for (int i = 0; i < 1005; i++) {
      if (num[i] == 2) {
        cout << "YES" << '\n' << 1 << " " << i << '\n';
        flag = 0;
        break;
      }
    }
    if (flag) cout << "NO" << '\n';
  }
  return 0;
}
