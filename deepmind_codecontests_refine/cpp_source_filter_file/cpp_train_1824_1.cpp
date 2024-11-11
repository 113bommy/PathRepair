#include <bits/stdc++.h>
using namespace std;
struct point {
  long long x, y;
};
vector<point> v;
int n;
long long pre[2][500010];
long long det(point a, point b) { return (a.x * b.y - a.y * b.x); }
long long mod(long long x) {
  x %= 1000000007;
  if (x < 0) x += 1000000007;
  return x;
}
long long getArea(vector<point> v) {
  long long area = 0;
  for (int i = 0; i < v.size(); ++i) {
    area = area - det(v[i], v[0]) + det(v[i], v[(i + 1) % v.size()]) +
           det(v[(i + 1) % v.size()], v[0]);
  }
  return area;
}
long long pr(int l, int r, int ok) {
  if (l <= r) {
    if (l == 0) return pre[ok][r];
    return mod(pre[ok][r] - pre[ok][l - 1]);
  } else {
    return mod(pre[ok][n - 1] - pre[ok][l - 1] + pre[ok][r]);
  }
}
long long cnt(int l, int r) {
  if (l <= r)
    return r - l + 1;
  else
    return n - l + r + 1;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n;
  v.resize(n);
  for (int i = 0; i < n; ++i) {
    cin >> v[i].x >> v[i].y;
  }
  reverse(v.begin(), v.end());
  pre[1][0] = v[0].y;
  pre[0][0] = v[0].x;
  for (int i = 1; i < n; ++i) {
    pre[1][i] = mod(pre[1][i - 1] + v[i].y);
    pre[0][i] = mod(pre[0][i - 1] + v[i].x);
  }
  long long area = getArea(v);
  int i = 0, j = 1;
  long long cArea = 0, cSum = 0, ans = 0;
  while (i < n) {
    while (cArea < area * 0.5 || (cArea == area * 0.5 && i < j)) {
      int jj = (j + 1) % n;
      cArea = cArea - det(v[j], v[i]) + det(v[j], v[jj]) + det(v[jj], v[i]);
      cSum = mod(cSum + mod(cArea));
      j = jj;
    }
    int jj = j;
    j = (j - 1 + n) % n;
    cSum = mod(cSum - mod(cArea));
    cArea = cArea - det(v[j], v[jj]) - det(v[jj], v[i]) + det(v[j], v[i]);
    ans = mod(ans + cSum);
    int ii = (i + 1) % n;
    cArea = cArea - det(v[j], v[i]) - det(v[i], v[ii]) + det(v[j], v[ii]);
    cSum =
        mod(cSum - (mod(pr(ii, j, 0) * v[i].y) - mod(pr(ii, j, 1) * v[i].x)) -
            mod(cnt(ii, j) * det(v[i], v[ii])) +
            (mod(pr(ii, j, 0) * v[ii].y) - mod(pr(ii, j, 1) * v[ii].x)));
    ++i;
  }
  cout << mod(mod(area) * mod(1LL * n * (n - 3) / 2) - 2 * ans);
}
