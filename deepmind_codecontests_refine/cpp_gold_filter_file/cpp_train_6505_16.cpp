#include <bits/stdc++.h>
using namespace std;
long long n, m;
long long a[100005];
long long b[100005];
bool check(long long ans) {
  for (long long i = 1; i <= n; i++) b[i] = a[i];
  long long last = n;
  for (long long i = 1; i <= m; i++) {
    long long ret = ans;
    long long j;
    for (j = last; j > 0; j--) {
      if (b[j] != 0) break;
    }
    if (j == 0) {
      return true;
    }
    ret -= j;
    if (ret <= 0) return false;
    long long x = min(ret, b[j]);
    ret -= x;
    b[j] -= x;
    last = j;
    if (ret > 0) {
      while (ret > 0) {
        for (; j > 0; j--) {
          if (b[j] != 0) break;
        }
        if (j == 0) {
          return true;
        }
        last = j;
        x = min(ret, b[j]);
        ret -= x;
        b[j] -= x;
      }
    }
  }
  for (long long i = 1; i <= n; i++) {
    if (b[i] != 0) return false;
  }
  return true;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> m;
  for (long long i = 1; i <= n; i++) {
    cin >> a[i];
  }
  long long hi = (long long)1e15;
  long long lo = 0;
  while (hi > lo) {
    long long mid = lo + (hi - lo) / 2;
    if (check(mid))
      hi = mid;
    else
      lo = mid + 1;
  }
  cout << hi << endl;
  return 0;
}
