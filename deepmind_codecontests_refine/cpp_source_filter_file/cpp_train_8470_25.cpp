#include <bits/stdc++.h>
using namespace std;
void FuckMyLife() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
int gcd(int a, int b) {
  if (!a || !b) return a + b;
  return gcd(b, a % b);
}
long long CalcArithmeticAn(long long a1, long long n, long long d) {
  return a1 + (n - 1) * d;
}
long long CalcArithmeticSn1(long long a1, long long an, long long n) {
  return (n * (a1 + an)) / 2;
}
long long CalcArithmeticSn2(long long a1, long long n, long long d) {
  return (n * (2 * a1 + (n - 1) * d)) / 2;
}
double CalcGeometricAn(long long a, long long r, long long n) {
  return (a * pow(r, n - 1));
}
double CalcGeometricSn(long long a, long long r, long long n) {
  return (a * (1 - pow(r, n))) / (1 - r);
}
bool isDistincit(int n) {
  int a[10] = {0};
  for (int i = 0; i < 4; i++) {
    int sub = n % 10;
    n /= 10;
    a[sub]++;
  }
  for (int i = 0; i < 10; i++)
    if (a[i] > 1) return 0;
  return 1;
}
int main() {
  FuckMyLife();
  int n;
  cin >> n;
  for (int i = n + 1; i < 9000; i++) {
    if (isDistincit(i)) {
      cout << i << '\n';
      return 0;
    }
  }
  return 0;
}
