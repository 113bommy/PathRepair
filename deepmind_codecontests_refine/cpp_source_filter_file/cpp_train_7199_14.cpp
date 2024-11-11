#include <bits/stdc++.h>
using namespace std;
long long MOD = 1e9 + 7;
long long INF = 1e18;
void chmin(long long &a, long long b) {
  if (a > b) a = b;
}
void chmax(long long &a, long long b) {
  if (a < b) a = b;
}
void pmod(long long &a, long long b) { a = (a + b) % MOD; }
void qmod(long long &a, long long b) { a = (a * b) % MOD; }
void ans1(bool x) {
  if (x)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}
void ans2(bool x) {
  if (x)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}
void ans3(bool x) {
  if (x)
    cout << "Yay!" << endl;
  else
    cout << ":(" << endl;
}
void ans(bool x, long long y, long long z) {
  if (x)
    cout << y << endl;
  else
    cout << z << endl;
}
int main() {
  long long i, j, o;
  long long result = INF, buf = 0, buf1 = 0, buf2 = 0, buf3 = 0, buf4 = 0;
  bool judge = true;
  long long n;
  cin >> n;
  vector<long long> a(n), b(n), d(n + 1);
  for (i = 0; i < n; i++) cin >> a[i];
  for (i = 0; i < n; i++) cin >> b[i];
  for (i = 0; i < n; i++) {
    if (b[i] != 0) d[b[i]] = i + 1;
  }
  buf3 = b[n - 1];
  if (buf3 != 0) {
    for (i = 0; i < n; i++) {
      if (b[n - i - 1] == buf3 - i && buf3 != i)
        buf++;
      else
        break;
    }
    if (buf == n) result = 0;
  }
  if (buf > 0) {
    for (i = buf + 1; i <= n; i++) {
      if (d[i] > i - buf)
        break;
      else if (i == n)
        result = n - buf;
    }
  }
  for (i = 1; i <= n; i++) {
    chmax(buf2, d[i] + 1 - i);
  }
  chmin(result, buf2 + n);
  cout << result << endl;
  return 0;
}
