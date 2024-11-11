#include <bits/stdc++.h>
using namespace std;
int k;
string n, m;
int a[1001], b[1001], ns, ms;
int fs, ss;
int lcm(int, int);
int gcd(int, int);
int main() {
  cin >> k >> n >> m;
  ns = n.size();
  ms = m.size();
  for (int i = 0; i < ns; i++) {
    a[i] = (n[i] == 'R' ? 0 : (n[i] == 'P' ? 1 : 2));
  }
  for (int i = 0; i < ms; i++) {
    b[i] = (m[i] == 'R' ? 0 : (m[i] == 'P' ? 1 : 2));
  }
  int q = 0, p = 0, l = lcm(ns, ms);
  for (int i = 0; i < l; i++) {
    if ((a[q] == 0 && b[p] == 2) || (a[q] == 2 && b[p] == 1) ||
        (a[q] == 1 && b[p] == 0))
      fs++;
    else if (a[q] != b[p])
      ss++;
    q++, p++;
    if (q == ns) q = 0;
    if (p == ms) p = 0;
  }
  fs *= k / l;
  ss *= k / l;
  p = q = 0;
  for (int i = 0; i < k % l; i++) {
    if ((a[q] == 0 && b[p] == 2) || (a[q] == 2 && b[p] == 1) ||
        (a[q] == 1 && b[p] == 0))
      fs++;
    else if (a[q] != b[p])
      ss++;
    q++, p++;
    if (q == ns) q = 0;
    if (p == ms) p = 0;
  }
  cout << fs << " " << ss;
}
int lcm(int q, int p) { return q * p / gcd(q, p); }
int gcd(int q, int p) {
  if (q > p) {
    q += p, p = q - p, q -= p;
  }
  if (!q) return p;
  return gcd(p - q, q);
}
