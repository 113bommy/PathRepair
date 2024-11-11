#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
const double E = exp(1.0);
const long long INF = 0x3f3f3f3f3f3f3f3f;
const long long MOD = 1e9 + 7;
const int MAXN = 1e6 + 10;
int fst[MAXN] = {0};
int lst[MAXN] = {0};
string s, t;
int main() {
  cin >> s >> t;
  int slen = s.length();
  int tlen = t.length();
  if (s[0] == t[0]) fst[0] = 1;
  bool flag = false;
  for (int i = 1; i < slen; ++i) {
    fst[i] = fst[i - 1];
    if (!flag) {
      if (s[i] == t[fst[i - 1]]) fst[i] = fst[i - 1] + 1;
      if (fst[i] == tlen) flag = true;
    }
  }
  flag = false;
  if (*--s.end() == *--t.end()) {
    lst[slen - 1] = 1;
  }
  for (int i = slen - 2; i >= 0; --i) {
    lst[i] = lst[i + 1];
    if (!flag) {
      if (s[i] == t[tlen - lst[i + 1] - 1]) lst[i] = lst[i + 1] + 1;
      if (lst[i] == tlen) {
        flag = true;
      }
    }
  }
  map<int, int> aft;
  for (int i = slen - 1; i >= 0; --i) {
    if (lst[i] != lst[i + 1]) {
      aft[lst[i]] = i;
    }
  }
  int ans = 0;
  for (int i = 0; i < slen; ++i) {
    if (fst[i] == tlen) ans = max(ans, slen - 1 - i);
    ans = max(ans, aft[tlen - fst[i]] - i - 1);
    if (lst[i] == tlen) ans = max(ans, i);
  }
  cout << ans << '\n';
  return 0;
}
