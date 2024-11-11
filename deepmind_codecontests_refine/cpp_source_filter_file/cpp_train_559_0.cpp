#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1.0);
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
const int limit = 5e5;
inline int read() {
  int x = 0;
  bool f = 1;
  char c = getchar();
  for (; !isdigit(c); c = getchar())
    if (c == '-') f = 0;
  for (; isdigit(c); c = getchar()) x = (x << 3) + (x << 1) + c - '0';
  if (f) return x;
  return 0 - x;
}
inline void write(long long x) {
  if (x < 0) {
    putchar('-');
    x = -x;
  }
  if (x > 9) write(x / 10);
  putchar(x % 10 + '0');
}
const long long mod = 1e9;
const int N = 3e5 + 5;
int n, m;
int i, j, k;
int a[N];
map<int, int> mp;
vector<int> ans;
long long sum[N];
int main() {
  while (~scanf("%d", &n)) {
    long long tot = 0;
    for (int i = 1; i <= (n); i++) {
      scanf("%d", &a[i]);
      if (a[i] >= 0)
        sum[i] = sum[i - 1] + a[i], tot += a[i];
      else
        sum[i] = sum[i - 1];
      mp[a[i]] = i;
    }
    long long l = 0, r = n + 1, maxx = -9e18;
    for (int i = 1; i <= (n); i++) {
      if (mp[a[i]] > i) {
        long long pre = sum[i - 1], suf = sum[n] - sum[mp[a[i]]];
        long long tmp;
        if (a[i] >= 0)
          tmp = tot - pre - suf;
        else
          tmp = tot - pre - suf + 2 * a[i];
        if (tmp > maxx) {
          l = i, r = mp[a[i]];
          maxx = tmp;
        }
      }
    }
    for (int i = 1; i <= (n); i++) {
      if (i >= 1 && i < l)
        ans.push_back(i);
      else if (i <= n && i > r)
        ans.push_back(i);
      else if (i >= l && i <= r && a[i] < 0)
        ans.push_back(i);
    }
    printf("%lld %d\n", maxx, ans.size());
    for (int i = 0; i < ans.size(); i++) printf("%d ", ans[i]);
  }
  return 0;
}
