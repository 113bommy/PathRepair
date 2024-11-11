#include <bits/stdc++.h>
using namespace std;
long long power(long long x, long long y, long long p) {
  long long res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
long long PO(long long a, long long n) {
  long long val = 1;
  for (long long i = 0; i < n; i++) val *= a;
  return val;
}
bool sortbysec(const pair<long long, long long> &a,
               const pair<long long, long long> &b) {
  return (a.second < b.second);
}
signed main() {
  long long t;
  cin >> t;
  while (t--) {
    long long cnt = 0;
    string s;
    cin >> s;
    long long n = s.length();
    long long second[n + 1];
    long long pre[n + 1];
    pre[0] = 0;
    for (long long i = 1; i <= n; i++) {
      second[i] = (long long)s[i - 1] - (long long)'0';
    }
    for (long long i = 1; i <= n; i++) {
      if (second[i] == 1) cnt++;
      if (i + 1 <= n) {
        if (second[i] == 1 && second[i + 1] == 0) cnt++;
      }
    }
    for (long long i = 1; i <= n; i++) {
      pre[i] = pre[i - 1] + second[i];
    }
    for (long long i = 2; i <= 20; i++) {
      for (long long j = 1; j <= n - i + 1; j++) {
        if (second[j] == 0) continue;
        long long tt = 0;
        long long xx = 0;
        for (long long k = j + i - 1; k >= j; k--) {
          tt += pow(2, xx) * second[k];
          xx++;
        }
        long long curl = i;
        long long resl = tt - curl;
        if (j - resl - 1 >= 0 && resl > 0) {
          if (pre[j - 1] - pre[j - resl - 1] == 0) cnt++;
        }
      }
    }
    cout << cnt << "\n";
  }
}
