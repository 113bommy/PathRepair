#include <bits/stdc++.h>
using namespace std;
const int INF = (int)1e9;
void solve() {
  int alph[26], alph1[26];
  for (int i = 0; i < 26; i++) alph[i] = alph1[i] = 0;
  int a, b, l, r, dif, ans1 = INF;
  string s, s1;
  cin >> a >> b >> l >> r;
  --l;
  --r;
  char d;
  for (char c = 'a'; c - 'a' < a; c++) {
    if (a > b && c - 'a' == b) d = c;
    s += c;
    if (a > b) s1 += c;
    if (c - 'a' == a - 1) {
      for (int i = 0; i < b; i++) {
        s += c;
        if (a > b) s1 += d;
      }
    }
  }
  int sz = s.length(), times = 0, times1 = 0;
  for (int i = sz - 1; times < a; i--) {
    alph[s[i] - 'a']++;
    if (a > b) alph1[s1[i] - 'a']++;
    times++;
  }
  times = 0;
  if (!(a > b)) times1 = INF;
  char c = 'a';
  for (int i = 0; times < a || times1 < a; i++) {
    if (times1 == b) d = c;
    if (alph[i] == 0) {
      s += c;
      times++;
      if (times == a) {
        for (int j = 0; j < b; j++) {
          s += c;
        }
      }
    }
    if (alph1[i] == 0) {
      if (a > b) s1 += c;
      times1++;
      if (times1 == a) {
        for (int j = 0; j < b; j++) {
          s1 += d;
        }
      }
    }
    c++;
  }
  for (int i = 0; i < 26; i++) alph[i] = alph1[i] = 0;
  dif = l;
  l = l % (2 * (a + b));
  dif -= l;
  r -= dif;
  int idx = l;
  for (int i = 0; i < min(2 * (a + b), r - l + 1); i++) {
    alph[s[idx % (2 * (a + b))] - 'a']++;
    if (a > b) alph1[s1[idx % (2 * (a + b))] - 'a']++;
    idx++;
  }
  int answer = 0;
  if (a > b) ans1 = 0;
  for (int i = 0; i < 26; i++) {
    if (alph[i]) answer++;
    if (alph1[i]) ans1++;
  }
  cout << min(answer, ans1);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
