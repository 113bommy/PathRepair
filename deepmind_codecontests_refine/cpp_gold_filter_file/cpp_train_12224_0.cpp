#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-9;
const int MOD = 1000000007;
int n, pot[1000100];
pair<double, double> a[1010];
bool cmp(const pair<double, double> &A, const pair<double, double> &B) {
  if (abs(A.first - B.first) > eps) return A.first < B.first;
  if (abs(A.second - B.second) > eps) return A.second < B.second;
  return 0;
}
struct seg {
  double x, y, ang;
  seg() {}
  seg(pair<double, double> A, pair<double, double> B) {
    x = A.first + B.first;
    y = A.second + B.second;
    ang = atan2(A.second - B.second, A.first - B.first);
  }
  seg(double ang) : ang(ang) {}
  bool operator<(const seg &A) const {
    if (abs(x - A.x) > eps) return x < A.x;
    if (abs(y - A.y) > eps) return y < A.y;
    if (abs(ang - A.ang) > eps) return ang < A.ang;
    return 0;
  }
};
vector<seg> V;
vector<int> cnt;
int calc() {
  int ret = 1, sum = 0;
  for (int i = 0; i < (int)cnt.size(); ++i)
    ret = ((long long)ret * (cnt[i] + 1)) % MOD, sum += cnt[i];
  return (ret - 1 - sum + MOD) % MOD;
}
int main() {
  pot[0] = 1;
  for (int i = 1; i < 1000005; ++i) pot[i] = (long long)pot[i - 1] * 2 % MOD;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    int A, B, C, D;
    scanf("%d%d%d%d", &A, &B, &C, &D);
    double x = (double)A / B, y = (double)C / D;
    double X = x / (x * x + y * y), Y = y / (x * x + y * y);
    a[i] = pair<double, double>(X, Y);
  }
  sort(a, a + n, cmp);
  for (int i = 0; i < n; ++i)
    for (int j = i + 1; j < n; ++j) {
      V.push_back(seg(a[i], a[j]));
    }
  sort(V.begin(), V.end());
  V.push_back(seg(-100));
  int ans = 0;
  cnt.push_back(1);
  for (int i = 1; i < (int)V.size(); ++i) {
    if (abs(V[i].x - V[i - 1].x) > eps || abs(V[i].y - V[i - 1].y) > eps) {
      ans = (ans + calc()) % MOD;
      cnt.clear();
      cnt.push_back(1);
    } else if (abs(V[i].ang - V[i - 1].ang) > eps)
      cnt.push_back(1);
    else
      ++cnt.back();
  }
  printf("%d\n", ans);
  return 0;
}
