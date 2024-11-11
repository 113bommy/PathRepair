#include <bits/stdc++.h>
using namespace std;
const int N = 100;
const int Z = 26;
const int K = 100;
int c_[Z][Z];
inline int ch(char a) { return a - 'a'; }
inline int& c(char a, char b) { return c_[a - 'a'][b - 'a']; }
int a[N][K + 1][Z];
char s[N + 1];
int n, k;
int main() {
  cin >> s >> k;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    char a, b;
    cin >> a >> b;
    cin >> c(a, b);
  }
  const int l = strlen(s);
  const int INF = 1000000000;
  for (int i = 1; i < l; ++i) {
    for (int j = 0; j <= k; ++j) {
      for (char kk = 'a'; kk <= 'z'; ++kk) {
        a[i][j][ch(kk)] = -INF;
      }
    }
  }
  for (int j = 2; j <= k; ++j) {
    for (char kk = 'a'; kk <= 'z'; ++kk) {
      a[0][j][ch(kk)] = -INF;
    }
  }
  for (int i = 1; i < l; ++i) {
    a[i][0][ch(s[i])] = c(s[i - 1], s[i]) + a[i - 1][0][ch(s[i - 1])];
    for (int j = 1; j <= min(k, i + 1); ++j) {
      for (char kk = 'a'; kk <= 'z'; ++kk) {
        if (kk == s[i]) {
          for (char k2 = 'a'; k2 <= 'z'; ++k2) {
            a[i][j][ch(kk)] =
                max(a[i][j][ch(kk)], a[i - 1][j][ch(k2)] + c(k2, kk));
          }
        } else {
          if (j > 1) {
            for (char k2 = 'a'; k2 <= 'z'; ++k2) {
              a[i][j][ch(kk)] =
                  max(a[i][j][ch(kk)], a[i - 1][j - 1][ch(k2)] + c(k2, kk));
            }
          } else {
            a[i][j][ch(kk)] = max(a[i][j][ch(kk)],
                                  a[i - 1][0][ch(s[i - 1])] + c(s[i - 1], kk));
          }
        }
      }
    }
  }
  int max_good = a[l - 1][0][ch(s[l - 1])];
  for (int j = 1; j <= k; ++j) {
    for (char kk = 'a'; kk <= 'z'; ++kk) {
      max_good = max(max_good, a[l - 1][j][ch(kk)]);
    }
  }
  cout << max_good << endl;
}
