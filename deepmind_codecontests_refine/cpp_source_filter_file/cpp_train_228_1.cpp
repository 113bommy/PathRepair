#include <bits/stdc++.h>
#pragma warning(disable : 4996)
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n, m;
    cin >> n >> m;
    vector<char> s(n);
    vector<long long> a(26);
    vector<long long> p(m);
    for (long long i = 0; i < n; i++) cin >> s[i];
    for (long long i = 0; i < m; i++) cin >> p[i];
    p.push_back(n);
    sort(p.begin(), p.end());
    long long j = 0;
    for (long long i = 0; i < n; i++) {
      a[s[i] - 'a'] += m + 1 - j;
      if (i + 1 == p[j]) {
        if (j < m && p[j] == p[j + 1]) j++;
        j++;
      }
    }
    for (long long i = 0; i < 26; i++) {
      cout << a[i] << ' ';
    }
    cout << endl;
  }
  return 0;
}
