#include <bits/stdc++.h>
using namespace std;
string a, b;
bool func(string s, long n) {
  if (s.size() % n) return false;
  for (long i = 0; i < s.size(); i++)
    if (s[i] != a[i % n]) return 0;
  return 1;
}
int main() {
  cin >> a >> b;
  long ans = 0, i = 1;
  string p = a, q = b;
  long minx = min(a.size(), b.size());
  while (i <= minx) {
    ans += (func(p, i) && func(q, i));
    i++;
  }
  cout << ans;
}
