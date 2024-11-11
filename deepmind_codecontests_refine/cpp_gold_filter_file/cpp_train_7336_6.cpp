#include <bits/stdc++.h>
using namespace std;
string s, t;
vector<int> a, b;
signed main() {
  cin >> s >> t;
  int n = s.length();
  for (int i = 0; i < n; i++) {
    a.emplace_back(s[i] - 'a');
  }
  for (int i = 0; i < n; i++) {
    b.emplace_back(t[i] - 'a');
  }
  a[n - 1]++;
  reverse(a.begin(), a.end());
  for (int i = 0; i < a.size() - 1; i++) {
    if (a[i] >= 26) {
      a[i + 1] += a[i] / 26;
      a[i] %= 26;
    }
  }
  if (a[n - 1] > 26) {
    cout << "No such string" << endl;
    return 0;
  }
  reverse(a.begin(), a.end());
  int ok = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] != b[i]) {
      ok = 1;
      break;
    }
  }
  if (!ok)
    cout << "No such string" << endl;
  else {
    for (int i = 0; i < n; i++) {
      cout << char('a' + a[i]);
    }
    cout << endl;
  }
  return 0;
}
