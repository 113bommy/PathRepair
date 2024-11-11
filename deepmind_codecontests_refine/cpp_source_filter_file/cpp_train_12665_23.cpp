#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1000000000")
using namespace std;
inline void solve();
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solve();
}
string abc = "abcdefghijklmnopqrstuvwxyz";
string ABC = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
string digits = "0123456789";
long long n, k;
string s[105];
void solve() {
  cin >> n >> k;
  long long a[105][105] = {0};
  for (long long i = 0; i < n; i++) cin >> s[i];
  for (long long i = 0; i < n; i++)
    for (long long j = 0; j < n; j++) {
      bool f = true;
      for (long long t = 0; t < k && i + k < n; t++) {
        if (s[i + t][j] == '#') f = false;
      }
      if (i + k < n && f) {
        for (long long t = 0; t < k; t++) a[i + t][j]++;
      }
      f = true;
      for (long long t = 0; t < k && j + k < n; t++) {
        if (s[i][j + t] == '#') f = false;
      }
      if (j + k < n && f) {
        for (long long t = 0; t < k; t++) a[i][j + t]++;
      }
    }
  long long mi = 0, mj = 0;
  for (long long i = 0; i < n; i++)
    for (long long j = 0; j < n; j++)
      if (a[i][j] > a[mi][mj]) {
        mi = i;
        mj = j;
      }
  cout << mi + 1 << ' ' << mj + 1;
}
