#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, k, l, c, d, p, nl, np, C, L, S, t = 0;
  cin >> n >> k >> l >> c >> d >> p >> nl >> np;
  L = (k * l) / n;
  S = p / n;
  C = d;
  while ((nl <= L && np <= S) && (C >= n)) {
    L = L - nl;
    S = S - np;
    C = C - n;
    t++;
  }
  cout << t << "\n";
}
