#include <bits/stdc++.h>
using namespace std;
const long long int mod = 1e9 + 7;
long long int fexpo(long long int a, long long int b) {
  if (b == 0) return 1LL;
  if (b == 1) return a;
  if (b == 2) return a * a;
  if (b % 2 == 0)
    return fexpo(fexpo(a, b / 2), 2);
  else
    return a * fexpo(fexpo(a, (b - 1) / 2), 2);
}
void solve() {
  int a, b;
  char x;
  cin >> a >> x >> b;
  double hour, minute;
  double Hour = ((double)a * 60.0000000) + (double)b;
  hour = 0.5 * Hour;
  minute = b * 6;
  if (hour >= 360) hour = 360 - hour;
  printf("%.9lf %.9lf ", hour, minute);
}
int main() { solve(); }
