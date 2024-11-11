#include <bits/stdc++.h>
using namespace std;
const int N = 300005;
long long ans = 0;
int n, p, c[N], tot, num[N], len, cnt[N], a[N], b[N];
vector<int> l;
map<pair<int, int>, int> mp;
inline int read() {
  int f = 1, x = 0;
  char ch = getchar();
  while (ch > '9' || ch < '0') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return f * x;
}
int main() {
  n = read(), p = read();
  for (int i = (1), iend = (n); i <= iend; i++) {
    a[i] = read(), b[i] = read();
    if (a[i] > b[i]) swap(a[i], b[i]);
    if (mp[make_pair(a[i], b[i])] == 0) mp[make_pair(a[i], b[i])] = ++tot;
    cnt[mp[make_pair(a[i], b[i])]]++;
    num[a[i]]++, num[b[i]]++;
  }
  for (int i = (1), iend = (n); i <= iend; i++) l.push_back(num[i]);
  sort(l.begin(), l.end());
  for (int i = (1), iend = (n); i <= iend; i++) {
    if ((p - num[i]) > l[l.size() - 1]) continue;
    ans += l.end() - lower_bound(l.begin(), l.end(), p - num[i]) -
           (p - num[i] <= num[i]);
  }
  for (int i = (1), iend = (n); i <= iend; i++)
    if (num[a[i]] + num[b[i]] >= p &&
        num[a[i]] + num[b[i]] - cnt[mp[make_pair(a[i], b[i])]] < p) {
      ans -= 2, cnt[mp[make_pair(a[i], b[i])]] = 0;
    }
  printf("%lld", ans / 2);
  return 0;
}
