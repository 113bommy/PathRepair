#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000100;
const int INF = 1e9 + 10;
int n, k;
char ts[maxn];
int a[maxn];
int val[maxn];
void go() {
  long long t = 0;
  for (int i = n; i >= 0; i--) {
    t = t * k + val[i];
    if (abs(t) > INF) {
      puts("No");
      return;
    }
  }
  puts(t ? "No" : "Yes");
}
void solve() {
  int now = 0;
  int cnt = n + 1;
  for (int i = 0; i <= n; i++)
    if (a[i]) now ^= 1, cnt--;
  if (cnt == 0)
    go();
  else {
    if (now == 0)
      puts(cnt & 1 ? "No" : "Yes");
    else
      puts(cnt & 1 ? "Yes" : "No");
  }
}
void work() {
  if (a[0] == 0) {
    int now = 0;
    for (int i = 0; i <= n + 1; i++)
      if (a[i]) now ^= 1;
    puts(now ? "Yes" : "No");
  } else
    puts(val[0] ? "No" : "Yes");
}
int main() {
  while (cin >> n >> k) {
    for (int i = 0; i <= n; i++) {
      scanf("%s", ts);
      if (ts[0] == '?')
        a[i] = 0;
      else
        a[i] = 1, sscanf(ts, "%d", &val[i]);
    }
    if (k == 0)
      work();
    else
      solve();
  }
  return 0;
}
