#include <bits/stdc++.h>
using namespace std;
string s, t;
bool check(string a, int d) {
  int n = a.size();
  for (int i = 0; i < n; ++i) {
    if (s[i % d] != a[i]) return false;
  }
  return true;
}
int main() {
  cin >> s >> t;
  int n = s.size();
  int m = t.size();
  int cnt = 0;
  for (int i = 1; i < max(n, m); i++) {
    if (n % i == 0 && m % i == 0) {
      if (check(s, i) && check(t, i)) ++cnt;
    }
  }
  printf("%d\n", cnt);
}
