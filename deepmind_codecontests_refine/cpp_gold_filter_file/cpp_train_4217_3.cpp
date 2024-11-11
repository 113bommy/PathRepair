#include <bits/stdc++.h>
const int MOD = 1000000007;
const int MAX = 10000005;
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int a, b, c, d, e, f;
  cin >> a >> b >> c >> d >> e >> f;
  long long sum1 = a + b + c;
  long long sum2 = d + e + f;
  float area1, area2, A_a, A_b, A_c, A_d, A_e, A_f, A_equi;
  area1 = (sqrt(3) / 4) * (sum1 * sum1);
  area2 = (sqrt(3) / 4) * (sum2 * sum2);
  A_a = (sqrt(3) / 4) * (a * a);
  A_b = (sqrt(3) / 4) * (b * b);
  A_c = (sqrt(3) / 4) * (c * c);
  A_d = (sqrt(3) / 4) * (d * d);
  A_e = (sqrt(3) / 4) * (e * e);
  A_f = (sqrt(3) / 4) * (f * f);
  A_equi = (sqrt(3) / 4) * (1 * 1);
  area1 = area1 - A_a - A_e - A_c;
  area2 = area2 - A_d - A_f - A_f;
  float num1 = area1 / A_equi;
  float num2 = area2 / A_equi;
  cout << (long long int)(num1 + 0.5);
}
