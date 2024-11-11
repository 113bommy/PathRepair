#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  char ch = getchar();
  long long p = 1, data = 0;
  while (ch < '0' || ch > '9') {
    if (ch == '-') p = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    data = data * 10 + (ch ^ 48);
    ch = getchar();
  }
  return p * data;
}
inline long long qpow(long long a, long long b) {
  long long r = 1;
  while (b) {
    if (b & 1) r = a * r;
    a = a * a;
    b >>= 1;
  }
  return r;
}
inline long long gcd(long long a, long long b) {
  while (b ^= a ^= b ^= a %= b)
    ;
  return a;
}
inline long long lcm(long long a, long long b) { return a * b / gcd(a, b); }
void exgcd(long long a, long long b, long long &x, long long &y) {
  if (!b)
    x = 1, y = 0;
  else {
    exgcd(b, a % b, y, x);
    y -= x * (a / b);
  }
}
const int mod = 1e9 + 7;
char s[55][5];
string name[55];
int main() {
  int n = read(), k = read();
  for (int i = 1; i <= n - k + 1; i++) scanf("%s", s[i] + 1);
  char t[5] = {'A', 'a', 'a', 'a', 'a'};
  for (int i = 1; i <= k - 1; i++) {
    for (int j = 0; j <= 4; j++) name[i] += t[j];
    for (int j = 4; j >= 0; j--) {
      t[j]++;
      if (t[j] > 'a' + 25)
        t[j]--, t[j - 1]++;
      else
        break;
    }
  }
  char s1 = 'A', s2 = 'a' - 1;
  for (int i = k; i <= n; i++) {
    if (s[i - k + 1][1] == 'N')
      name[i] = name[max(1, i - k + 1)];
    else {
      s2++;
      if (s2 > 'a' + 25) s2 = 'a', s1++;
      name[i] += s1;
      name[i] += s2;
    }
  }
  for (int i = 1; i <= n; i++) printf("%s ", name[i].c_str());
  return 0;
}
