#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t, i, j, a, b;
  cin >> t;
  while (t--) {
    cin >> a >> b;
    string s;
    cin >> s;
    vector<long long int> v;
    long long int j;
    long long int p;
    long long int q, r;
    long long int count = 0;
    long long int ans = 0;
    long long int c = 0;
    for (i = 0; i < s.size(); i++) {
      if (s[i] == '1') {
        c++;
      }
    }
    if (c == 0) {
      cout << "0" << endl;
    } else {
      for (i = 0; i < s.size(); i++) {
        if (s[i] == '1') {
          j = i;
          break;
        }
      }
      for (i = s.size() - 1; i >= 0; i--) {
        if (s[i] == '1') {
          q = i;
          break;
        }
      }
      for (p = j; p < q; p++) {
        if (s[p] == '0') {
          while (s[p] == '0' && p < q) {
            count++;
            p++;
          }
          v.push_back(count);
          count = 0;
        }
      }
      ans = ans + a;
      for (i = 0; i < v.size(); i++) {
        ans = ans + min(v[i] * b, a);
      }
      cout << ans << endl;
    }
  }
}
