#include <bits/stdc++.h>
using namespace std;
bool isPrime(long long int x) {
  if (x <= 4 || x % 2 == 0 || x % 3 == 0) return x == 2 || x == 3;
  for (int i = 5; i * i <= x; i += 6)
    if (x % i == 0 || x % (i + 2) == 0) return 0;
  return 1;
}
int NumDigits(int x) {
  return (
      x < 10
          ? 1
          : (x < 100
                 ? 2
                 : (x < 1000
                        ? 3
                        : (x < 10000
                               ? 4
                               : (x < 100000
                                      ? 5
                                      : (x < 1000000
                                             ? 6
                                             : (x < 10000000
                                                    ? 7
                                                    : (x < 100000000
                                                           ? 8
                                                           : (x < 1000000000
                                                                  ? 9
                                                                  : 10)))))))));
}
inline void boostIO() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
inline long long int Pow10(int x) {
  if (x == 0) return 1;
  if (x == 1) return 10;
  if (x == 2) return 100;
  if (x == 3) return 1000;
  if (x == 4) return 10000;
  if (x == 5) return 100000;
  if (x == 6) return 1000000;
  if (x == 7) return 10000000;
  if (x == 8) return 100000000;
  if (x == 9) return 1000000000;
  if (x == 10) return 10000000000;
}
long long int gcd(long long int a, long long int b) {
  return b ? gcd(b, a % b) : a;
}
long long int lcm(long long int a, long long int b) {
  return a * b / gcd(a, b);
}
int main() {
  boostIO();
  cout.precision(10);
  long double a, b, c;
  cin >> a >> b >> c;
  long double x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  long double x3, y3, x4, y4;
  long double One = abs(x1 - (-c - y1 * b) / a) + abs(x2 - (-c - y2 * b) / a);
  x3 = (-c - y1 * b) / a;
  y3 = (-c - x3 * a) / b;
  x4 = (-c - y2 * b) / a;
  y4 = (-c - x4 * a) / b;
  One += sqrt((x3 - x4) * (x3 - x4) + (y3 - y4) * (y3 - y4));
  long double Two = abs(x1 - (-c - y1 * b) / a) + abs(y2 - (-c - x2 * a) / b);
  x3 = (-c - y1 * b) / a;
  y3 = (-c - x3 * a) / b;
  y4 = (-c - x2 * a) / b;
  x4 = (-c - y4 * b) / a;
  Two += sqrt((x3 - x4) * (x3 - x4) + (y3 - y4) * (y3 - y4));
  long double Three = abs(y1 - (-c - x1 * a) / b) + abs(x2 - (-c - y2 * b) / a);
  y3 = (-c - x1 * a) / b;
  x3 = (-c - y3 * b) / a;
  x4 = (-c - y2 * b) / a;
  y4 = (-c - x4 * a) / b;
  Three += sqrt((x3 - x4) * (x3 - x4) + (y3 - y4) * (y3 - y4));
  long double Four = abs(y1 - (-c - x1 * a) / b) + abs(y2 - (-c - x2 * a) / b);
  y3 = (-c - x1 * a) / b;
  x3 = (-c - y3 * b) / a;
  y4 = (-c - x2 * a) / b;
  x4 = (-c - y4 * b) / a;
  Four += sqrt((x3 - x4) * (x3 - x4) + (y3 - y4) * (y3 - y4));
  long double Five = abs(x1 - x2) + abs(y1 - y2);
  cout << min(Five, min(min(One, Two), min(Three, Four))) << '\n';
  return 0;
}
