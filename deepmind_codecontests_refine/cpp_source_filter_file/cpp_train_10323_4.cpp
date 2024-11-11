#include <bits/stdc++.h>
using namespace std;
long long int mod = 1e9 + 7;
int main() {
  long long int n;
  cin >> n;
  map<long long int, long long int> cnt, freq;
  long long int i, mx = 0;
  long long int ans = 2;
  for (i = 1; i <= n; i++) {
    long long int x;
    cin >> x;
    cnt[freq[x]]--;
    freq[x]++;
    cnt[freq[x]]++;
    mx = max(mx, freq[x]);
    long long int ok = 0;
    if (cnt[1] == i)
      ok = 1;
    else if (cnt[1] == 1 && ((cnt[mx] * mx) == (i - 1)))
      ok = 1;
    else if (cnt[i] = 1)
      ok = 1;
    else if (cnt[mx - 1] * (mx - 1) == i - mx && cnt[mx] == 1)
      ok = 1;
    if (ok) ans = i;
  }
  cout << ans;
}
