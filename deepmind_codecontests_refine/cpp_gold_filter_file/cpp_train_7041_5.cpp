#include <bits/stdc++.h>
using namespace std;
int n, a[5005][5005], b[5005][5005], res;
string s;
void Solve() {
  cin >> s;
  n = s.size();
  s = " " + s;
  for (long long i = 1, _b = n; i <= _b; i++) {
    long long cur = 0;
    bool ok = true;
    for (long long j = i, _b = n; j <= _b; j++) {
      if (s[j] == ')')
        cur--;
      else
        cur++;
      if (cur < 0) ok = false;
      a[i][j] = ok;
    }
  }
  for (long long j = 1, _b = n; j <= _b; j++) {
    long long cur = 0;
    bool ok = true;
    for (long long i = j, _b = 1; i >= _b; i--) {
      if (s[i] == '(')
        cur--;
      else
        cur++;
      if (cur < 0) ok = false;
      b[i][j] = ok;
    }
  }
  for (long long i = 1, _b = n; i <= _b; i++)
    for (long long j = i + 1; j <= n; j += 2) {
      if (a[i][j] && b[i][j]) res++;
    }
  cout << res;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int Test_numbers = 1;
  while (Test_numbers--) Solve();
  return 0;
}
