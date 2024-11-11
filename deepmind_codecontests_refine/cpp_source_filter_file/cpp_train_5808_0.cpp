#include <bits/stdc++.h>
using namespace std;
long long n, d[3] = {}, sum;
string res;
vector<string> s;
bool solve();
int main() {
  cin >> n;
  for (int i = 0; i < 3; ++i) cin >> d[i];
  s.resize(n);
  for (int i = 0; i < n; ++i) cin >> s[i];
  if (solve()) {
    cout << "Yes" << endl;
    for (int i = 0; i < n; ++i) cout << res[i] << endl;
  } else
    cout << "No" << endl;
  return 0;
}
bool solve() {
  sum = d[0] + d[1] + d[2];
  if (sum == 0) return 0;
  for (int i = 0; i < n; ++i) {
    string now = s[i];
    long long x[2] = {now[0] - 'A', now[1] - 'A'}, p = 0;
    if (d[x[0]] > d[x[1]])
      p = 0;
    else if (d[x[0]] < d[x[1]])
      p = 1;
    else if (d[x[0]] == 0)
      return 0;
    else {
      if (i + 1 < n && s[i] != s[i + 1]) {
        long long y[2] = {s[i + 1][0] - 'A', s[i + 1][1] - 'A'};
        if (x[0] == y[0] || x[0] == y[1]) p = 1;
      }
    }
    --d[x[p]];
    ++d[x[1 - p]];
    res += x[p] + 'A';
  }
  return 1;
}
