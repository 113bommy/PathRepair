#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 5;
const long long mod = 1e9 + 7;
int n, l;
long long x, m, a[MAXN];
struct Mat {
  long long cnt[105];
} mat, mat1, mat2, mat3;
Mat cal(Mat mt1, Mat mt2) {
  Mat ans;
  memset(ans.cnt, 0, sizeof(ans.cnt));
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < m; ++j) {
      ans.cnt[(i + j) % m] += mt1.cnt[i] * mt2.cnt[j];
      ans.cnt[(i + j) % m] %= mod;
    }
  }
  return ans;
}
Mat qpow(Mat mt, int t) {
  Mat ans = mt;
  while (t) {
    if (t & 1) ans = cal(ans, mt);
    t >>= 1;
    mt = cal(mt, mt);
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n >> l >> m;
  memset(a, 0, sizeof(a));
  memset(mat.cnt, 0, sizeof(mat.cnt));
  memset(mat1.cnt, 0, sizeof(mat1.cnt));
  memset(mat2.cnt, 0, sizeof(mat2.cnt));
  memset(mat3.cnt, 0, sizeof(mat3.cnt));
  for (int i = 1; i <= n; ++i) {
    cin >> x;
    mat1.cnt[x % m]++;
  }
  for (int i = 1; i <= n; ++i) {
    cin >> x;
    mat2.cnt[x % m]++;
    a[i] = x;
  }
  for (int i = 1; i <= n; ++i) {
    cin >> x;
    mat3.cnt[(x + a[i]) % m]++;
  }
  if (l <= 2)
    mat = cal(mat1, mat3);
  else {
    mat = qpow(mat2, l - 3);
    mat = cal(mat, mat1);
    mat = cal(mat, mat3);
  }
  long long ans = 0;
  for (int i = 0; i <= 100; ++i) {
    if (i % m == 0) {
      ans += mat.cnt[i];
      ans %= mod;
    }
  }
  cout << ans << endl;
  return 0;
}
