#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
string s, w;
signed main() {
  int n;
  cin >> n >> s >> w;
  long long Ans = 1, Ans1 = 1, Ans2 = 1, Ans3 = 1;
  for (int i = 0; i < n; i++) {
    if (s[i] == '?') (Ans *= 10) %= mod;
    if (w[i] == '?') (Ans *= 10) %= mod;
  }
  for (int i = 0; i < n; i++) {
    if (s[i] != '?' && w[i] != '?')
      Ans1 *= (s[i] >= w[i]), Ans2 *= (w[i] >= s[i]), Ans3 *= (s[i] == w[i]);
    else if (s[i] == '?' && w[i] != '?')
      (Ans1 *= '9' - w[i] + 1) %= mod, (Ans2 *= w[i] - '0' + 1) %= mod;
    else if (s[i] != '?' && w[i] == '?')
      (Ans1 *= s[i] - '0' + 1) %= mod, (Ans2 *= '9' - s[i] + 1) %= mod;
    else
      (Ans1 *= 55) %= mod, (Ans2 *= 55) %= mod, (Ans3 *= 10) %= mod;
  }
  cout << ((Ans - Ans1 - Ans2 + Ans3) % mod + mod) % mod << endl;
  return 0;
}
