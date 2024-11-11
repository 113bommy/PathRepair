#include <bits/stdc++.h>
using namespace std;
const int maxn = 207;
int sInTrpos[maxn];
int main() {
  string s, t;
  cin >> s >> t;
  int pos = s.length();
  sInTrpos[t.length()] = s.length();
  for (int i = t.length() - 1; i >= 0; i--) {
    pos = sInTrpos[i + 1] - 1;
    while (s[pos] != t[i]) pos--;
    sInTrpos[i] = pos;
  }
  pos = 0;
  int ans = 0;
  int rPos = 0;
  for (int i = 0; i < s.length() - 1; i++) {
    if (pos < t.length())
      rPos = sInTrpos[pos] - 1;
    else
      rPos = s.length() - 1;
    ans = max(ans, rPos - i + 1);
    if (pos < t.length() && s[i] == t[pos]) pos++;
  }
  cout << ans << endl;
}
