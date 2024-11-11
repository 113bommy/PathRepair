#include <bits/stdc++.h>
const long long N = 2e5 + 5;
using namespace std;
long long l;
long long a[N];
long long n;
long long s[N];
void read(void) {
  long long ans = 1e15;
  cin >> n >> l;
  n--;
  for (long long i = 1; i <= (long long)(n); ++i)
    cin >> a[i], s[i] = s[i - 1] + a[i];
  for (long long i = (long long)(l); i <= (long long)(n - 1); ++i)
    ans = min(ans, s[i] - s[i - l]);
  if (ans == 1e15) ans = 0;
  cout << ans;
}
signed main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  read();
}
