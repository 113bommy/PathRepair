#include <bits/stdc++.h>
using namespace std;
set<long long> dic;
long long f[600100];
const long long X = 257;
void mfa() {
  f[0] = 1;
  for (long long i = 1; i < 600100; i++) {
    f[i] = (f[i - 1] * X) % 10000000000;
  }
}
long long hsh(string s) {
  long long x = 0;
  long long l = s.size();
  for (long long i = 0; i < l; i++) {
    x = (x * X + s[i]) % 10000000000;
  }
  return x;
}
bool chck(string s) {
  long long h = hsh(s);
  long long l = s.size();
  for (long long i = 0; i < l; i++) {
    for (long long c = 'a'; c <= 'c'; c++) {
      if (c == s[i]) continue;
      long long x =
          (((c - s[i]) * f[l - 1 - i]) % 10000000000 + 10000000000 + h) %
          10000000000;
      if (dic.count(x)) return 1;
    }
  }
  return 0;
}
int main() {
  mfa();
  long long n, m;
  cin >> n >> m;
  for (long long i = 0; i < n; i++) {
    string s;
    cin >> s;
    long long h1 = hsh(s);
    dic.insert(h1);
  }
  for (long long i = 0; i < m; i++) {
    string s;
    cin >> s;
    if (chck(s))
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
}
