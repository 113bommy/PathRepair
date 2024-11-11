#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e16 + 47;
long long n, circ = 0;
string st;
vector<long long> pref;
long long get(char c) {
  if (c == '(') return 1;
  return -1;
}
void read() {
  cin >> n >> st;
  pref.resize(n, 0);
  long long bl = 0, mn = 0;
  for (long long i = 0; i < n; i++) {
    bl += get(st[i]);
    pref[i] = bl;
    mn = min(mn, bl);
  }
  if (bl != 0) {
    cout << 0 << " " << 1 << " " << 1 << "\n";
    exit(0);
  }
  for (long long i = 0; i < n; i++) {
    if (pref[i] == mn) {
      circ = i;
      break;
    }
  }
  bl = 0;
  for (long long i = 0; i < n; i++) {
    bl += get(st[(i + circ + 1) % n]);
    pref[i] = bl;
  }
}
void solve() {
  long long ans = 0;
  for (long long i = 0; i < n; i++)
    if (pref[i] == 0) ans++;
  long long pr = 0, one = 0, zero = ans;
  long long l = 0, r = n - 1;
  for (long long i = 1; i < n; i++) {
    if (st[(i + circ + 1) % n] == '(') {
      r = i;
      break;
    }
  }
  for (long long i = 1; i < n; i++) {
    if (pref[i] == 1 && st[(i + circ + 1) % n] == ')') one++;
    if (pref[i] != 0) continue;
    if (one + 1 > ans) {
      l = pr, r = i;
      ans = one + 1;
    }
    long long kek = pr, cnt = 0;
    for (long long k = pr + 1; k < i; k++) {
      if (pref[k] == 2 && st[(k + circ + 1) % n] == '(') kek = k, cnt = 0;
      if (pref[k] == 3 && st[(k + circ + 1) % n] == '(') cnt++;
      if (pref[k] == 1 && st[(k + circ + 1) % n] == ')') {
        if (ans < zero - 1 + 2 + cnt) {
          ans = zero + 1 + cnt;
          l = kek, r = k;
        }
        cnt = 0;
      }
    }
    pr = i + 1;
  }
  cout << ans << "\n";
  l = (circ + 1 + l) % n + 1, r = (circ + 1 + r) % n + 1;
  cout << l << " " << r << "\n";
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long t = 1;
  while (t--) {
    read();
    solve();
  }
}
