#include <bits/stdc++.h>
using namespace std;
const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, 1, 0, -1};
const int dl[] = {0, 0, 0, -1};
const int dr[] = {0, 0, -1, 0};
long long Inverse(long long a, long long MOD) {
  long long m = a, n = MOD;
  long long xm = 1, xn = 0;
  while (n != 0) {
    long long q = m / n;
    long long r = m - q * n;
    long long xr = xm - q * xn;
    m = n;
    xm = xn;
    n = r;
    xn = xr;
  }
  return (xm % MOD + MOD) % MOD;
}
int lg(long long x) {
  int res = 0;
  for (int i = 0; i < x; i++) {
    long long GT = (1ll << i);
    if (GT <= x) {
      res = i;
    } else {
      return res;
    }
  }
  return res;
}
long long GCD(long long a, long long b) {
  if (b == 0) {
    return abs(a);
  }
  return GCD(b, a % b);
}
long long sqr(long long x) { return x * x; }
long long nhan(long long a, long long b, long long module) {
  a %= module;
  b %= module;
  long long q = (long double)a * b / module;
  long long r = (a * b - q * module) % module;
  if (r < 0) {
    r += module;
  }
  return r;
}
long long MU(long long a, long long n, long long module) {
  long long res = 1;
  for (; n; n = n >> 1, a = nhan(a, a, module)) {
    if (n & 1) {
      res = nhan(res, a, module);
    }
  }
  return res;
}
void hamZ(string S, int z[]) {
  int n = S.size();
  for (int i = 0; i <= n + 1; i++) {
    z[i] = 0;
  }
  int L = 1, R = 1;
  for (int i = 2; i <= n; i++) {
    if (i <= R) {
      z[i] = min(z[i - L + 1], R - i + 1);
    }
    while (i + z[i] <= n && S[z[i]] == S[i + z[i] - 1]) {
      z[i]++;
    }
    if (i + z[i] - 1 > R) {
      R = i + z[i] - 1;
      L = i;
    }
  }
}
void Sang(int N, vector<int> Uoc[]) {
  for (int i = 1; i <= N; i++) {
    for (int j = i; j <= N; j += i) Uoc[j].push_back(i);
  }
}
struct Point {
  int x, y;
  Point(){};
  Point(int a, int b) {
    x = a;
    y = b;
  }
};
void Tru(Point &A, Point B) {
  A.x -= B.x;
  A.y -= B.y;
}
bool CungChieu(Point O, Point A, Point B) {
  Tru(A, O);
  Tru(B, O);
  return 1ll * A.x * B.y < 1ll * A.y * B.x;
}
bool ThangHang(Point O, Point A, Point B) {
  Tru(A, O);
  Tru(B, O);
  return 1ll * A.x * B.y == 1ll * A.y * B.x;
}
bool NguocChieu(Point O, Point A, Point B) {
  Tru(A, O);
  Tru(B, O);
  return 1ll * A.x * B.y > 1ll * A.y * B.x;
}
mt19937 rnd(chrono::system_clock::now().time_since_epoch().count());
const int N = 5200 + 5;
const double sodu = 1e-9;
const long long oo = 1e18;
const int module = 1e9 + 7;
const int M = 1e9 + 7;
const int NN = (1 << 16);
void nhap() {}
void solve() {
  int n;
  cin >> n;
  int L = 0;
  int R = 1e9;
  int MaxValue = -1;
  while (L <= R) {
    int mid = (L + R) >> 1;
    cout << "> " << mid << '\n';
    fflush(stdout);
    int r;
    cin >> r;
    if (r == 1) {
      MaxValue = mid;
      L = mid + 1;
    } else
      R = mid - 1;
  }
  MaxValue++;
  vector<int> B(30);
  for (int i = 0; i < 30; i++) {
    cout << "? " << rnd() % n + 1 << '\n';
    fflush(stdout);
    cin >> B[i];
  }
  sort(B.begin(), B.end());
  B.push_back(MaxValue);
  int Res = 0;
  for (int i = 0; i < 30; i++) Res = GCD(Res, B[i + 1] - B[i]);
  cout << "! " << MaxValue - (n - 1) * Res << " " << Res << '\n';
  fflush(stdout);
  return;
}
int main() {
  ios_base::sync_with_stdio(1);
  cin.tie(nullptr);
  cout.tie(nullptr);
  nhap();
  solve();
}
