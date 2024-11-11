#include <bits/stdc++.h>
using namespace std;
char s[1000005];
long long pre1[1000005];
long long suf1[1000005];
long long pre2[1000005];
long long suf2[1000005];
long long p = 26, mod1 = 19260817, mod2 = 1e9 + 21;
string hashh(string s) {
  int n = s.length();
  if (n == 0) return "";
  string ans = "";
  int pos = 1;
  pre1[0] = s[0] - 'a' + 1;
  suf1[0] = s[0] - 'a' + 1;
  pre2[0] = s[0] - 'a' + 1;
  suf2[0] = s[0] - 'a' + 1;
  long long now1 = p, now2 = p;
  for (int i = 1; i < n; i++) {
    pre1[i] = (((pre1[i - 1]) * p) % mod1 + s[i] - 'a' + 1) % mod1;
    suf1[i] = (suf1[i - 1] + (now1 * (s[i] - 'a' + 1)) % mod1) % mod1;
    pre2[i] = (((pre2[i - 1]) * p) % mod2 + s[i] - 'a' + 1) % mod2;
    suf2[i] = (suf2[i - 1] + (now2 * (s[i] - 'a' + 1)) % mod2) % mod2;
    if (pre1[i] == suf1[i] && pre2[i] == suf2[i]) pos = i + 1;
    now1 *= p;
    now1 %= mod1;
    now2 *= p;
    now2 %= mod2;
  }
  for (int i = 0; i < pos; i++) ans += s[i];
  return ans;
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%s", s);
    int n = strlen(s);
    string anss = "";
    string s1 = "", s2 = "", ss = "";
    int fro = 0, bac = n - 1;
    while (fro < bac && s[fro] == s[bac]) {
      fro++;
      bac--;
    }
    for (int i = 0; i < fro; i++) {
      s1 += s[i];
      s2 += s[i];
    }
    for (int i = fro; i <= bac; i++) {
      ss += s[i];
    }
    reverse(s2.begin(), s2.end());
    string ss1 = hashh(ss);
    reverse(ss.begin(), ss.end());
    string ss2 = hashh(ss);
    if (ss1.length() >= ss2.length()) {
      cout << s1 << ss1 << s2 << endl;
    } else {
      cout << s1 << ss2 << s2 << endl;
    }
  }
  return 0;
}
