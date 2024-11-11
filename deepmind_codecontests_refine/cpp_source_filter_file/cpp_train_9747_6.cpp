#include <bits/stdc++.h>
const long long INF = 1e9 + 1;
const double EPS = 1e-10;
const long long P = 1e9 + 7;
const long long Q = 47;
using namespace std;
void hello() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
void show(vector<long long>& arr) {
  for (auto i : arr) cout << i << " ";
  cout << "\n";
}
void show(vector<vector<long long>>& arr) {
  for (auto i : arr) show(i);
  cout << "\n";
}
struct pt {
  long long x, y;
  pt() {}
  pt(long long tx, long long ty) {
    x = tx;
    y = ty;
  }
  pt operator+(pt t) { return {x + t.x, y + t.y}; }
  pt operator-(pt t) { return {x - t.x, y - t.y}; }
  long long operator%(pt t) { return x * t.x + y * t.y; }
  long long operator*(pt t) { return x * t.y - y * t.x; }
  long long len() { return x * x + y * y; }
};
long long find_min(vector<pt>& matr) {
  long long res = 0;
  for (long long i = 1; i < matr.size(); ++i)
    if (matr[res].x > matr[i].x ||
        matr[res].x == matr[i].x && matr[res].y < matr[i].y)
      res = i;
  return res;
}
bool cmp(pt l, pt r) { return l * r > 0 || l * r == 0 && l.len() < r.len(); }
vector<pt> minc_sum(vector<pt> left, vector<pt> right) {
  long long indl = find_min(left);
  long long indr = find_min(right);
  vector<pt> res;
  res.push_back(left[indl] + right[indr]);
  long long ptl = indl;
  long long ptr = indr;
  do {
    if (cmp(left[(indl + 1) % left.size()] - left[indl],
            right[(indr + 1) % right.size()] - right[indr]))
      ++indl;
    else
      ++indr;
    indl %= left.size();
    indr %= right.size();
    res.push_back(left[indl] + right[indr]);
  } while (ptl != indl || ptr != indr);
  res.pop_back();
  return res;
}
long long sign(long long a) {
  if (!a) return 0;
  return a / abs(a);
}
bool inangle(pt o, pt a, pt b, pt x) {
  if (sign((a - o) * (x - o)) && sign((b - o) * (x - o)))
    return sign((a - o) * (x - o)) == sign((x - o) * (b - o)) &&
           sign((a - o) * (x - o)) == sign((a - o) * (b - o));
  if (!sign((a - o) * (x - o))) return (a - o) % (x - o) >= 0;
  return (b - o) % (x - o) >= 0;
}
bool intrg(pt a, pt b, pt c, pt x) {
  return inangle(a, b, c, x) && inangle(b, a, c, x);
}
signed main() {
  hello();
  long long n, m, k;
  cin >> n;
  vector<pt> v1(n);
  for (long long i = 0; i < n; ++i) cin >> v1[i].x >> v1[i].y;
  cin >> m;
  vector<pt> v2(m);
  for (long long i = 0; i < m; ++i) cin >> v2[i].x >> v2[i].y;
  cin >> k;
  vector<pt> v3(k);
  for (long long i = 0; i < k; ++i) cin >> v3[i].x >> v3[i].y;
  vector<pt> matr = minc_sum(v1, v2);
  matr = minc_sum(matr, v3);
  pt dt = matr[find_min(matr)];
  for (auto& val : matr) val = val - dt;
  sort(matr.begin(), matr.end(), cmp);
  long long q;
  cin >> q;
  for (long long v = 0; v < q; ++v) {
    pt check;
    cin >> check.x >> check.y;
    check.x *= 3;
    check.y *= 3;
    if (check.x < dt.x || check.x == dt.x && check.y < dt.y) {
      cout << "NO"
           << "\n";
      continue;
    }
    if (check.x == dt.x && check.y == dt.y) {
      cout << "YES"
           << "\n";
      continue;
    }
    check = check - dt;
    long long ind =
        lower_bound(matr.begin(), matr.end(), check, cmp) - matr.begin();
    if (ind == matr.size()) {
      cout << "NO"
           << "\n";
      continue;
    }
    if (intrg(matr[0], matr[ind], matr[ind - 1], check))
      cout << "YES"
           << "\n";
    else
      cout << "NO"
           << "\n";
  }
}
