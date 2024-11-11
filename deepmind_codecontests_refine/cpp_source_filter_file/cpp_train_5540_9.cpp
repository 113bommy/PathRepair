#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> s;
  int n = s.length();
  const long long p = 31LL;
  long long p_pow[n];
  p_pow[0] = 1;
  for (int i = 1; i < n; ++i) p_pow[i] = p_pow[i - 1] * p;
  long long h[n];
  h[0] = (s[0] - 'a' + 1LL) * p_pow[0];
  for (int i = 1; i < n; ++i) h[i] = h[i - 1] + (s[i] - 'a' + 1LL) * p_pow[i];
  for (int i = n - 1; i > 0; --i) {
    long long h1 = h[i - 1] * p_pow[n - 1];
    long long h2 = (h[n - 1] - h[n - 1 - i]) * p_pow[i - 1];
    if (h1 != h2) continue;
    for (int j = 1; j < n - 1 - i; ++j) {
      long long h3 = (h[j + i - 1] - h[j - 1]) * p_pow[n - j - 1];
      if (h1 == h3) {
        string s1 = s.substr(0, i), s2 = s.substr(n - i), s3 = s.substr(j, i);
        if (s1 == s2 && s2 == s3) {
          cout << s1 << '\n';
          return 0;
        }
      }
    }
  }
  cout << "Just a legend\n";
}
