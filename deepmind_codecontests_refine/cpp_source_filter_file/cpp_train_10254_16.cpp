#include <bits/stdc++.h>
using namespace std;
template <class T, class T1>
int chkmin(T &x, const T1 &y) {
  return x > y ? x = y, 1 : 0;
}
template <class T, class T1>
int chkmax(T &x, const T1 &y) {
  return x < y ? x = y, 1 : 0;
}
const int MAXN = (1 << 20);
bool check(string s1, string s2) {
  if (s1 == s2) return true;
  if (s1.size() % 2 == 1) return (s1 == s2);
  long long n = s1.size();
  string c1 = s1.substr(0, n / 2);
  string c2 = s1.substr(n / 2, n / 2);
  string c3 = s2.substr(0, n / 2);
  string c4 = s2.substr(n / 2, n / 2);
  return (check(c1, c4) && check(c1, c3) || check(c2, c3) && check(c2, c4));
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long T = 1;
  for (long long t = 0; t < T; t++) {
    string s1, s2;
    cin >> s1 >> s2;
    bool c = check(s1, s2);
    if (c)
      cout << "YES" << '\n';
    else
      cout << "NO" << '\n';
  }
  return 0;
}
