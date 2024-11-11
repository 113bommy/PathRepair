#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1164777216")
using namespace std;
template <class T>
inline T sqr(T x) {
  return x * x;
}
const double pi = acos(-1.0), eps = 1e-15;
const int INF = 1000 * 1000 * 1000 + 5, MAXN = 100005, MOD = 1000007;
const long long INFL = 1000000000000000005;
void prepare(string s) {
  if ((int)s.size() != 0) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
  }
}
string s;
int vowel[5 * MAXN], cnta[5 * MAXN], cntb[5 * MAXN];
void solve() {
  cin >> s;
  for (int i = 0; i < (int)s.size(); ++i)
    if (s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' ||
        s[i] == 'U' || s[i] == 'Y')
      s[i] = 'A';
    else
      s[i] = 'B';
  if (s[0] == 'A') vowel[0] = 1;
  for (int i = 1; i < (int)s.size(); i++) {
    vowel[i] = vowel[i - 1];
    if (s[i] == 'A') vowel[i]++;
  }
  cnta[0] = vowel[(int)s.size() - 1];
  cntb[0] = (int)s.size();
  int border = (int)s.size() / 2 + (int)s.size() % 2;
  for (int i = 1; i < (int)s.size(); i++) {
    if (i <= border) {
      cnta[i] = cnta[i - 1];
      cntb[i] = cntb[i - 1];
      cnta[i] += vowel[(int)s.size() - i - 1] - vowel[i - 1];
      cntb[i] += ((int)s.size() - i - 1) - (i - 1);
    } else {
      cnta[i] = cnta[(int)s.size() - i - 1];
      cntb[i] = cntb[(int)s.size() - i - 1];
    }
  }
  double ans = 0;
  for (int i = 0; i < (int)s.size(); ++i) {
    ans += (double)cnta[i] / (double)cntb[i] * ((int)s.size() - i);
  }
  printf("%.8f", ans);
}
int main() {
  srand(time(NULL));
  prepare("");
  solve();
  return 0;
}
