#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
const double PI = 3.14159265358979323846;
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
int x[1001], y[1001];
long long r[1001];
bool inside(int i, int j) {
  if (r[j] >= r[i]) return 0;
  long long d = (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
  long long d2 = (r[i] - r[j]) * (r[i] - r[j]);
  if (d <= d2) return 1;
  return 0;
}
int sum[1001];
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> y[i] >> r[i];
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (inside(i, j)) sum[j]++;
    }
  }
  long long sol = 0;
  for (int i = 0; i < n; i++) {
    if (sum[i] == 0 || sum[i] % 2 == 1)
      sol += (r[i]) * (r[i]);
    else
      sol -= (r[i]) * (r[i]);
  }
  printf("%.8lf\n", double(sol) * acos(-1));
  return 0;
}
