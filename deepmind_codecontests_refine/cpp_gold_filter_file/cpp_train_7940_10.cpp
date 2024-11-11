#include <bits/stdc++.h>
using namespace std;
long long int mod = 1000000007;
long long int INF = 1e9;
long long int po(long long int a, long long int b) {
  long long int re = 1;
  while (b) {
    if (b % 2 == 1) {
      re = (re * a);
      re %= mod;
    }
    a = (a * a);
    a %= mod;
    b >>= 1;
  }
  return re;
}
long long int t[4000000];
map<long long int, int> m;
void update(int v, int tl, int tr, int p, int val) {
  if (tl == tr) {
    t[v] = val;
    return;
  }
  int tm = (tl + tr) / 2;
  if (p > tm) {
    update(2 * v + 1, tm + 1, tr, p, val);
  } else {
    update(2 * v, tl, tm, p, val);
  }
  t[v] = max(t[2 * v], t[2 * v + 1]);
  return;
}
long long int ma(int v, int tl, int tr, int l, int r) {
  if (l > r) {
    return -INF;
  }
  if (tl == l && tr == r) {
    return t[v];
  }
  int tm = (tl + tr) / 2;
  return max(ma(2 * v, tl, tm, l, min(tm, r)),
             ma(2 * v + 1, tm + 1, tr, max(l, tm + 1), r));
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int test = 1;
  while (test--) {
    int n, k;
    cin >> n >> k;
    long long int a[n];
    for (long long int i = (0); i < (1000000); i++) {
      t[i] = -INF;
    }
    vector<long long int> d;
    for (long long int i = (0); i < (n); i++) {
      cin >> a[i];
      a[i] -= i;
      if (m[a[i]] == 0) {
        d.push_back(a[i]);
        m[a[i]] = 1;
      }
    }
    sort(d.begin(), d.end());
    d.push_back(-INF);
    int s = d.size();
    for (long long int i = (0); i < (s); i++) {
      m[d[i]] = i;
    }
    int b[k];
    for (long long int i = (0); i < (k); i++) {
      cin >> b[i];
    }
    for (long long int i = (1); i < (k); i++) {
      if (a[b[i] - 1] < a[b[i - 1] - 1]) {
        cout << -1;
        return 0;
      }
    }
    update(1, 0, s - 1, 0, 0);
    int j = 0, o = 0, f = 0;
    if (k > 0 && b[0] == 1) {
      update(1, 0, s - 1, 0, -INF);
      update(1, 0, s - 1, m[a[0]], 1);
      j = f = 1;
    }
    long long int q;
    for (long long int i = (f); i < (n); i++) {
      q = ma(1, 0, s - 1, 0, m[a[i]]);
      if (j < k && b[j] == (i + 1)) {
        update(1, 0, s - 1, 0, -INF);
        while (o < i) {
          update(1, 0, s - 1, m[a[o]], -INF);
          o++;
        }
        j++;
      }
      update(1, 0, s - 1, m[a[i]], q + 1);
    }
    q = ma(1, 0, s - 1, 0, s - 1);
    if (q < 0) {
      cout << -1;
    } else {
      cout << n - q;
    }
  }
  return 0;
}
