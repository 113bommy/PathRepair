#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;
const int MOD = 1e9 + 7;
const int N = 1e5 + 10;
int n, k, unk[N], a[N];
string s;
void prepare() {
  cin >> n >> k;
  for (auto i = (0); i <= (n); i++) {
    cin >> s;
    if (s[0] == '?')
      unk[i] = 1;
    else {
      int sign = 1;
      for (auto ch : s) {
        if (ch == '-') {
          sign = -1;
          continue;
        }
        a[i] = 10 * a[i] + ch - '0';
      }
      a[i] *= sign;
    }
  }
}
string solve() {
  if (k == 0) {
    if (unk[0]) {
      int cturn = count(unk, unk + n + 1, 0);
      return (cturn & 1) ? "Yes" : "No";
    }
    return (a[0] == 0) ? "Yes" : "No";
  }
  if (count(unk, unk + n + 1, 1)) return ((n & 1) ? "Yes" : "No");
  for (auto i = (0); i <= (n); i++) {
    int val = a[i] / k;
    a[i + 1] += val;
    a[i] -= val * k;
  }
  return (count(a, a + n + 2, 0) == n + 2) ? "Yes" : "No";
}
int main() {
  prepare();
  cout << solve();
}
