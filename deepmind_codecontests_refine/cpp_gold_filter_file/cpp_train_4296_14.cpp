#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
const int ha = 998244353;
int ok(int n, int k) {
  if (n == 9 && k == 2) return 0;
  if (~n & 1 || k < 0) return 0;
  if (n > 1 && (n - 3) / 2 < k) return 0;
  if (k == 0) return !(n & (n + 1));
  if (k == 1) return n & (n + 1);
  return 1;
}
int cnt = 0;
void work(int n, int k, int fa) {
  printf("%d ", fa);
  int now = ++cnt;
  for (int i = 0; (i << 1 | 1) < n; ++i) {
    int lsz = i << 1 | 1, rsz = n - lsz - 1;
    int z = (min(lsz, rsz) << 1 <= max(lsz, rsz));
    if (ok(lsz, 0) && ok(rsz, k - z)) {
      work(lsz, 0, now);
      work(rsz, k - z, now);
      return;
    }
  }
}
int main() {
  int n, k;
  std::ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> k;
  if (!ok(n, k))
    cout << "NO";
  else {
    cout << "YES" << endl;
    work(n, k, 0);
  }
}
