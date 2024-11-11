#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  if (!b) return a;
  return gcd(b, a % b);
}
int main() {
  long long t, w, b;
  cin >> t >> w >> b;
  long long times = t / w / (b / gcd(w, b));
  long long p = ((times)*min(w, b)) - 1;
  long long q = t;
  long long L = (times * w * b) / gcd(w, b);
  p += min(t - L + 1, min(w, b));
  long long gcd_pq = gcd(p, q);
  cout << p / gcd_pq << "/" << q / gcd_pq << endl;
  return 0;
}
