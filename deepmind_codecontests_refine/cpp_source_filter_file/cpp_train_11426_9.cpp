#include <bits/stdc++.h>
using namespace std;
int dx[] = {0, 1, 0, -1, -1, 1, 1, -1};
int dy[] = {1, 0, -1, 0, -1, -1, 1, 1};
int kx[] = {-2, -2, -1, 1, 2, 2, 1, -1};
int ky[] = {-1, 1, 2, 2, 1, -1, -2, -2};
inline long long gcd(long long a, long long b) {
  a = fabs(a);
  b = fabs(b);
  while (b) {
    a = a % b;
    swap(a, b);
  }
  return a;
}
inline long long bigmod(long long a, long long p, long long m) {
  long long res = 1 % m, x = a % m;
  while (p) {
    if (p & 1) res = (res * x) % m;
    x = (x * x) % m;
    p >>= 1;
  }
  return res;
}
struct DATA {};
int res = 0;
void check(string str) {
  bool p = 1;
  int k = str.size() - 1;
  for (int i = (int)(0); i <= (int)(str.size() - 1 / 2); i++) {
    if (str[i] != str[k]) p = 0;
    k--;
  }
  if (!p) {
    res = max(res, (int)str.size());
  }
}
int main() {
  string str;
  cin >> str;
  int len = str.size();
  for (int i = (int)(0); i <= (int)(str.size() - 1); i++) {
    for (int j = (int)(0); j <= (int)(str.size() - 1 + 1); j++) {
      if (j > len - i) continue;
      check(str.substr(i, j));
    }
  }
  cout << res << endl;
  return 0;
}
