#include <bits/stdc++.h>
using namespace std;
namespace Base {
const int inf = 0x3f3f3f3f, INF = 0x7fffffff;
const long long infll = 0x3f3f3f3f3f3f3f3fll, INFll = 0x7fffffffffffffffll;
template <typename T>
void read(T &x) {
  x = 0;
  int fh = 1;
  double num = 1.0;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') fh = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  if (ch == '.') {
    ch = getchar();
    while (isdigit(ch)) {
      num /= 10;
      x = x + num * (ch - '0');
      ch = getchar();
    }
  }
  x = x * fh;
}
template <typename T>
void chmax(T &x, T y) {
  x = x < y ? y : x;
}
template <typename T>
void chmin(T &x, T y) {
  x = x > y ? y : x;
}
}  // namespace Base
using namespace Base;
const int N = 200010;
long long n, k, a[N], b[N], cnt[N];
set<pair<int, int> > mp;
vector<pair<int, int> > inc[N];
long long chnum(int x) {
  memset(cnt, 0, sizeof(cnt));
  int now = 0;
  long long sum = 0;
  for (int i = 1; i <= n; i++) {
    for (unsigned j = 0; j < inc[i].size(); j++) {
      cnt[max(now + 1, inc[i][j].first)] += inc[i][j].second;
      cnt[i + 1] -= inc[i][j].second;
    }
    while (now < n && cnt[now + 1] >= x) {
      cnt[now + 2] += cnt[now + 1];
      now++;
    }
    sum = sum + now;
  }
  return sum;
}
long long chsum(int x) {
  memset(cnt, 0, sizeof(cnt));
  int now = 0;
  long long num = 0, sum = 0;
  for (int i = 1; i <= n; i++) {
    for (unsigned j = 0; j < inc[i].size(); j++) {
      if (now >= inc[i][j].first)
        num = num + (now - inc[i][j].second + 1ll) * inc[i][j].second;
      cnt[max(now + 1, inc[i][j].first)] += inc[i][j].second;
      cnt[i + 1] -= inc[i][j].second;
    }
    while (now < n && cnt[now + 1] >= x) {
      num = num + cnt[now + 1];
      cnt[now + 2] += cnt[now + 1];
      now++;
    }
    sum = sum + num;
  }
  return sum;
}
int main() {
  read(n), read(k);
  for (int i = 1; i <= n; i++) read(a[i]), read(b[i]), b[i] -= 1;
  mp.insert(make_pair(0, 0));
  mp.insert(make_pair(inf, n + 1));
  for (int i = 1; i <= n; i++) {
    set<pair<int, int> >::iterator id = mp.lower_bound(make_pair(a[i], 0));
    int ti = (*(--id)).second;
    id++;
    int tmp = (*id).first, las = a[i] - 1;
    while (tmp - 1 <= b[i]) {
      inc[i].push_back(make_pair(ti + 1, tmp - las - 1));
      las = tmp - 1;
      ti = (*id).second;
      mp.erase(id);
      id = mp.lower_bound(make_pair(a[i], 0));
      tmp = (*id).first;
    }
    inc[i].push_back(make_pair(ti + 1, b[i] - las));
    mp.insert(make_pair(b[i] + 1, ti));
    mp.insert(make_pair(a[i], i));
  }
  int pl = 1, pr = inf, lim = 0;
  while (pl <= pr) {
    int mid = (pl + pr) / 2;
    if (chnum(mid) >= k)
      lim = mid, pl = mid + 1;
    else
      pr = mid - 1;
  }
  long long tmp = k - chnum(lim + 1);
  long long ans = tmp * lim + chsum(lim + 1);
  printf("%lld\n", ans);
  return 0;
}
