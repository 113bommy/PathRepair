#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, k;
  cin >> n >> k;
  long long a[26];
  for (long long i = 0; i < 26; i++) a[i] = 0LL;
  string s;
  cin >> s;
  long long slen = s.length();
  for (long long i = 0; i < slen; i++) a[s[i] - 'A']++;
  sort(a, a + 26);
  long long ans = 0;
  for (long long i = 0; i < 26; i++) {
    if (a[i] <= k) {
      ans += (a[i] * a[i]);
      k -= a[i];
    } else if (a[i] > k) {
      ans += (k * k);
      break;
    }
  }
  cout << ans << '\n';
  return 0;
}
