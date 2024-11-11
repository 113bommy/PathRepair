#include <bits/stdc++.h>
using namespace std;
int Set(int N, int pos) { return N = N | (1 << pos); }
int reset(int N, int pos) { return N = N & ~(1 << pos); }
bool check(int N, int pos) { return (bool)(N & (1 << pos)); }
void CI(int &_x) { scanf("%d", &_x); }
void CO(int &_x) { cout << _x; }
template <typename T>
void getarray(T a[], int n) {
  for (int i = 0; i < n; i++) cin >> a[i];
}
template <typename T>
void printarray(T a[], int n) {
  for (int i = 0; i < n - 1; i++) cout << a[i] << " ";
  cout << a[n - 1] << endl;
}
const double EPS = 1e-9;
const int INF = 0x7f7f7f7f;
int dr8[8] = {1, -1, 0, 0, 1, -1, -1, 1};
int dc8[8] = {0, 0, -1, 1, 1, 1, -1, -1};
int dr4[4] = {0, 0, 1, -1};
int dc4[4] = {-1, 1, 0, 0};
int kn8r[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int kn8c[8] = {2, 1, -1, -2, -2, -1, 1, 2};
double n, l, v1, v2, k;
bool possible(double t) {
  int group = (n + k - 1) / k;
  double dist = l;
  for (int i = 1; i <= group; i++) {
    if (dist > (t * v2)) return 0;
    double tt = (dist - (t * v1)) / (v2 - v1);
    double ex = (tt * (v2 - v1)) / (v1 + v2);
    dist -= (tt + ex) * v1;
    t -= (tt + ex);
  }
  return true;
}
int main() {
  cin >> n >> l >> v1 >> v2 >> k;
  int it = 200;
  double low = 0, hi = l / v1;
  double mid;
  while (it--) {
    mid = (low + hi) / 2.0;
    if (possible(mid))
      hi = mid;
    else
      low = mid;
  }
  printf("%0.7lf\n", low);
}
