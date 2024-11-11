#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18;
const long long MOD = 1e9 + 7;
const int N = 1e4 + 1;
string kmp(string a, string b) {
  string t = b + '#' + a;
  int n = (int)t.size();
  vector<int> p(n + 1);
  for (int i = 2; i < n; i++) {
    p[i] = p[i - 1];
    while (p[i] && t[i - 1] != t[p[i]]) p[i] = p[p[i]];
    if (t[i - 1] == t[p[i]]) ++p[i];
    if (p[i] == (int)b.size()) return a;
  }
  for (int i = p[n - 1]; i < b.size(); i++) a += b[i];
  return a;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int ans = INT_MAX;
  string second[3];
  for (int i = 0; i < 3; i++) cin >> second[i];
  int steps[] = {0, 1, 2};
  do {
    string cur = second[steps[0]];
    for (int i = 1; i < 3; i++) cur = kmp(cur, second[steps[i]]);
    ans = min(ans, (int)cur.size());
  } while (next_permutation(steps, steps + 3));
  cout << ans;
  return 0;
}
