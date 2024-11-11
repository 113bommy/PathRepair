#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const long long LL_INF = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1);
const double EPS = 1e-10;
inline bool isVowel(char c) {
  return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  string s;
  cin >> s;
  string res = "";
  for (int i = 0; i < (int)s.size();) {
    if (isVowel(s[i])) {
      res += s[i++];
      continue;
    }
    int j = i, numCons = 0, dup = 0;
    while (j < (int)s.size()) {
      if (isVowel(s[j])) {
        break;
      }
      ++numCons;
      if (numCons == 1) {
        dup = 1;
      }
      if (numCons > 1) {
        if (s[j] == s[j - 1]) {
          ++dup;
        } else {
          dup = 1;
        }
      }
      if (numCons == 3 && dup != 3) {
        res += ' ';
        break;
      }
      res += s[j++];
    }
    i = j;
  }
  cout << res;
}
