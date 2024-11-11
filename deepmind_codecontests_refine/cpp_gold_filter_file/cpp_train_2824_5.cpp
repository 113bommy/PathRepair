#include <bits/stdc++.h>
using namespace std;
void getint(int &v) {
  char ch, fu = 0;
  for (ch = '*'; (ch < '0' || ch > '9') && ch != '-'; ch = getchar())
    ;
  if (ch == '-') fu = 1, ch = getchar();
  for (v = 0; ch >= '0' && ch <= '9'; ch = getchar()) v = v * 10 + ch - '0';
  if (fu) v = -v;
}
int n, t, mx, x, k, a[500010], ans;
int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) getint(a[i]);
  t = 1;
  for (int i = 2; i <= n; ++i)
    if (a[i] == a[i - 1])
      ans = max(ans, t), t = 1;
    else
      ++t;
  ans = max(ans, t);
  cout << ans << endl;
  return 0;
}
