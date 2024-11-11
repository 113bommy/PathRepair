#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, l, c, d, p, nl, np;
  cin >> n >> k >> l >> c >> d >> p >> nl >> np;
  int ml;
  ml = k * l;
  int tost;
  tost = ml / nl;
  int laim;
  laim = c * d;
  int soli;
  soli = p / np;
  int mn;
  mn = min(tost, min(laim, soli));
  cout << mn / 3;
}
