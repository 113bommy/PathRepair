#include <bits/stdc++.h>
using namespace std;
string P, S;
int K;
const long long prime1 = 29, mod1 = 1000000007;
const long long prime2 = 5, mod2 = 1000000009;
struct hash_t {
  long long h1, h2;
  hash_t() : h1(0), h2(0) {}
  void add_char(char ch) {
    int value = (int)ch;
    h1 = ((h1 * prime1) + value) % mod1;
    h2 = ((h2 * prime2) + value) % mod2;
  }
  bool operator==(const hash_t& o) const {
    return ((h1 == o.h1) && (h2 == o.h2));
  }
};
hash_t column[2005];
int main() {
  getline(cin, P);
  getline(cin, S);
  cin >> K;
  for (unsigned int i = 0; i < P.length(); i++) {
    int col = i % K;
    column[col].add_char(P[i]);
  }
  int rows = P.length() / K;
  int rem = P.length() % K;
  bool found = false;
  string best("0");
  for (int x = 1; x <= (int)S.length(); x++) {
    if ((int)(S.length() - x * rows) <= rem) {
      vector<hash_t> sought(x);
      string ans(K, '0');
      for (unsigned int i = 0; i < S.length(); i++) {
        int col = i % x;
        sought[col].add_char(S[i]);
      }
      int j = K - 1;
      bool failed = false;
      for (int i = x - 1; i >= 0; --i) {
        for (; j >= 0; --j) {
          if (sought[i] == column[j]) {
            ans[j] = '1';
            break;
          }
        }
        if (j < 0) {
          failed = true;
          break;
        }
        --j;
      }
      if (!failed) {
        if (!found) {
          found = true;
          best = ans;
        } else {
          if (ans < best) best = ans;
        }
      }
    }
  }
  cout << best << endl;
  return 0;
}
