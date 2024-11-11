#include <bits/stdc++.h>
#pragma GCC optimize("-Ofast")
using namespace std;
int32_t main() {
  long long t;
  cin >> t;
  while (t--) {
    vector<pair<long long, long long> > v;
    long long n, k;
    cin >> n >> k;
    string t = "";
    for (long long i = 0; i < k / 2; i++) {
      t += "()";
    }
    long long con = (n - t.size()) / 2;
    for (long long i = 0; i < con; i++) {
      t += "(";
    }
    for (long long i = 0; i < con; i++) {
      t += ")";
    }
    string s;
    cin >> s;
    for (long long i = 0; i < n; i++) {
      if (t[i] == s[i]) continue;
      for (long long j = i + 1; j < n; j++) {
        if (s[j] == t[i]) {
          v.push_back({i + 1, j + 1});
          reverse(s.begin() + i, s.begin() + j + 1);
          break;
        }
      }
    }
    cout << v.size() << '\n';
    for (long long i = 0; i < v.size(); i++) {
      cout << v[i].first << " " << v[i].second << '\n';
    }
  }
}
