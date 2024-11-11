#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
long long n, ans, now;
long long num[1010000];
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> num[i];
  for (int i = 1; i <= n; i++)
    if (num[i] != -1)
      num[i] = 0;
    else
      break;
  ans += num[n];
  num[n] = 0x3f3f3f3f;
  now = n / 2;
  while (now) {
    long long bufid, bufmin = 0x3f3f3f3f;
    for (int i = now; i <= n; i++)
      if (num[i] < bufmin) bufmin = num[i], bufid = i;
    ans += bufmin;
    num[bufid] = 0x3f3f3f3f;
    now /= 2;
  }
  cout << ans + 1;
  return 0;
}
