#include <bits/stdc++.h>
using namespace std;
const int N = 70005, mod = 1e9 + 7;
char s[10];
map<string, int> S;
map<string, int>::iterator it;
string ans[N];
string Min(string a, string b) {
  if (((int)(a).size()) <= ((int)(b).size())) return a;
  return b;
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = (0); i < (n); ++i) {
    scanf("%s", s);
    for (int l = (0); l < (9); ++l) {
      string a = "";
      for (int r = (l); r < (9); ++r) {
        a += s[r];
        if (S[a] == 0 || S[a] == i + 1)
          S[a] = i + 1;
        else
          S[a] = -1;
      }
    }
  }
  for (int i = (1); i < (n + 1); ++i) ans[i] = "99999999999999999999";
  for (it = S.begin(); it != S.end(); it++) {
    if (it->second >= 1) ans[it->second] = Min(it->first, ans[it->second]);
  }
  for (int i = (1); i < (n + 1); ++i) {
    assert(ans[i] != "99999999999999999999");
    cout << ans[i] << endl;
  }
  return 0;
}
