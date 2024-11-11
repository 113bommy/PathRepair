#include <bits/stdc++.h>
using namespace std;
string s1, s2;
bool chek(int in, string &s) {
  int n = (int)s.size();
  if (n % in) return false;
  for (int i = 0; i < n; i++)
    if (s[i] != s[i % in]) return false;
  return true;
}
int main() {
  cin >> s1 >> s2;
  int a = (int)s1.size();
  int b = (int)s2.size();
  long long ans = 0;
  if (a <= b) {
    if (s1 != s2.substr(a)) {
      cout << 0 << endl;
      return 0;
    }
    for (int i = 1; i * i <= a; i++)
      if (a % i == 0) {
        if (chek(i, s1) && chek(i, s2)) ans++;
        if (i * i != a)
          if (chek((a / i), s1) && chek((a / i), s2)) ans++;
      }
  } else {
    if (s2 != s1.substr(b)) {
      cout << 0 << endl;
      return 0;
    }
    for (int i = 1; i * i <= b; i++)
      if (b % i == 0) {
        if (chek(i, s1) && chek(i, s2)) ans++;
        if (i * i != b)
          if (chek((b / i), s1) && chek((b / i), s2)) ans++;
      }
  }
  cout << ans << endl;
  return 0;
}
