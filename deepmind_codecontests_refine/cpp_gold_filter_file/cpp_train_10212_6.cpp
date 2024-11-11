#include <bits/stdc++.h>
using namespace std;
int n, m, a[200010];
struct fenwick {
  vector<int> F;
  int N;
  void init(int n) {
    N = n;
    F.clear();
    F.resize(N + 1);
  }
  void add(int k, int v) {
    if (k == 0) return;
    while (k <= N) {
      F[k] += v;
      k += k & -k;
    }
  }
  int sum(int k) {
    int s = 0;
    while (k >= 1) {
      s += F[k];
      k -= k & -k;
    }
    return s;
  }
} f;
long long calc(int k) {
  int h = 0, l = 0;
  f.init(200010 * 2);
  for (int i = 0; i < n; ++i) {
    l += a[i] < k;
    h += a[i] >= k;
    f.add(h - l + 200010, 1);
  }
  long long ret = 0;
  int cur = 0;
  h = l = 0;
  for (int i = 0; i < n; ++i) {
    ret += f.sum(2 * 200010) - f.sum(cur + 200010);
    l += a[i] < k;
    h += a[i] >= k;
    f.add(h - l + 200010, -1);
    cur += (a[i] >= k) - (a[i] < k);
  }
  assert(f.sum(2 * 200010) == 0);
  return ret;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  cout << calc(m) - calc(m + 1) << endl;
  return 0;
}
