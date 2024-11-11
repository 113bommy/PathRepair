#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6;
const long long z = 131, MOD = 1e9 + 21;
long long Z[MAXN + 1];
void fillZ() {
  Z[0] = 1;
  for (int n = 1; n <= MAXN; ++n) Z[n] = z * Z[n - 1] % MOD;
}
struct RollingHashing {
  vector<long long> H;
  RollingHashing(string &S) {
    int N = S.length();
    H.resize(N + 1);
    H[N] = 0;
    for (int i = N - 1; i >= 0; --i) H[i] = (S[i] + z * H[i + 1]) % MOD;
  }
  long long hash(int i, int k) {
    long long ans = (H[i] - Z[k] * H[i + k]) % MOD;
    return ans >= 0 ? ans : ans + MOD;
  }
};
int main() {
  fillZ();
  string s;
  cin >> s;
  int lens = s.length();
  int lent = lens - 2;
  RollingHashing rs(s);
  long long prefix, suffix, mid;
  int i;
  while (lent > 1) {
    prefix = rs.hash(0, lent);
    suffix = rs.hash(lens - lent, lent);
    if (prefix == suffix) {
      i = 1;
      while (i + lent < lens - 1) {
        mid = rs.hash(i, lent);
        if (mid == prefix) {
          for (int j = 0; j < lent; ++j) {
            cout << s[j];
          }
          cout << '\n';
          return 0;
        }
        ++i;
      }
    }
    --lent;
  }
  cout << "Just a legend\n";
  return 0;
}
