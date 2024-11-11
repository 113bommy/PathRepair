#include <bits/stdc++.h>
using namespace std;
int cnt[10];
int calLen(long long n) {
  int ret = 0;
  while (n) {
    n /= 10;
    ret++;
  }
  return ret;
}
long long pow10(int len) {
  long long ret = 1;
  for (int i = 0; i < len; i++) ret *= 10;
  return ret;
}
int main() {
  long long w, m, k, ans = 0;
  cin >> w >> m >> k;
  int len = calLen(m);
  long long cnt = w / (k * len);
  while (cnt > 0) {
    long long next = m + cnt;
    long long lenNext = calLen(next);
    if (lenNext > len) cnt = pow10(len) - m, m = pow10(len);
    w = w - cnt * k * len;
    ans += cnt;
    if (lenNext > len) len = lenNext;
    cnt = w / (k * len);
  }
  cout << ans << endl;
}
