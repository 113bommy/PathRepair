#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  while (a && b) {
    if (a > b)
      a %= b;
    else
      b %= a;
  }
  return a + b;
}
int main() {
  long double t, w, b;
  cin >> t >> w >> b;
  long long ww = w;
  long long bb = b;
  long double Gcd = gcd(ww, bb);
  long double lcm = (w * b) / Gcd;
  long long up = 0, down = t;
  if (lcm > t) {
    up = min(min(w, b) - 1, t);
  } else {
    long long kol = (t / lcm);
    long long q1 = (kol)*min(w, b) - 1;
    long long pos = kol * lcm;
    q1 += min(t - pos + 1, min(w, b));
    up = q1;
  }
  long long uup = up;
  long long ddown = down;
  long long G = gcd(up, down);
  long long u = up / G;
  long long d = down / G;
  cout << u << "/" << d << endl;
}
