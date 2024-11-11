#include <bits/stdc++.h>
using namespace std;
int ch[100] = {}, len = 0;
long long min(long long a, long long b) { return (a < b) ? a : b; }
long long dec() {
  long long res = 0;
  for (int i = len - 1; i >= 0; i--)
    if (!ch[i])
      res = res * 10 + 4;
    else
      res = res * 10 + 7;
  return res;
}
void next() {
  ch[0]++;
  for (int i = 0; i < len; i++) {
    ch[i + 1] += ch[i] / 2;
    ch[i] %= 2;
  }
  if (ch[len]) ch[len++] = 0;
}
int main() {
  long long l, r;
  cin >> l >> r;
  long long k = 4;
  len = 1;
  ch[0] = 0;
  for (; k < l; next(), k = dec()) {
  }
  long long ans = 0;
  for (long long i = l; i <= r;) {
    ans += k * (min(k, r) - i + 1);
    i = k + 1;
    next(), k = dec();
  }
  cout << ans;
}
