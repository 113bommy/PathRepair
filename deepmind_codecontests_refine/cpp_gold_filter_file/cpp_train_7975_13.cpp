#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const double EPS = 1e-6;
inline void read(long long& x) {
  int f = 1;
  char c;
  while (((c = getchar()) < '0' || c > '9') && c != '-')
    ;
  c == '-' ? (f = -1, x = 0) : (x = c - '0');
  while ((c = getchar()) >= '0' && c <= '9') x = x * 10 + c - '0';
  x *= f;
}
inline void read(int& x) {
  long long t;
  read(t);
  x = t;
}
struct node {
  int i, t, d, p;
} a[205];
vector<int> s[2005];
bool cmp(const node& a, const node& b) { return a.d < b.d; }
int dp[2005];
int main() {
  int n;
  read(n);
  for (int i = 1; i <= n; i++) {
    read(a[i].t);
    read(a[i].d);
    read(a[i].p);
    a[i].i = i;
  }
  sort(a + 1, a + n + 1, cmp);
  for (int i = 1; i <= n; i++) {
    for (int j = a[i].d - 1; j >= a[i].t; j--) {
      if (dp[j] < dp[j - a[i].t] + a[i].p) {
        dp[j] = dp[j - a[i].t] + a[i].p;
        s[j] = s[j - a[i].t];
        s[j].push_back(a[i].i);
      }
    }
  }
  int ans = 0, pos = 0;
  for (int i = 1; i <= a[n].d; i++) {
    if (ans < dp[i]) {
      ans = dp[i];
      pos = i;
    }
  }
  printf("%d\n", ans);
  printf("%d\n", int((s[pos]).size()));
  for (int i = 0; i < int((s[pos]).size()); i++) printf("%d ", s[pos][i]);
  return 0;
}
