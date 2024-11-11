#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
using vii = vector<pair<int, int>>;
int main() {
  string s;
  cin >> s;
  int n = s.length();
  vi p(n);
  for (int i = 1; i < n; i++) {
    int j = p[i - 1];
    while (j > 0 && s[j] != s[i]) j = p[j - 1];
    if (s[j] == s[i]) ++j;
    p[i] = j;
  }
  int ans = 0;
  if (p[n - 1] > 0) {
    for (int i = 0; i < n - 1; i++) {
      if (p[i] == p[n - 1]) {
        ans = p[i];
        break;
      }
    }
    if (ans == 0) ans = p[p[n - 1]];
  }
  if (ans == 0)
    cout << "Just a legend" << endl;
  else
    cout << s.substr(0, ans) << endl;
}
