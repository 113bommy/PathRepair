#include <bits/stdc++.h>
using namespace std;
const int N = 2000009;
string k, str, s;
vector<int> pi;
int z[N];
void go() {
  int L = 0, R = 0;
  for (int i = 1; i < s.size(); i++) {
    if (i > R) {
      L = R = i;
      while (R < s.size() && s[R - L] == s[R]) R++;
      z[i] = R - L;
      R--;
    } else {
      int k = i - L;
      if (z[k] < R - i + 1)
        z[i] = z[k];
      else {
        L = i;
        while (R < s.size() && s[R - L] == s[R]) R++;
        z[i] = R - L;
        R--;
      }
    }
  }
}
int ind = 0;
int main(void) {
  int n, m;
  cin >> n >> m;
  cin >> k;
  for (int i = 0; (i) < (int)(n); (i)++) str += "?";
  for (int i = 0; (i) < (int)(m); (i)++) {
    int j;
    cin >> j;
    j--;
    pi.push_back(j);
    for (int i = max(ind, j); i < j + k.size(); i++) {
      ind = i + 1;
      str[i] = k[i - j];
    }
    ind = j + k.size();
  }
  s += k;
  s += str;
  go();
  for (int i = 0; (i) < (int)(m); (i)++) {
    if (z[pi[i] + k.size()] < k.size()) {
      cout << "0\n";
      return 0;
    }
  }
  long long ans = 1, MOD = 1000000007;
  for (int i = 0; (i) < (int)(n); (i)++) {
    if (str[i] == '?') {
      ans *= 26;
      ans %= MOD;
    }
  }
  cout << ans << endl;
  return 0;
}
