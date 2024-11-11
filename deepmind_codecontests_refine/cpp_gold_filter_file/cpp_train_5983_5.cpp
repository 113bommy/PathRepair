#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long n, p, l = n, r = -1, count = 0;
  string s;
  cin >> n >> p >> s;
  p--;
  if (p >= n / 2) p = n - p - 1;
  for (long long i = 0; i < n / 2; i++) {
    if (s[i] != s[n - 1 - i]) {
      count += min(abs(s[i] - s[n - 1 - i]), 26 - abs(s[i] - s[n - 1 - i]));
      l = min(l, i);
      r = max(r, i);
    }
  }
  if (r >= 0) count += abs(r - l) + min(abs(p - l), abs(r - p));
  cout << count;
}
