#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  int m[2002], s[2002];
  memset(m, 0, sizeof m);
  memset(s, 0, sizeof s);
  for (long long i = 0; i < n; i++) {
    long long x, y;
    cin >> x >> y;
    m[x - y + 1001]++;
    s[x + y]++;
  }
  long long a, ans = 0;
  for (int i = 0; i < 2002; i++) ans += (m[i]) * (m[i] - 1) / 2;
  for (int i = 0; i < 2002; i++) ans += (s[i]) * (s[i] - 1) / 2;
  cout << ans;
}
