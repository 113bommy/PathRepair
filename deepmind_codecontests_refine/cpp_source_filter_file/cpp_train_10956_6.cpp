#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const long long mod2 = 998244353;
const long long INF = 3e18;
const long long N = 100001;
const long double PI = 3.141593;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long n, m;
    cin >> n >> m;
    string s[n];
    for (long long i = 0; i < n; i++) cin >> s[i];
    set<long long> sub;
    for (long long i = 0; i < n; i++) {
      long long a = 0;
      for (long long j = 0; j < m; j++) {
        if (s[i][j] == '1') {
          a += pow(2, m - j - 1);
        }
      }
      sub.insert(a);
    }
    long long v = (pow(2, m) - n - 1) / 2;
    long long med = max(0ll, (long long)(pow(2, m) - 1) / 2 - 101ll);
    bool f = 0;
    while (med < (long long)pow(2, m) - 1ll) {
      if (sub.find(med) == sub.end()) {
        long long small = med;
        for (auto i : sub) {
          if (i < m) small--;
        }
        if (small == v) {
          f = 1;
          break;
        }
      }
      med++;
    }
    string fa;
    for (long long i = 0; i < m; i++) {
      long long c = med % 2;
      med /= 2;
      if (c == 0)
        fa.push_back('0');
      else
        fa.push_back('1');
    }
    reverse(fa.begin(), fa.end());
    cout << fa << endl;
  }
}
