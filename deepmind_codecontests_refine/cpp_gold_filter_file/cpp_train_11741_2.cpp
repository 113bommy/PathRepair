#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[1<<17], suf[1<<17];

int main() {
  int n;
  cin >> n;
  for(int i = 0; i <= n; i++) cin >> a[i];
  for(int i = n; ~i; i--) suf[i] = suf[i+1] + a[i];
  
  ll now = 1, ans = 0;
  for(int i = 0; i <= n; i++) {
    if(now < a[i]) puts("-1"), exit(0);
    ans += now;
    now -= a[i];
    now = min(now * 2, suf[i+1]);
  }
  cout << ans << endl;
  return 0;
}