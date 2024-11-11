#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
using namespace std;
long long int MOD = 998244353;
double eps = 1e-12;
void solve();
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
void solve() {
  long long int n;
  cin >> n;
  string s;
  cin >> s;
  long long int c = 0;
  for (long long int i = 1; i < n; i++) {
    if (s[i] == s[i - 1] && i < n - 1) {
      if (s[i] == 'B') {
        if (s[i + 1] == 'R') {
          s[i] = 'G';
          c++;
        } else if (s[i + 1] == 'G') {
          s[i] = 'R';
          c++;
        } else {
          s[i] = 'G';
          c++;
        }
      } else if (s[i] == 'R') {
        if (s[i + 1] == 'B') {
          s[i] = 'G';
          c++;
        } else if (s[i + 1] == 'G') {
          s[i] = 'B';
          c++;
        } else {
          s[i] = 'B';
          c++;
        }
      } else if (s[i] == 'G') {
        if (s[i + 1] == 'R') {
          s[i] = 'B';
          c++;
        } else if (s[i + 1] == 'B') {
          s[i] = 'R';
          c++;
        } else {
          s[i] = 'R';
          c++;
        }
      }
    } else if (s[i] == s[i - 1] && i == n - 1) {
      if (s[i] == 'R')
        s[i] = 'B';
      else if (s[i] == 'B')
        s[i] = 'R';
      else if (s[i] == 'G')
        s[i] = 'R';
      c++;
    }
  }
  cout << c << endl;
  cout << s << endl;
}
