#include <bits/stdc++.h>
using namespace std;
void pass() { return; }
const double EPS = 1e-6;
mt19937 rnd(rand() << 15 + rand());
const long long MOD = 1e9 + 7;
const long long BIG_MOD = 1e18 + 7;
const long long MAXN = 1e5 + 7;
bool bad(char c) {
  return (c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u');
}
signed main() {
  cout.tie(NULL);
  cout.precision(20);
  ios_base::sync_with_stdio(false);
  string s;
  cin >> s;
  long long n = s.size();
  long long i = 0;
  for (; i < n;) {
    if (!bad(s[i])) {
      cout << s[i];
      ++i;
      continue;
    }
    if (i == n - 1) {
      cout << s[i];
      ++i;
      continue;
    }
    if (!bad(s[i + 1]) || !bad(s[i + 2])) {
      cout << s[i];
      ++i;
      continue;
    }
    bool good = true;
    long long j = i + 1;
    for (; j < n && bad(s[j]); ++j) {
      good &= (s[j] == s[j - 1]);
    }
    if (good) {
      for (long long k = i + 1; k < j; ++k) {
        cout << s[k];
      }
      i = j;
      continue;
    }
    if (s[i] != s[i + 1]) {
      cout << s[i] << s[i + 1] << ' ';
      i = i + 2;
      continue;
    }
    cout << s[i];
    i = i + 1;
    for (; i < n && s[i] == s[i - 1]; ++i) {
      cout << s[i];
    }
    cout << ' ';
  }
  return 0;
}
