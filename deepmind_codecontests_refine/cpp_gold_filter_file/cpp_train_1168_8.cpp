#include <bits/stdc++.h>
using namespace std;
template <typename T>
T solve(string s, int a, int b, int p) {
  T ans = 0;
  int i = s.length() - 2;
  while (i >= 0) {
    int j = i;
    while (j > 0 and s[j - 1] == s[j]) j--;
    if (s[i] == 'A')
      p -= a;
    else
      p -= b;
    if (p == 0 and j)
      return j + 1;
    else if (p < 0)
      break;
    i = j - 1;
  }
  return i + 2;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t) {
    int a, b, p;
    cin >> a >> b >> p;
    string s;
    cin >> s;
    cout << solve<int>(s, a, b, p);
    cout << endl;
    t--;
  }
  return 0;
}
