#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
clock_t time_p = clock();
void rtime() {
  time_p = clock() - time_p;
  cerr << "Time Taken : " << (float)(time_p) / CLOCKS_PER_SEC << "\n";
}
long long power(long long a, long long b, long long m = mod) {
  long long ans = 1;
  a = a % m;
  while (b > 0) {
    if (b & 1) ans = (1ll * a * ans) % m;
    b >>= 1;
    a = (1ll * a * a) % m;
  }
  return ans;
}
long long rr[] = {0, 1, 1, 1, 0, -1, -1, -1};
long long cc[] = {1, 1, 0, -1, -1, -1, 0, 1};
const long long N = 1000500;
long long tree[4 * N], a[N], b[N], posa[N], posb[N], len[N];
bool lazy[4 * N];
void update(long long i, long long s, long long e, long long l, long long r,
            long long val) {
  if (l <= s && e <= r) {
    tree[i] = val;
    lazy[i] = true;
    return;
  }
  if (lazy[i]) {
    tree[2 * i + 1] = tree[2 * i + 2] = tree[i];
    lazy[2 * i + 1] = lazy[2 * i + 2] = true;
    lazy[i] = false;
  }
  long long m = s + e >> 1;
  if (l <= m) update(2 * i + 1, s, m, l, r, val);
  if (r > m) update(2 * i + 2, m + 1, e, l, r, val);
}
long long find(long long i, long long s, long long e, long long l) {
  if (s == e && s == l) {
    return tree[i];
  }
  if (lazy[i]) {
    tree[2 * i + 1] = tree[2 * i + 2] = tree[i];
    tree[i] = 0;
    lazy[2 * i + 1] = lazy[2 * i + 2] = true;
    lazy[i] = false;
  }
  long long m = s + e >> 1;
  if (l <= m) return find(2 * i + 1, s, m, l);
  return find(2 * i + 2, m + 1, e, l);
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long t = 1;
  while (t--) {
    long long n, m;
    cin >> n >> m;
    for (long long i = 0; i < n; i++) {
      cin >> a[i];
    }
    for (long long i = 0; i < n; i++) {
      cin >> b[i];
    }
    for (long long i = 1; i <= m; i++) {
      long long type;
      cin >> type;
      if (type == 1) {
        cin >> posa[i] >> posb[i] >> len[i];
        update(0, 0, n - 1, posb[i] - 1, posb[i] + len[i] - 1, i);
      } else {
        long long x;
        cin >> x;
        long long ans = find(0, 0, n - 1, x - 1);
        if (!ans)
          cout << b[x - 1];
        else
          cout << a[x - posb[ans] + posa[ans] - 1];
        cout << "\n";
      }
    }
  }
  rtime();
  return 0;
}
