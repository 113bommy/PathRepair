#include <bits/stdc++.h>
using namespace std;
int Gcd(int a, int b) {
  if (b == 0) return a;
  return Gcd(b, a % b);
}
int Lcm(int a, int b) { return a / Gcd(a, b) * b; }
inline long long read() {
  long long f = 1, x = 0;
  char ch = getchar();
  while (ch > '9' || ch < '0') {
    if (ch == '-') f = -f;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
const int maxn = 2e6;
const int inf = 0x3f3f3f3f;
struct node {
  int d, f, t, c;
  bool operator<(const node& rhs) const { return d < rhs.d; }
} p[maxn];
vector<node> res[2];
long long sum[maxn], val[maxn];
long long sum2[maxn], val2[maxn];
int ok1[maxn], ok2[maxn];
int main() {
  int n = read(), m = read(), k = read();
  for (int i = 1; i <= m; i++) {
    p[i].d = read();
    p[i].f = read();
    p[i].t = read();
    p[i].c = read();
    if (p[i].t == 0) {
      res[0].push_back(p[i]);
    } else {
      res[1].push_back(p[i]);
    }
  }
  sort(res[0].begin(), res[0].end());
  sort(res[1].begin(), res[1].end());
  int cur1 = 0, cur2 = (int)res[1].size() - 1;
  for (int i = 1; i <= 1e6; i++) {
    val[i] = val2[i] = inf;
  }
  sum[0] = 1ll * inf * n;
  int cnt1 = 0, cnt2 = 0;
  for (int i = 1; i <= 1e6; i++) {
    sum[i] = sum[i - 1];
    while (cur1 < res[0].size() && i >= res[0][cur1].d) {
      int st = res[0][cur1].f;
      if (res[0][cur1].c < val[st]) {
        if (val[st] == inf) cnt1++;
        sum[i] -= val[st];
        val[st] = res[0][cur1].c;
        sum[i] += val[st];
      }
      cur1++;
    }
    if (cnt1 == n) ok1[i] = 1;
  }
  sum2[1000001] = 1ll * inf * n;
  for (int i = 1e6; i >= 1; i--) {
    sum2[i] = sum2[i + 1];
    while (cur2 >= 0 && i <= res[1][cur2].d) {
      int st = res[1][cur2].t;
      if (res[1][cur2].c < val2[st]) {
        if (val2[st] == inf) cnt2++;
        sum2[i] -= val2[st];
        val2[st] = res[1][cur2].c;
        sum2[i] += val2[st];
      }
      cur2--;
    }
    if (cnt2 == n) ok2[i] = 1;
  }
  long long ans = LLONG_MAX;
  for (int st = 1; st <= 1e6; st++) {
    int ed = st + k + 1;
    if (ok1[st] && ok2[ed]) {
      ans = min(ans, sum[st] + sum2[ed]);
    }
  }
  if (ans == LLONG_MAX)
    cout << -1 << endl;
  else
    cout << ans << endl;
  return 0;
}
