#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long x = 0, f = 1;
  char c = getchar();
  for (; !isdigit(c); c = getchar())
    if (c == '-') f = -1;
  for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
  return x * f;
}
const long long MAXN = 100010;
const long long INF = 2147483600;
long long N;
long long a[MAXN + 1], b[MAXN + 1];
vector<long long> Last[63], T[63];
int main() {
  N = read();
  long long sum = 0;
  for (long long i = 1; i <= N; i++) a[i] = read(), b[i] = read();
  for (long long i = 1; i <= N; i++) {
    bool flag = false;
    for (long long j = 61; j >= 0; j--) {
      if (!((b[i] >> j) & 1)) continue;
      if (!flag) {
        Last[j].push_back(i);
        flag = true;
      }
      T[j].push_back(i);
    }
    sum += a[i];
  }
  long long base = 1, ans = 0;
  for (long long i = 0; i < 62; i++) {
    long long tot = 0;
    for (long long j = 0; j < Last[i].size(); j++) tot += a[Last[i][j]];
    if ((tot > 0 && sum > 0) || (tot < 0 && sum < 0)) {
      for (long long j = 0; j < T[i].size(); j++) a[T[i][j]] = -a[T[i][j]];
      ans += base;
    }
    base <<= 1;
  }
  cout << ans << endl;
  return 0;
}
