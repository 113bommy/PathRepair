#include <bits/stdc++.h>
using namespace std;
struct BIT {
  int size;
  vector<long long> bit;
  BIT() { size = 0; }
  BIT(int s) {
    size = s;
    bit.resize(size + 1);
    init();
  }
  void init() {
    for (int i = 1; i <= size; i++) bit[i] = 0;
  }
  long long query(int i) {
    long long ret = 0;
    while (i > 0) {
      ret += bit[i];
      i -= i & (-i);
    }
    return ret;
  }
  void add(int i, long long x) {
    while (i <= size) {
      bit[i] += x;
      i += i & (-i);
    }
  }
};
long long n, p;
long long a[100005];
long long cnt[300005], *pt;
vector<long long> ans;
BIT bit(100005);
bool check(long long x) {
  for (int i = 1; i <= n; i++) {
    if (a[i] > x + i - 1) return false;
  }
  return true;
}
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> p;
  for (int i = 1; i <= n; i++) cin >> a[i];
  sort(a + 1, a + n + 1);
  pt = cnt + 150005;
  long long ub = a[n], lb = 1, mid;
  while (ub - lb > 1) {
    mid = (ub + lb) / 2;
    if (check(mid))
      ub = mid;
    else
      lb = mid;
  }
  long long x = ub;
  for (int i = n; i >= 1; i--) {
    long long num = min(n, x + (n - 1) - a[i] + 1) - (n - i);
    bit.add(i, num), bit.add(i + 1, -num);
    pt[num]++;
  }
  if (pt[p] == 0) ans.push_back(x);
  long long pos = 0;
  while (pos < n && bit.query(pos + 1) == pos + 1) {
    pos++;
    pt[pos]--;
  }
  for (int i = 1; i <= n && pos < p; i++) {
    bit.add(pos + 1, 1);
    pt--;
    while (pos < n && bit.query(pos + 1) == pos + 1) {
      pos++;
      pt[pos]--;
    }
    if (pos < p && pt[p] == 0) ans.push_back(x + i);
  }
  cout << ans.size() << endl;
  for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
  cout << endl;
  return 0;
}
