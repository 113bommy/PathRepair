#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 2e5 + 50;
struct pad {
  long long last;
  long long res;
  long long per;
  long long nt;
} a[MAXN];
long long n, k, t = 0;
bool operator<(pad a, pad b) { return a.nt > b.nt; }
priority_queue<pad> p, q;
bool check(long long x) {
  for (long long i = 0; i <= k - 1; i++) {
    pad now = q.top();
    q.pop();
    if (now.nt > 1e9) {
      return true;
    }
    if (now.nt < i) {
      return false;
    }
    now.res -= (i - now.last) * now.per;
    now.res += x;
    if (now.res > 1e13) {
      now.nt = 1e10;
    }
    now.last = i;
    now.nt = now.res / now.per + i;
    q.push(now);
  }
  return true;
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i].res;
  }
  for (int i = 1; i <= n; i++) {
    cin >> a[i].per;
    a[i].last = 0;
    a[i].nt = a[i].res / a[i].per;
    p.push(a[i]);
  }
  long long l = 0, r = 1e12, ans = -1;
  while (l <= r) {
    q = p;
    long long mid = (l + r) / 2;
    if (check(mid)) {
      ans = mid;
      r = mid - 1;
    } else
      l = mid + 1;
  }
  cout << ans << endl;
}
