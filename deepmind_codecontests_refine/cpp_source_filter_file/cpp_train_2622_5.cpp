#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    vector<char> v;
    v.push_back('0');
    long long co = 0, n = 1ll * s.size();
    for (int i = 0; i < n; i++) {
      v.push_back(s[i]);
    }
    vector<int> next(n + 1);
    int bc = -1;
    for (int i = 1; i <= n; i++) {
      next[i] = bc;
      if (v[i] == '1') bc = i;
    }
    for (int i = n; i >= 1; i--) {
      long long start = 0, in = next[i], ct = 1;
      if (v[i] == '1') {
        co++;
        start = 1;
      }
      for (int j = i - 1; j >= max(1, i - 20); j--) {
        ct *= 2;
        if (v[j] == '1') {
          start += ct;
          if (i - start + 1 == j) {
            co++;
            continue;
          }
          if (i - start + 1 <= 0) continue;
          if (next[j] >= i - start + 1) break;
          co++;
        }
      }
    }
    cout << co << endl;
  }
  return 0;
}
