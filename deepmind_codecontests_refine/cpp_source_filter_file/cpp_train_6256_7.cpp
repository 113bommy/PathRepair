#include <bits/stdc++.h>
using namespace std;
int tree[2000005], a[100005];
long long merge(long long x, long long y) { return min(x, y); }
void build(int node, int low, int high, int b[]) {
  if (low == high) {
    tree[node] = b[low];
    return;
  }
  int mid = (low + high) / 2;
  build(2 * node, low, mid, b);
  build(2 * node + 1, mid + 1, high, b);
  tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
}
long long query(int node, int low, int high, int l, int r) {
  if (low > r || high < l) return 1e9;
  if (l <= low && high <= r) return tree[node];
  int mid = (low + high) / 2;
  long long p1 = query(2 * node, low, mid, l, r);
  long long p2 = query(2 * node + 1, mid + 1, high, l, r);
  return merge(p1, p2);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int TESTS = 1;
  while (TESTS--) {
    long long n, q;
    cin >> n >> q;
    for (long long int i = 0; i < n; i++) cin >> a[i];
    for (long long int i = 0; i < n; i++) {
      if (a[i] > q) {
        cout << "NO";
        return 0;
      }
    }
    long long is = 0;
    long long idx = 0;
    while (idx < n && a[idx] == 0) {
      idx++;
    }
    if (idx >= n) {
      cout << "YES\n";
      for (long long int i = 0; i < n; i++) cout << q << " ";
      return 0;
    }
    for (long long int i = 0; i < n; i++) {
      if (a[i] == q) is = 1;
    }
    long long l = 0;
    if (is == 0) {
      if (a[0] == 0) {
        a[0] = q;
        is = 1;
        l = 1;
      }
      if (a[n - 1] == 0 && is == 0) {
        a[n - 1] = q;
        is = 1;
      }
    }
    std::vector<pair<pair<long long int, long long int>, long long> > qry;
    for (long long int i = l; i < idx; i++) a[i] = a[idx];
    long long curr = a[0];
    vector<long long int> fl(q + 1, 0);
    fl[curr] = 1;
    for (long long int i = 1; i < n; i++) {
      if (a[i] == 0 && is == 0) {
        a[i] = q;
        is = 1;
        break;
      }
    }
    vector<long long int> fi(q + 1, -1), si(q + 1, -1);
    curr = a[0];
    fl[curr] = 1;
    for (long long int i = 1; i < n; i++) {
      if (a[i] == 0) {
        a[i] = curr;
      } else if (a[i] != curr) {
        curr = a[i];
        fl[curr] = 1;
      }
    }
    curr = a[0];
    fi[curr] = 0;
    si[curr] = 0;
    fl[curr] = 1;
    for (long long int i = 1; i < n; i++) {
      si[a[i]] = i;
      if (fi[a[i]] == -1) fi[a[i]] = i;
    }
    if (is == 0) {
      cout << "NO";
      return 0;
    }
    build(1, 0, n - 1, a);
    for (long long int i = 1; i < q + 1; i++) {
      if (fl[i] == 0) continue;
      if (i > query(1, 0, n - 1, fi[i], si[i])) {
        cout << "NO";
        return 0;
      }
    }
    cout << "YES\n";
    for (long long int i = 0; i < n; i++) cout << a[i] << " ";
  }
  return 0;
}
