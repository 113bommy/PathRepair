#include <bits/stdc++.h>
using namespace std;
int a[26];
string s;
int main() {
  for (int i = 0; i < 26; i++) cin >> a[i];
  cin >> s;
  int n = (int)s.length();
  long long ans = 0;
  map<long long, long long> m;
  for (int i = 0; i < 26; i++) {
    m.clear();
    long long sum = 0;
    for (int j = 0; j < n; j++) {
      if (s[j] - 'a' == i) {
        if (((m.find(sum - a[i])) != (m.end()))) ans += m[sum - a[i]];
        if (((m.find(sum)) != (m.end())))
          m[sum] = m[sum] + 1;
        else
          m[sum] = 1;
      }
      sum += a[j];
    }
  }
  cout << ans;
}
