#include <bits/stdc++.h>
const int NUM = 2e5 + 5;
using namespace std;
int k;
string s, t, r;
int si[NUM], ti[NUM], sumi[NUM], ri[NUM];
int N(char a) { return a - 'a'; }
void input() {
  cin >> k;
  cin >> s >> t;
}
void prep() {
  int i;
  int rem = 0;
  for (i = k - 1; i >= 0; --i) {
    si[i + 1] = N(s[i]);
    ti[i + 1] = N(t[i]);
    sumi[i + 1] = (si[i + 1] + ti[i + 1] + rem) % 26;
    rem = (si[i + 1] + ti[i + 1] + rem) / 26;
  }
  sumi[0] = rem;
}
void solve() {
  int i;
  int rem = 0;
  if (sumi[0]) {
    rem = 26;
  }
  for (i = 1; i <= k; ++i) {
    ri[i] = (rem + sumi[i]) / 2;
    rem = 26 * ((rem + sumi[i]) % 2);
  }
  for (i = 1; i <= k; ++i) {
    cout << (char)(ri[i] + 'a');
  }
}
int main() {
  input();
  prep();
  solve();
  return 0;
}
