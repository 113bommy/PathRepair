#include <bits/stdc++.h>
using namespace std;
long long modpow(int n, int p, int m) {
  long long ret = 1;
  for (int i = 0; i < p; ++i) ret = (ret * n) % m;
  return ret;
}
int zBase64(char c) {
  int n, ret = 0;
  if (c > '0' && c < '9')
    n = c - '0';
  else if (c >= 'A' && c <= 'Z')
    n = c - 'A' + 10;
  else if (c >= 'a' && c <= 'z')
    n = c - 'a' + 36;
  else if (c == '-')
    n = 62;
  else
    n = 63;
  for (int i = 0; i < 6; ++i) {
    if (n % 2 == 0) ret++;
    n /= 2;
  }
  return ret;
}
int main() {
  long long z = 0;
  string s;
  cin >> s;
  for (char c : s) z += zBase64(c);
  cout << modpow(3, z, 1e9 + 7);
  return 0;
}
