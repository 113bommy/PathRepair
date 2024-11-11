#include <bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;
char s[1111];
int main() {
  int t;
  cin >> t;
  while (t--) {
    unsigned long long x;
    cin >> x;
    cin >> s;
    int m = strlen(s);
    vector<char> s1(s, s + m);
    long long res = m;
    for (int i = 1; i <= x; ++i) {
      int mul = s1[i - 1] - '1';
      if (s1.size() < x) {
        vector<char> a(s1.begin() + i, s1.end());
        for (int j = 0; j < mul; ++j) {
          s1.insert(s1.end(), a.begin(), a.end());
        }
      }
      res = (res + (res - i) * mul) % mod;
    }
    res = (res + mod) % mod;
    cout << res << endl;
  }
}
