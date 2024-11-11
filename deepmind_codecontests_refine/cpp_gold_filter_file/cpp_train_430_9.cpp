#include <bits/stdc++.h>
using namespace std;
const int64_t INF = 4e18;
const int64_t MAXN = 1e6 + 10;
struct Seg {
  vector<int64_t> a;
  vector<int64_t> maxSuf;
  int64_t sz;
  vector<int64_t> r;
  Seg(vector<int64_t> ar) {
    for (sz = 1; sz < ar.size(); sz *= 2)
      ;
    a.resize(2 * sz, 0);
    maxSuf.resize(2 * sz, 0);
    r.resize(2 * sz, -1);
    for (int64_t i = 0; i < ar.size(); i++) {
      a[i + sz] = ar[i];
      maxSuf[i + sz] = a[i + sz];
    }
    for (int64_t i = 0; i < sz; i++) {
      r[i + sz] = i;
    }
    for (int64_t i = sz - 1; i > 0; i--) {
      a[i] = a[i * 2] + a[i * 2 + 1];
      r[i] = r[2 * i + 1];
      maxSuf[i] = max(maxSuf[i * 2] + a[i * 2 + 1], maxSuf[i * 2 + 1]);
    }
  }
  int64_t sum(int64_t l, int64_t r) {
    if (l > r) return 0;
    int64_t ans = 0;
    for (l += sz, r += sz; l <= r; l /= 2, r /= 2) {
      if (l % 2 == 1) ans += a[l++];
      if (r % 2 == 0) ans += a[r--];
      if (l >= r) break;
    }
    return ans;
  }
  void Change(int64_t dx, int64_t i) {
    i += sz;
    a[i] += dx;
    maxSuf[i] = a[i];
    for (i /= 2; i > 0; i /= 2) {
      a[i] = a[i * 2] + a[i * 2 + 1];
      maxSuf[i] = max(maxSuf[i * 2] + a[i * 2 + 1], maxSuf[i * 2 + 1]);
    }
  }
  int64_t q() {
    int64_t v = query(1);
    return v;
  }
  int64_t query(int64_t cur) {
    if (maxSuf[cur] + sum(r[cur] + 1, sz - 1) <= 0) return -1;
    if (cur >= sz) {
      if (sum(cur - sz, sz - 1) > 0) return cur - sz;
      return -1;
    }
    if (maxSuf[cur * 2 + 1] + sum(r[cur * 2 + 1] + 1, sz - 1) > 0)
      return query(cur * 2 + 1);
    return query(cur * 2);
  }
  void printTree() {
    int64_t t = 1;
    for (int64_t i = 1; i < sz * 2; i++) {
      if (t == i) {
        cout << endl;
        t *= 2;
      }
      cout << a[i] << " ";
    }
    cout << endl;
    t = 1;
    for (int64_t i = 1; i < sz * 2; i++) {
      if (t == i) {
        cout << endl;
        t *= 2;
      }
      cout << maxSuf[i] << " ";
    }
    cout << endl << endl;
  }
  void printPath(int64_t i) {
    cout << "PATH OF " << i << " : ";
    for (i += sz; i > 0; i /= 2) cout << a[i] << " ";
    cout << endl;
  }
};
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int64_t n, m;
  cin >> n >> m;
  vector<int64_t> cnt(MAXN, 0);
  vector<int64_t> a(n), b(m);
  for (int64_t i = 0; i < n; i++) {
    cin >> a[i];
    cnt[a[i]]++;
  }
  for (int64_t i = 0; i < m; i++) {
    cin >> b[i];
    cnt[b[i]]--;
  }
  Seg s(cnt);
  int64_t q;
  cin >> q;
  int64_t first, i;
  for (int64_t j = 0; j < q; j++) {
    cin >> first;
    if (first == 1) {
      cin >> i >> first;
      i--;
      s.Change(-1, a[i]);
      s.Change(1, first);
      a[i] = first;
    } else {
      cin >> i >> first;
      i--;
      s.Change(1, b[i]);
      s.Change(-1, first);
      b[i] = first;
    }
    cout << s.q() << endl;
  }
  return 0;
}
