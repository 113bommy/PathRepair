#include <bits/stdc++.h>
#pragma warning(disable : 4101)
using namespace std;
const double pi = acos(-1.0);
const int INF = 1000000000;
const int MAX = 100007;
const int MAX2 = 2000000;
const int inf = (int)1e9 + 5;
const long long mod = 1e9 + 7;
const int BASE = 10;
const int ST = 1000003;
const int CNT = 100;
const double eps = 1e-6;
const long long base = 2204234849;
const long long l_inf = (long long)4e18;
const int logn = 30;
int main() {
  long long n, a, b, c, d, maxim1, maxim2;
  cin >> n >> a >> b >> c >> d;
  long long sum1 = a + b, sum2 = b + d, sum3 = c + a, sum4 = d + c;
  int minim = min(sum1, min(sum2, min(sum3, sum4)));
  int kol = 0;
  maxim1 = minim + n;
  int maxim = max(sum1, max(sum2, max(sum3, sum4)));
  if (maxim > maxim1) {
    cout << 0;
    return 0;
  }
  cout << n * (maxim1 - maxim);
  return 0;
}
