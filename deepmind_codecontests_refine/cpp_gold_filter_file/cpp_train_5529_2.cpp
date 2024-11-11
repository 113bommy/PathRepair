#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  if (a == 0LL) return b;
  if (b == 0LL) return a;
  return gcd(b, a % b);
}
struct point {
  int x, y, col, ind;
};
bool cw(const point &a, const point &b, const point &c) {
  return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x) < 0;
}
inline bool cmp(point &a, point &b) {
  if (a.x == b.x) return a.y <= b.y;
  return a.x < b.x;
}
vector<point> convexHull(vector<point> p) {
  int n = p.size();
  if (n <= 1) return p;
  int k = 0;
  sort(p.begin(), p.end(), cmp);
  vector<point> q(n * 2);
  for (int i = 0; i < n; q[k++] = p[i++])
    for (; k >= 2 && !cw(q[k - 2], q[k - 1], p[i]); --k)
      ;
  for (int i = n - 2, t = k; i >= 0; q[k++] = p[i--])
    for (; k > t && !cw(q[k - 2], q[k - 1], p[i]); --k)
      ;
  q.resize(k - 1 - (q[0].ind == q[1].ind));
  return q;
}
const int N = 1003;
int X[N], Y[N], colour[N];
vector<point> H;
int area_triangle(point A, point B, point C) {
  int ans = A.x * B.y + B.x * C.y + C.x * A.y;
  ans -= A.x * C.y + B.x * A.y + C.x * B.y;
  ans = abs(ans);
  return ans;
}
vector<point> divide_points(point X1, point X2, point X3, vector<point> v) {
  vector<point> ans;
  ans.clear();
  int A = area_triangle(X1, X2, X3);
  for (int i = 0; i < v.size(); i++) {
    if (v[i].ind == X1.ind) continue;
    if (v[i].ind == X2.ind) continue;
    if (v[i].ind == X3.ind) continue;
    if (area_triangle(X1, X2, v[i]) + area_triangle(X2, X3, v[i]) +
            area_triangle(X3, X1, v[i]) ==
        A)
      ans.push_back(v[i]);
  }
  return ans;
}
void solveTriangle(point X1, point X2, point Y, vector<point> v) {
  if (v.size() == 0) return;
  bool flag = false;
  int ind;
  for (int i = 0; i < v.size(); i++)
    if (v[i].col == Y.col) {
      ind = i;
      flag = true;
      break;
    }
  if (!flag) {
    for (int i = 0; i < v.size(); i++)
      cout << X1.ind << " " << v[i].ind << "\n";
    return;
  }
  cout << Y.ind << " " << v[ind].ind << "\n";
  vector<point> v1, v2, v3;
  v1 = divide_points(X1, X2, v[ind], v);
  v2 = divide_points(X1, Y, v[ind], v);
  v3 = divide_points(X2, Y, v[ind], v);
  solveTriangle(X1, X2, v[ind], v1);
  solveTriangle(Y, v[ind], X1, v2);
  solveTriangle(Y, v[ind], X2, v3);
  return;
}
vector<point> V, temp;
void solve() {
  H.clear();
  V.clear();
  int n;
  bool flag[] = {false, false};
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> X[i] >> Y[i] >> colour[i];
    flag[colour[i]] = true;
    H.push_back({X[i], Y[i], colour[i], i});
    V.push_back({X[i], Y[i], colour[i], i});
  }
  if (!flag[0] || !flag[1]) {
    cout << n - 1 << "\n";
    for (int i = 1; i < n; i++) cout << "0 " << i << "\n";
    return;
  }
  H = convexHull(H);
  int cnt = 0, pos = 0;
  H.push_back(H[0]);
  for (int i = 1; i < H.size(); i++)
    if (H[i].col != H[i - 1].col) {
      pos = i;
      cnt++;
    }
  if (cnt > 2) {
    cout << "Impossible\n";
    return;
  }
  cout << n - 2 << "\n";
  flag[0] = flag[1] = false;
  int fst[] = {-1, -1};
  int now;
  if (pos == H.size() - 1) pos = 0;
  H.pop_back();
  for (int i = pos; i < H.size(); i++) {
    now = H[i].col;
    if (!flag[now]) {
      flag[now] = true;
      fst[now] = i;
    }
  }
  for (int i = 0; i < pos; i++) {
    now = H[i].col;
    if (!flag[now]) {
      flag[now] = true;
      fst[now] = i;
    }
  }
  if (flag[0] & flag[1]) {
    vector<int> v1, v2;
    v1.clear();
    v2.clear();
    if (fst[1] < fst[0]) {
      for (int i = fst[0]; i < H.size(); i++) v1.push_back(i);
      for (int i = 0; i < fst[1]; i++) v1.push_back(i);
    } else {
      for (int i = fst[0]; i < fst[1]; i++) v1.push_back(i);
    }
    if (fst[0] < fst[1]) {
      for (int i = fst[1]; i < H.size(); i++) v2.push_back(i);
      for (int i = 0; i < fst[0]; i++) v2.push_back(i);
    } else {
      for (int i = fst[1]; i < fst[0]; i++) v2.push_back(i);
    }
    assert(v1.size() > 0);
    assert(v2.size() > 0);
    assert(v1.size() + v2.size() == H.size());
    for (int i = 1; i < v1.size(); i++)
      cout << H[v1[i - 1]].ind << " " << H[v1[i]].ind << "\n";
    for (int i = 1; i < v2.size(); i++)
      cout << H[v2[i - 1]].ind << " " << H[v2[i]].ind << "\n";
    for (int i = 1; i < v1.size(); i++) {
      temp = divide_points(H[v1[i - 1]], H[v1[i]], H[fst[1]], V);
      solveTriangle(H[v1[i - 1]], H[v1[i]], H[fst[1]], temp);
    }
    for (int i = 1; i < v2.size(); i++) {
      temp = divide_points(H[v2[i - 1]], H[v2[i]], H[fst[0]], V);
      solveTriangle(H[v2[i - 1]], H[v2[i]], H[fst[0]], temp);
    }
    return;
  }
  for (int i = 1; i < H.size(); i++)
    cout << H[i - 1].ind << " " << H[i].ind << "\n";
  now = -1;
  for (int i = 0; i < n; i++) {
    if (!flag[0] && colour[i] == 0) {
      now = i;
      break;
    }
    if (!flag[1] && colour[i] == 1) {
      now = i;
      break;
    }
  }
  assert(now != -1);
  H.push_back(H[0]);
  for (int i = 1; i < H.size(); i++) {
    temp.clear();
    temp = divide_points(H[i - 1], H[i], V[now], V);
    solveTriangle(H[i - 1], H[i], V[now], temp);
  }
  return;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  clock_t clk = clock();
  int t = 1;
  for (int tests = 1; tests <= t; tests++) {
    solve();
  }
  clk = clock() - clk;
  cerr << "Time Elapsed: " << fixed << setprecision(10)
       << ((long double)clk) / CLOCKS_PER_SEC << "\n";
  return 0;
}
