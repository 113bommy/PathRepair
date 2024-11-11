#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/STACK:102400000,102400000")
long long mul(long long a, long long b) { return (a * b) % (1000000007); }
long long add(long long a, long long b) { return (a + b) % (1000000007); }
long long sub(long long a, long long b) {
  return ((a - b) % (1000000007) + (1000000007)) % (1000000007);
}
void upd(long long &a, long long b) {
  a = (a % (1000000007) + b % (1000000007)) % (1000000007);
}
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
long long a[123333];
int n;
long long Abs(long long x) { return max(-x, x); }
bool check(long long dis) {
  set<long long> S;
  S.insert(a[1]);
  S.insert(a[2]);
  for (int i = 3; i <= n; i++) {
    while (!S.empty() && Abs((*S.begin()) - a[i]) > dis) {
      S.erase(S.begin());
    }
    while (!S.empty() && Abs((*S.rbegin()) - a[i]) > dis) {
      S.erase(--S.end());
    }
    if (S.empty()) return 0;
    S.insert(a[i]);
  }
  return 1;
}
int main() {
  ios::sync_with_stdio(false);
  n = read() + 2;
  for (int i = 1; i <= n; i++) a[i] = read();
  long long l = Abs(a[1] - a[2]), r = 1e12, ans = 0;
  while (l < r) {
    long long m = l + r >> 1;
    if (check(m))
      ans = m, r = m - 1;
    else
      l = m + 1;
  }
  cout << ans << endl;
  return 0;
}
