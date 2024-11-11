#include <bits/stdc++.h>
using namespace std;
long long sqr(long long x) { return x * x; }
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    string s;
    cin >> s;
    long long i = 1, start = 0, ans = 0;
    while (i < n && s[i] == s[0]) {
      i++;
    }
    long long k = n - 1;
    while (k > i && s[k] == s[0]) {
      k--;
    }
    long long add = 0;
    if (i + (n - 1 - k) == n) {
      ans = (n % 2 != 2 ? 1 + n / 2 : n / 2);
      cout << ans << endl;
      continue;
    }
    ans += (i + (n - 1 - k)) / 3;
    start = i;
    while (i < k + 1) {
      if (s[i] == s[start])
        i++;
      else {
        ans += (i - start) / 3;
        start = i;
      }
    }
    ans += (i - start) / 3;
    cout << ans << endl;
  }
}
