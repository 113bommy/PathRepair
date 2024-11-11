#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 100;
int a[maxn];
int ans[maxn];
int val[4 * maxn];
int fac1[maxn];
int fac2[maxn];
vector<int> hel;
void add(int id, int L, int R, int idx) {
  val[id]++;
  if (L + 1 == R) return;
  int mid = (L + R) >> 1;
  if (idx < mid)
    add(id * 2 + 0, L, mid, idx);
  else
    add(id * 2 + 1, mid, R, idx);
}
int get(int id, int L, int R, int l, int r) {
  if (L == l && r == R) return val[id];
  int mid = (L + R) >> 1;
  int ret = 0;
  if (l < mid) ret += get(id * 2 + 0, L, mid, l, min(r, mid));
  if (r > mid) ret += get(id * 2 + 1, mid, R, max(l, mid), r);
  return ret;
}
void debug(int n) {
  cout << endl;
  for (int i = 0; i < n; i++) cout << fac1[i] << " ";
  cout << endl;
  for (int i = 0; i < n; i++) cout << fac2[i] << " ";
  cout << endl;
  for (int i = 0; i < n; i++) cout << ans[i] << " ";
}
int main() {
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  for (int i = n - 1; i >= 0; i--) {
    int t;
    cin >> t;
    add(1, 0, n, t);
    fac1[i] = t - get(1, 0, n, 0, t);
  }
  fill(val, val + 4 * maxn - 10, 0);
  for (int i = n - 1; i >= 0; i--) {
    int t;
    cin >> t;
    add(1, 0, n, t);
    fac2[i] = t - get(1, 0, n, 0, t);
  }
  for (int i = n - 1; i >= 0; i--) ans[i] = fac1[i] + fac2[i];
  for (int i = 0; i < n; i++) {
    ans[i + 1] += ans[i] / (i + 1);
    ans[i] = ans[i] % (i + 1);
  }
  fill(val, val + maxn - 10, 0);
  for (int i = n - 1; i >= 0; i--) {
    int t = ans[i];
    int low = 0, hig = n;
    while (low + 1 != hig) {
      int mid = (low + hig) >> 1;
      int k = t + get(1, 0, n, 0, mid);
      if (k >= mid)
        low = mid;
      else
        hig = mid;
    }
    add(1, 0, n, low);
    hel.push_back(low);
  }
  for (int i = 0; i < hel.size(); i++) cout << hel[i] << " ";
  return 0;
}
