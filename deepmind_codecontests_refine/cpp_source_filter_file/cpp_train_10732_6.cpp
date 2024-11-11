#include <bits/stdc++.h>
using namespace std;
const int M = 1e9 + 7;
long long powmod(long long a, long long b) {
  long long res = 1;
  a %= M;
  assert(b >= 0);
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % M;
    a = a * a % M;
  }
  return res % M;
}
const int N = 1e5 + 10;
int a[20];
int main() {
  int n, m;
  cin >> n >> m;
  string s, t;
  cin >> s >> t;
  if (s == t)
    puts("YES");
  else {
    int id = -1;
    for (int i = 0; i < n; i++) {
      if (s[i] == '*') {
        id = i;
        break;
      }
    }
    int ok = 0;
    if (id == -1) {
      puts("NO");
      return 0;
    }
    int y = 0;
    for (int i = 0; i < id; i++) {
      if (s[i] != t[i]) {
        ok = 1;
        break;
      } else
        y = i;
    }
    if (ok == 1)
      puts("NO");
    else {
      int j = m - 1;
      for (int i = n - 1; i > id; i--, j--) {
        if (s[i] != t[j]) {
          ok = 1;
          break;
        }
      }
      if (ok == 1)
        puts("NO");
      else if (j < y)
        puts("NO");
      else
        puts("YES");
    }
  }
  return 0;
}
