#include <bits/stdc++.h>
using namespace std;
void game(char n, char p, int &rn, int &rp) {
  if ((n == 'R' && p == 'S') || (n == 'P' && p == 'R') ||
      (n == 'S' && p == 'P'))
    rn++;
  else if ((p == 'R' && n == 'S') || (p == 'P' && n == 'R') ||
           (p == 'S' && n == 'P'))
    rp++;
}
int main() {
  int n = 0, p = 0;
  long long g;
  cin >> g;
  string ns, ps;
  cin >> ns;
  cin >> ps;
  if (ns == ps)
    cout << 0 << " " << 0 << endl;
  else {
    for (long long i = 0; i < ns.length() * ps.length(); i++) {
      game(ns[i % ns.length()], ps[i % ps.length()], n, p);
    }
    p *= g / (ns.length() * ps.length());
    n *= g / (ns.length() * ps.length());
    for (long long i = 0; i < g % (ns.length() * ps.length()); i++) {
      game(ns[i % ns.length()], ps[i % ps.length()], n, p);
    }
    cout << p << " " << n << endl;
  }
  return 0;
}
