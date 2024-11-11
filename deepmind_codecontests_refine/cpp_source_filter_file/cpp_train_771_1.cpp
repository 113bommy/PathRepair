#include <bits/stdc++.h>
using namespace std;
const int maxn = 200005;
int n;
int a[maxn];
long long head, firnum, secnum;
int ans;
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (head = 1; head <= n; head++) {
    ans++;
    for (firnum = head; a[firnum] == -1; firnum++)
      ;
    for (secnum = firnum + 1; a[secnum] == -1; secnum++)
      ;
    if (secnum > n) break;
    if ((a[secnum] - a[firnum]) % (secnum - firnum)) {
      head = secnum;
      continue;
    }
    int inc = (a[secnum] - a[firnum]) / (secnum - firnum);
    if (a[secnum] - inc * (secnum - head) < 1) {
      head = secnum;
      continue;
    }
    for (head = secnum + 1;
         head <= n && a[secnum] + inc * (head - secnum) > 0 &&
         (a[head] != -1 || a[head] == a[secnum] + inc * (head - secnum));
         head++)
      ;
  }
  cout << ans << endl;
  return 0;
}
