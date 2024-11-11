#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
int main() {
  long long a, b, gc;
  int ga, gb, gcc;
  cin >> a >> b;
  gc = gcd(a, b);
  gcc = a / gc * b;
  ga = gcc / a - 1;
  gb = gcc / b - 1;
  if (ga < gb)
    ga++;
  else if (ga > gb)
    gb++;
  if (ga > gb)
    cout << "Dasha" << endl;
  else if (ga < gb)
    cout << "Masha" << endl;
  else
    cout << "Equal" << endl;
  return 0;
}
