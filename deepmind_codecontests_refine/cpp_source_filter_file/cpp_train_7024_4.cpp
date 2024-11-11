#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1.0);
const double eps = 1e-11;
map<char, int> cnt;
int main() {
  std::ios_base::sync_with_stdio(0);
  int n;
  string s;
  cin >> n;
  cin >> s;
  int mx = 0;
  int nm = 0;
  for (int i = 0; i < n; i++) {
    cnt[s[i]]++;
    if (cnt[s[i]] > mx) {
      mx = cnt[s[i]];
      nm = 1;
    } else if (cnt[s[i]] == mx)
      nm++;
  }
  long long rs = nm;
  for (int i = 1; i <= n; i++) {
    rs *= nm;
    rs %= 1000000000 + 7;
  }
  cout << rs << endl;
  return 0;
}
