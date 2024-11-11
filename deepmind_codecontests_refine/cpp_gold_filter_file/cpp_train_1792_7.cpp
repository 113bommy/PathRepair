#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int n = s.size();
  struct sub {
    int l;
    char t;
  };
  vector<sub> v;
  char last = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == last) {
      v.back().l++;
    } else {
      v.push_back({1, s[i]});
      last = s[i];
    }
  }
  n = v.size();
  if (n % 2 == 0) {
    cout << 0;
    return 0;
  }
  int m = n / 2;
  for (int i = 0; i < m; i++) {
    sub& a = v[i];
    sub& b = v[n - i - 1];
    if (a.t != b.t || a.l + b.l < 3) {
      cout << 0;
      return 0;
    }
  }
  int ans = v[m].l + 1;
  if (ans < 3) ans = 0;
  cout << ans;
  return 0;
}
