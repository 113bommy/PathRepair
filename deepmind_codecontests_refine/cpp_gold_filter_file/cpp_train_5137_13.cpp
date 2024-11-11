#include <bits/stdc++.h>
using namespace std;
int i, n, m, rs;
string a, b;
bool Check(string a, int p, int n) {
  for (int i = 0; i < n; ++i)
    if (a[i] != a[i % p]) return 0;
  return 1;
}
bool Check2(string a, string b, int n) {
  for (int i = 0; i < n; ++i)
    if (a[i] != b[i]) return 0;
  return 1;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  getline(cin, a);
  n = a.length();
  getline(cin, b);
  m = b.length();
  if (n > m) swap(n, m), swap(a, b);
  for (i = 1; i <= n; ++i)
    if (n % i == 0 && m % i == 0) {
      if (!Check(a, i, n)) continue;
      if (!Check(b, i, m)) continue;
      if (!Check2(a, b, i)) continue;
      ++rs;
    }
  cout << rs << '\n';
  return 0;
}
