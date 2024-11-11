#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 1000;
inline long long read() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - 48;
    ch = getchar();
  }
  return x * f;
}
deque<long long> que;
long long a[maxn];
struct P {
  long long fi, se;
} ans1[maxn * 2], ans2[maxn * 2];
long long tot1 = 0, tot2 = 0;
int main(void) {
  cin.tie(0);
  std::ios::sync_with_stdio(false);
  long long n, q;
  cin >> n >> q;
  long long mx = -1;
  long long pos = 0;
  for (long long i = 1; i <= n; i++) {
    cin >> a[i];
    que.push_back(a[i]);
    if (mx < a[i]) {
      mx = a[i];
      pos = i;
    }
  }
  for (long long i = 1; i <= 2 * n; i++) {
    long long one = que.front();
    que.pop_front();
    long long two = que.front();
    que.pop_front();
    ans1[++tot1].fi = one;
    ans1[tot1].se = two;
    if (one == mx) {
      ans2[++tot2].fi = one;
      ans2[tot2].se = two;
    }
    if (one > two) {
      que.push_front(one);
      que.push_back(two);
    } else {
      que.push_front(two);
      que.push_back(one);
    }
  }
  while (q--) {
    long long m;
    cin >> m;
    if (m <= pos) {
      cout << ans1[m].fi << " " << ans1[m].se << "\n";
    } else {
      long long cnt = m - pos;
      long long mod = cnt % (n - 1) + 1;
      cout << ans2[mod].fi << " " << ans2[mod].se << "\n";
    }
  }
  return 0;
}
