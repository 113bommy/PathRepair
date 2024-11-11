#include <bits/stdc++.h>
using namespace std;
const int oo = 0x7fffffff;
const long long OO = 1000000000000000000LL;
const int base = 1000000007;
const int dx[] = {1, 0, 0, -1};
const int dy[] = {0, 1, -1, 0};
const float eps = 1e-9;
int n, m, a[55], b[55];
double ans;
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) cin >> a[i] >> b[i];
  for (int i = 2; i <= n; ++i)
    ans += sqrt(((a[i] - a[i - 1]) * (a[i] - a[i - 1])) +
                ((b[i] - b[i - 1]) * (b[i] - b[i - 1])));
  ans *= m;
  printf("%.10lf", ans / 50);
}
