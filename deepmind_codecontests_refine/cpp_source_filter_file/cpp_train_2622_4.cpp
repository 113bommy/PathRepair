#include <bits/stdc++.h>
using namespace std;
long long min(long long a, long long b) { return (a < b) ? a : b; }
long long max(long long a, long long b) { return (a > b) ? a : b; }
int main() {
  long long t, n, m, i, j, k = 0, p;
  cin >> t;
  string s;
  for (long long ii = 0; ii < t; ii++) {
    cin >> s;
    k = 0;
    vector<long long> a(s.size());
    if (s[0] == '0')
      a[0] = -1;
    else
      a[0] = 1;
    for (i = 1; i < s.size(); i++) {
      if (s[i] == '1')
        a[i] = i;
      else
        a[i] = a[i - 1];
    }
    for (i = 0; i < s.size(); i++) {
      p = 0;
      for (j = i; j >= 0; j--) {
        if (i - j > 19) break;
        if (s[j] == '0') continue;
        p += 1 << (i - j);
        if (p <= i - ((j == 0) ? -1 : a[j - 1])) {
          k++;
        }
      }
    }
    cout << k << endl;
  }
}
