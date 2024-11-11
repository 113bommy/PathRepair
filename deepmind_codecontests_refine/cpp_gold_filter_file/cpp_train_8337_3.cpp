#include <bits/stdc++.h>
using namespace std;
int nn;
string grb(int kam, string s, int ba2e) {
  int cnt = kam;
  for (int j = 0; j < ba2e; ++j) {
    cnt = kam;
    for (int i = nn - kam; cnt; ++i, --cnt) s += s[i];
  }
  int tmp = 0;
  for (int i = 0; i < s.size(); ++i) {
    cnt = 0;
    for (int j = 0; j < nn && i + j < s.size(); ++j) {
      if (s[j + i] == s[j])
        ++cnt;
      else
        break;
    }
    if (cnt == nn) ++tmp;
  }
  if (ba2e + 1 == tmp) return s;
  return "#";
}
int main() {
  int n, k;
  cin >> n >> k;
  string s;
  nn = n;
  cin >> s;
  --k;
  for (int i = 1; i <= n; ++i) {
    string tmp = grb(i, s, k);
    if (tmp != "#") return cout << tmp, 0;
  }
}
