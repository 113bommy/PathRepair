#include <bits/stdc++.h>
using namespace std;
long long bigmod(long long a, long long b, long long m) {
  long long x = 1, y = a;
  while (b > 0) {
    if (b & 1) x = (x * y) % m;
    y = (y * y) % m;
    b >>= 1;
  }
  return x;
}
long long gcd(long long a, long long b) {
  long long rem = 0;
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long lcm(long long a, long long b) { return (a / gcd(a, b)) * b; }
int main() {
  long long l, i;
  string s;
  map<long long, long long> make_pair;
  cin >> l;
  getchar();
  cin >> s;
  for (i = 0; i < l; i++) {
    if (s[i] == 'A')
      make_pair['A']++;
    else if (s[i] == 'T')
      make_pair['T']++;
    else if (s[i] == 'C')
      make_pair['C']++;
    else if (s[i] == 'G')
      make_pair['G']++;
    else
      make_pair['E']++;
  }
  long long e = make_pair['E'], t = make_pair['T'], c = make_pair['C'],
            g = make_pair['G'], m = make_pair['A'];
  if (l % 4 || t > l / 4 || c > l / 4 || g > l / 4 || m > l / 4) {
    cout << "===\n";
    return 0;
  }
  t = l / 4 - t;
  c = l / 4 - c;
  g = l / 4 - g;
  m = l / 4 - m;
  for (i = 0; i < l; i++) {
    if (s[i] == '?') {
      if (c) {
        s[i] = 'C';
        c--;
      } else if (g) {
        s[i] = 'G';
        g--;
      } else if (t) {
        s[i] = 'T';
        t--;
      } else if (m) {
        s[i] = 'A';
        m--;
      }
    }
  }
  cout << s;
}
