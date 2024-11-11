#include <bits/stdc++.h>
using namespace std;
long long t;
long long n, m;
string s;
long long p[200005];
long long x[200005];
long long res[26];
int main() {
  cin >> t;
  while (t--) {
    cin >> n >> m >> s;
    for (int i = 0; i < m; i++) cin >> p[i];
    for (int i = 0; i < n; i++) x[p[i] - 1]++;
    x[n - 1] = 1;
    long long br = 0;
    for (int i = n - 1; i >= 0; i--) {
      br += x[i];
      res[s[i] - 'a'] += br;
    }
    for (int i = 0; i < 26; i++) cout << res[i] << " ";
    cout << "\n";
    for (int i = 0; i < 200005; i++) x[i] = 0;
    for (int i = 0; i < 26; i++) res[i] = 0;
  }
  return 0;
}
