#include <bits/stdc++.h>
using namespace std;
const long long N = 1e5 + 7, MAXN = 1e6 + 7, INF = 0x3f3f3f3f;
long long fpow(long long a, long long b, long long p) {
  long long ans = 1LL;
  while (b) {
    if (b & 1) ans = ans * a % p;
    b >>= 1;
    a = a * a % p;
  }
  return ans % p;
}
template <class T>
inline void read(T &ret) {
  char c;
  ret = 0;
  while ((c = getchar()) < '0' || c > '9')
    ;
  while (c >= '0' && c <= '9') {
    ret = ret * 10 + (c - '0'), c = getchar();
  }
}
long long n;
long long a[N];
map<long long, long long> m;
priority_queue<long long, vector<long long>, greater<long long> > q;
int main() {
  read(n);
  long long ans = 0, cnt = 0;
  while (q.size()) q.pop();
  m.clear();
  for (long long i = 1; i <= n; i++) {
    read(a[i]);
    if (q.empty() || q.top() >= a[i])
      q.push(a[i]);
    else {
      long long tmp = q.top();
      q.pop();
      ans += a[i] - tmp;
      cnt += 2LL;
      if (m[tmp] > 0) {
        cnt -= 2LL;
        m[tmp]--;
      }
      q.push(a[i]);
      q.push(a[i]);
      m[a[i]]++;
    }
  }
  printf("%lld\n", ans);
  return 0;
}
