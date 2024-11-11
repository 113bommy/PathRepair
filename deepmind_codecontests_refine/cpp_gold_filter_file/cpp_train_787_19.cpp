#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string s, t;
  cin >> s >> t;
  long long n = s.size();
  sort(s.begin(), s.end());
  sort(t.begin(), t.end());
  reverse(t.begin(), t.end());
  deque<char> a, b;
  for (long long i = 0; i < (n + 1) / 2; i++) {
    a.push_back(s[i]);
  }
  for (long long i = 0; i < n / 2; i++) {
    b.push_back(t[i]);
  }
  string ansl = "";
  string ansr = "";
  for (long long i = 0; i < n; i++) {
    if (i % 2 == 0) {
      if (!b.empty() && a[0] >= b[0]) {
        ansr.push_back(a.back());
        a.pop_back();
      } else {
        ansl.push_back(a[0]);
        a.pop_front();
      }
    } else {
      if (a[0] >= b[0]) {
        ansr.push_back(b.back());
        b.pop_back();
      } else {
        ansl.push_back(b[0]);
        b.pop_front();
      }
    }
  }
  reverse(ansr.begin(), ansr.end());
  ansl += ansr;
  cout << ansl << "\n";
}
