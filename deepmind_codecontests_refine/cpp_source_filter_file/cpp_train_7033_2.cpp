#include <bits/stdc++.h>
using namespace std;
bool check(int x, int pos) { return (bool)(x & (1 << pos)); }
int st(int x, int pos) { return x = x | (1 << pos); }
int Reset(int x, int pos) { return x = x & ~(1 << pos); }
long long sub[200006], day[200006], last[200006];
int main() {
  long long n, m;
  cin >> n >> m;
  for (long long i = 1; i <= n; i++) {
    scanf("%lld", &sub[i]);
  }
  for (long long i = 1; i <= m; i++) scanf("%lld", &day[i]);
  long long l = 1, h = n;
  bool ys = false;
  while (l < h) {
    long long mm = (l + h) / 2;
    for (long long j = 1; j <= m; j++) last[j] = 0;
    for (long long j = mm; j >= 1; j--) {
      if (sub[j] == 0) continue;
      if (last[sub[j]] == 0) last[sub[j]] = j;
    }
    long long ans = 0, d = 0;
    bool no = false;
    for (long long j = 1; j <= mm; j++) {
      if (last[sub[j]] == j) {
        if (d >= day[sub[j]]) {
          ans++;
          d -= day[sub[j]];
        } else {
          no = true;
          break;
        }
      } else {
        d++;
      }
    }
    if (ans < m) no = true;
    if (!no) {
      ys = true;
      h = mm;
    } else {
      l = mm + 1;
    }
  }
  if (ys)
    cout << l << endl;
  else
    puts("-1");
}
