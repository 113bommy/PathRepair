#include <bits/stdc++.h>
using namespace std;
long long a, b, c, d, e, f[100009], pas, g[100009], z[409][5], x[409], sq;
map<long long, long long> mp;
pair<string, long long> p[100009];
void updseg(long long q) {
  x[q] = 0;
  z[q][0] = 0;
  z[q][1] = 0;
  z[q][2] = 0;
  z[q][3] = 0;
  z[q][4] = 0;
  long long ka = 0;
  for (long long h = (q - 1) * sq + 1; h <= q * sq; h++) {
    if (f[h] != 0) {
      x[q]++;
      ka++;
      if (ka == 5) ka = 0;
    }
    z[q][ka] += f[h];
  }
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0);
  cin >> a;
  multiset<pair<long long, long long> > s;
  s;
  multiset<pair<long long, long long> >::iterator it;
  it;
  for (b = 1; b <= a; b++) {
    cin >> p[b].first;
    if (p[b].first == "sum") {
      continue;
    }
    cin >> p[b].second;
    if (p[b].first == "add") {
      s.insert(make_pair(p[b].second, b));
    }
  }
  for (it = s.begin(); it != s.end(); it++) {
    pas++;
    g[(*it).second] = pas;
  }
  long ju = pas;
  sq = sqrt(pas);
  for (b = 1; b <= a; b++) {
    if (p[b].first == "sum") {
      long long ka = 0;
      pas = 0;
      for (c = 1; c <= a; c++) {
        if ((c - 1) * sq + 1 > ju) break;
        e = a;
        if (e > c * sq) e = c * sq;
        pas += z[c][(8 - ka) % 5];
        ka += x[c];
        ka %= 5;
      }
      cout << pas << endl;
      continue;
    }
    c = p[b].second;
    if (p[b].first == "del") {
      f[mp[c]] = 0;
      updseg((mp[c] - 1) / sq + 1);
      continue;
    }
    f[g[b]] = c;
    mp[c] = g[b];
    updseg((g[b] - 1) / sq + 1);
  }
  return 0;
}
