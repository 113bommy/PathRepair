#include <bits/stdc++.h>
using namespace std;
long long t, a, b;
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long bcnn(long long a, long long b) { return a * b / gcd(a, b); }
long long calc() {
  long long d = gcd(a, b);
  long long tmp = a / d;
  if (t / tmp < b) {
    return min(t, min(a, b)) - 1;
  }
  long long hang = tmp * b;
  long long mod = t % hang;
  long long g = t / hang;
  long long base = min(a, b);
  return base * g + min(base - 1, mod);
}
int main(int argc, const char* argv[]) {
  if (0) freopen("../../input.txt", "r", stdin);
  cin >> t >> a >> b;
  long long tuso = calc();
  long long mauso = t;
  long long d = gcd(tuso, mauso);
  tuso /= d;
  mauso /= d;
  cout << tuso << "/" << mauso << endl;
  return 0;
}
