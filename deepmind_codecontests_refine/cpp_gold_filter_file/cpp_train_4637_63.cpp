#include <bits/stdc++.h>
#pragma GCC optimize(2)
namespace ucp {
template <typename T>
void Min(T &a, T b) {
  if (a > b) a = b;
}
template <typename T>
void Max(T &a, T b) {
  if (a < b) a = b;
}
inline int read() {
  int sign, data = 0;
  char ch = 0;
  while ((ch != '-') && ch < '0' || ch > '9') ch = getchar();
  if (ch == '-') {
    sign = -1;
    ch = getchar();
  } else
    sign = 1;
  while (ch >= '0' && ch <= '9') {
    data = data * 10 + ch - '0';
    ch = getchar();
  }
  return data * sign;
}
inline void print(int x) {
  if (x / 10) print(x / 10);
  putchar(x % 10 + '0');
}
}  // namespace ucp
using namespace std;
using namespace ucp;
const int mxint = 0x3f3f3f3f;
const long long mxll = 1e16;
const int lim = 5e5 + 10;
const int maxn = 10000 + 10;
const int maxm = 5e4 + 10;
const int N = 3e4 + 1000;
const long long mod = 1e9 + 7;
const double mxdb = 1e18;
const double eps = 1e-11;
struct node {
  double x, y, z;
  node() {}
  node(double x, double y, double z) : x(x), y(y), z(z) {}
  friend bool operator==(const node &a, const node &b) {
    return ((fabs(a.x - b.x) <= eps) && (fabs(a.y - b.y) <= eps) &&
            (fabs(a.z - b.z) <= eps));
  }
  friend node operator-(const node &a, const node &b) {
    node res;
    res.x = a.x - b.x;
    res.y = a.y - b.y;
    res.z = a.z - b.z;
    return res;
  }
  double lenth() { return sqrt(x * x + y * y + z * z); }
} point[maxn];
int n;
node pd;
node ans1;
double ans2;
double vc, vd;
double dis(node &a, node &b) {
  return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y) +
              (a.z - b.z) * (a.z - b.z));
}
vector<double> ve, cost;
bool check(double t) {
  int id = lower_bound(cost.begin(), cost.end(), t) - cost.begin();
  double tleft = t - cost[id - 1];
  node vv = point[id] - point[id - 1];
  double lenth = vv.lenth();
  node now;
  now.x = vc * tleft * vv.x / (lenth) + point[id - 1].x;
  now.y = vc * tleft * vv.y / (lenth) + point[id - 1].y;
  now.z = vc * tleft * vv.z / (lenth) + point[id - 1].z;
  double dist = dis(now, pd);
  double td = dist / vd;
  if (td - t > eps * 2) return false;
  if (t < ans2) {
    ans1 = now;
    ans2 = t + eps;
  }
  return true;
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i <= n; ++i) {
    scanf("%lf%lf%lf", &point[i].x, &point[i].y, &point[i].z);
  }
  scanf("%lf%lf", &vd, &vc);
  scanf("%lf%lf%lf", &pd.x, &pd.y, &pd.z);
  double sum = 0;
  ve.clear();
  cost.clear();
  cost.push_back(0.0);
  for (int i = 0; i < n; ++i) {
    ve.push_back(dis(point[i], point[i + 1]));
    sum = sum + ve[i];
    cost.push_back(ve[i] / vc);
  }
  for (int i = 1; i <= n; ++i) {
    cost[i] += cost[i - 1];
  }
  double l = 0, r = cost[n];
  ans2 = r + 1;
  while ((r - l) >= eps) {
    double mid = (l + r) / 2;
    if (check(mid))
      r = mid;
    else
      l = mid;
  }
  if (fabs(ans2 - (r + 1)) <= eps) {
    puts("NO");
  } else {
    puts("YES");
    printf("%.8lf\n", ans2);
    printf("%.8lf %.8lf %.8lf ", ans1.x, ans1.y, ans1.z);
  }
  return 0;
}
