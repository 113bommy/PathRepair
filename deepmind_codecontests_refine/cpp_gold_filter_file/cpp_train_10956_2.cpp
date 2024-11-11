#include <bits/stdc++.h>
using namespace std;
unsigned long long cvt(string s) {
  reverse(s.begin(), s.end());
  unsigned long long res = 0;
  for (int i = 0; i < s.length(); i++) {
    if (s[i] != '0') {
      res += pow(2, i);
    }
  }
  return res;
}
void solve() {
  unsigned long long n, m;
  cin >> n >> m;
  vector<string> s(n);
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }
  unsigned long long t = (pow(2, m) - 1) / 2;
  unsigned long long p = (pow(2, m) - 1) / 2;
  unsigned long long q = p;
  set<unsigned long long> se;
  for (int i = 0; i < n; i++) {
    unsigned long long k = cvt(s[i]);
    se.insert(k);
    if (p == q) {
      if (k <= t) {
        q--;
        t++;
        while (se.count(t)) {
          t++;
        }
      } else {
        q--;
      }
    } else {
      if (k < t) {
        p--;
      } else {
        p--;
        t--;
        while (se.count(t)) {
          t--;
        }
      }
    }
  }
  string res(m, '0');
  for (int i = 0; i < m; i++) {
    if ((t >> i) & 1 == 1) {
      res[m - i - 1] = '1';
    }
  }
  cout << res << '\n';
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
