#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
const long long MAX = 1e3 + 5;
const long long MAX2 = 11;
const int MOD = 1000000000 + 7;
const long long INF = 20000;
const int nr[] = {1, 0, -1, 0, 1, 1, -1, -1};
const int nc[] = {0, 1, 0, -1, 1, -1, 1, -1};
int sz, ans, id[65], tmp, pos, rel[128], dg;
string s, a, b;
char c;
bool st;
int main() {
  cout << fixed << setprecision(10);
  for (int i = 0; i <= 9; i++) {
    c = '0' + i;
    rel[c] = i;
  }
  for (int i = 0; i <= 25; i++) {
    c = 'A' + i;
    rel[c] = i + 10;
  }
  cin >> s;
  sz = s.size() - 1;
  for (int i = 0; i <= sz; i++) {
    if (s[i] == ':') {
      pos = i + 1;
      break;
    }
    a += s[i];
  }
  for (int i = pos; i <= sz; i++) b += s[i];
  reverse(a.begin(), a.end());
  reverse(b.begin(), b.end());
  for (int i = 2; i <= 60; i++) {
    st = 1;
    tmp = 0;
    dg = 1;
    for (auto j : a) {
      if (rel[j] >= i) {
        st = 0;
        break;
      }
      dg *= i;
      tmp += rel[j] * dg;
    }
    tmp /= i;
    if (tmp > 23) st = 0;
    tmp = 0;
    dg = 1;
    for (auto j : b) {
      if (rel[j] >= i) {
        st = 0;
        break;
      }
      dg *= i;
      tmp += rel[j] * dg;
    }
    tmp /= i;
    if (tmp > 59) st = 0;
    id[i] = st;
  }
  if (id[60]) return cout << -1, 0;
  for (int i = 2; i <= 60; i++) ans += id[i];
  if (!ans)
    cout << 0;
  else {
    for (int i = 2; i <= 60; i++)
      if (id[i]) cout << i << " ";
  }
  return 0;
}
