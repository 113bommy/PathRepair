#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5;
bool isp[maxn];
int p[maxn], len;
void init() {
  isp[0] = isp[1] = true;
  for (int i = 2; i < maxn; i++) {
    if (!isp[i]) p[++len] = i;
    for (int j = 1; j <= len && p[j] * i < maxn; j++) {
      isp[i * p[j]] = true;
      if (i % p[j] == 0) break;
    }
  }
}
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
int getfac(int num) {
  int e = sqrt(num);
  int res = 0;
  for (int i = 1; i <= e; i++)
    if (num % i == 0) {
      res++;
      if (num / i != i) res++;
    }
  return res;
}
int c(int a, int b) {
  int ans = 1;
  for (int i = 0; i < b; i++) {
    ans *= (a - i);
    ans /= (i + 1);
  }
  return ans;
}
inline int choose3(int k) { return c(k, 3) + 2 * c(k, 2) + k; }
int main() {
  int t;
  cin >> t;
  while (t--) {
    int x, y, z;
    cin >> x >> y >> z;
    int g1 = gcd(x, y);
    int g2 = gcd(y, z);
    int g3 = gcd(x, z);
    int g4 = gcd(g1, g2);
    int f1 = getfac(g1), f2 = getfac(g2), f3 = getfac(g3), f4 = getfac(g4);
    int k1 = getfac(x) - f1 - f3 + f4;
    int k2 = getfac(y) - f1 - f2 + f4;
    int k3 = getfac(z) - f2 - f3 + f4;
    int k4 = f3 - f4;
    int k5 = f1 - f4;
    int k6 = f2 - f4;
    int k7 = f4;
    int ss1 = k1 + k2 + k3, ss4 = k4 + k5 + k6;
    int sum111, sum112, sum113, sum122, sum222, sum133, sum333, sum123, sum223,
        sum233;
    sum111 = k1 * k2 * k3;
    sum112 = k1 * k2 * (ss4 - k5) + k3 * k2 * (ss4 - k6) + k1 * k3 * (ss4 - k4);
    sum113 = k7 * (k1 * k2 + k2 * k3 + k3 * k1);
    sum122 = k1 * (k4 * k5 + k5 * k6 + k4 * k6 + c(k6, 2) + k6) +
             k2 * (k4 * k5 + k5 * k6 + k4 * k6 + c(k4, 2) + k4) +
             k3 * (k4 * k5 + k5 * k6 + k4 * k6 + c(k5, 2) + k5);
    sum133 = ss1 * (c(k7, 2) + k7);
    sum333 = (c(k7, 3) + 2 * c(k7, 2) + k7);
    sum123 = ss1 * ss4;
    sum233 = ss4 * (c(k7, 2) + k7);
    sum223 = k7 * (c(ss4, 2) + ss4);
    sum222 = choose3(ss4) - choose3(k4) - choose3(k5) - choose3(k6);
    cout << sum111 + sum112 + sum113 + sum122 + sum133 + sum333 + sum123 +
                sum233 + sum223 + sum222
         << endl;
  }
  return 0;
}
