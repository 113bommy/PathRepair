#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
int main() {
  long long t, w, b;
  cin >> t >> w >> b;
  long long d = gcd(w, b);
  long long a = w / d;
  long long m = min(w, b);
  long long x = ((t / a) / b);
  long long n = x * m + min(m, t - x * a * b);
  long long dd = gcd(n, t);
  cout << n / dd << '/' << t / dd << endl;
}
