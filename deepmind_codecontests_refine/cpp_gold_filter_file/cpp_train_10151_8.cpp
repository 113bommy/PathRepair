#include <bits/stdc++.h>
using namespace std;
const int MAXN = 250;
const int INF = 0x3f3f3f3f;
char arr[10][10];
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
bool judge(long long t, long long a, long long b) {
  if (log(a * 1.0) + log(b * 1.0) - log(gcd(a, b) * 1.0) > log(t)) return true;
  return false;
}
int main() {
  long long xx, yy, t, a, b, lcm, temp;
  scanf("%I64d%I64d%I64d", &t, &a, &b);
  if (a == b) {
    cout << "1/1" << endl;
    return 0;
  }
  if (b > a) swap(a, b);
  yy = t;
  if (judge(t, a, b))
    xx = min(b - 1, t);
  else {
    lcm = a / gcd(a, b) * b;
    long long x = t / lcm;
    xx = x * b + min((t - lcm * x), b - 1);
  }
  temp = gcd(xx, yy);
  xx /= temp;
  yy /= temp;
  cout << xx << '/' << yy << endl;
  return 0;
}
