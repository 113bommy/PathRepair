#include <bits/stdc++.h>
using namespace std;
string removeChar(string str, char c) {
  str.erase(remove(str.begin(), str.end(), c), str.end());
  return str;
}
long long nCr(int n, int r) {
  int f1 = r, f2 = n - r;
  if (f2 > f1) swap(f2, f1);
  long long result = 1;
  for (int i = 1; i <= f2; i++) {
    result *= (i + f1);
    result /= i;
  }
  return result;
}
long long nPr(int n, int r, long long mod = 0) {
  long long result = 1;
  for (int i = n - r + 1; i <= n; i++) {
    result *= i;
    if (mod) result %= mod;
  }
  return result;
}
long long factorial(int n, long long modulo = 0) {
  if (n == 0) return 1;
  if (modulo)
    return (n * factorial(n - 1)) % modulo;
  else
    return n * factorial(n - 1);
}
int main() {
  ios_base ::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  string a, b, c, s, st, cmp = "ABC";
  char fnl[3];
  long long i, j, n, k;
  cin >> a >> b >> c;
  if (a[1] == '<')
    s += a[2];
  else
    s += a[0];
  if (b[1] == '<')
    s += b[2];
  else
    s += b[0];
  if (c[1] == '<')
    s += c[2];
  else
    s += c[0];
  sort(s.begin(), s.end());
  if (s == cmp)
    cout << "Impossible" << endl;
  else {
    if (s[0] == s[1]) {
      fnl[0] = s[0];
      fnl[1] = s[2];
    } else if (s[1] == s[2]) {
      fnl[0] = s[1];
      fnl[1] = s[0];
    }
    for (i = 0; i < 3; i++) {
      k = 0;
      for (j = 0; j < 2; j++)
        if (cmp[i] != fnl[j]) {
          k++;
          if (k == 2) {
            fnl[2] = cmp[i];
          }
        }
    }
  }
  for (i = 2; i >= 0; i--) cout << fnl[i];
}
