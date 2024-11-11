#include <bits/stdc++.h>
using namespace std;
long double kat(pair<long double, long double> A,
                pair<long double, long double> B,
                pair<long double, long double> C) {
  long double k1 = atan2(A.second - B.second, A.first - B.first),
              k2 = atan2(C.second - B.second, C.first - B.first);
  k2 -= k1;
  if (k2 < 0) k2 += 2 * acos(-1);
  if (k2 >= 2 * acos(-1)) k2 -= 2 * acos(-1);
  return k2;
}
void skieruj(vector<pair<long double, long double> >& V) {
  long double suma = 0.0;
  for (int i = 1; i <= V.size() - 2; i++) suma += kat(V[i - 1], V[i], V[i + 1]);
  if (suma > acos(-1) * V.size() - 2) reverse(V.begin(), V.end());
}
bool pkt_w_kacie(pair<long double, long double> p,
                 pair<long double, long double> A,
                 pair<long double, long double> B,
                 pair<long double, long double> C) {
  long double k1 = atan2(A.second - B.second, A.first - B.first),
              k2 = atan2(C.second - B.second, C.first - B.first),
              k3 = atan2(p.second - B.second, p.first - B.first);
  if (k1 < 0) k1 += 2.0 * acos(-1);
  while (k2 < k1) k2 += 2.0 * acos(-1);
  while (k3 < k1) k3 += 2.0 * acos(-1);
  if (k3 <= k2) return true;
  return false;
}
bool zmienia(pair<long double, long double> aktp,
             pair<long double, long double> aktk, int nr,
             vector<pair<long double, long double> >& V) {
  pair<long double, long double> w = V[nr];
  if ((aktk.first - aktp.first) * (w.second - aktk.second) !=
      (w.first - aktk.first) * (aktk.second - aktp.second))
    return false;
  if (aktp.first == w.first && aktp.second == w.second) swap(aktp, aktk);
  aktk = make_pair(w.first + (w.first - aktp.first),
                   w.second + (w.second - aktp.second));
  if (pkt_w_kacie(aktp, V[nr - 1], V[nr], V[nr + 1]) ==
      pkt_w_kacie(aktk, V[nr - 1], V[nr], V[nr + 1]))
    return false;
  return true;
}
int il_wek(pair<long double, long double> p, pair<long double, long double> k,
           pair<long double, long double> inny) {
  long double pom = (k.first - p.first) * (inny.second - p.second) -
                    (inny.first - p.first) * (k.second - p.second);
  if (pom > 0) return 1;
  if (pom < 0) return -1;
  return 0;
}
pair<long double, long double> wsp(pair<long double, long double> p,
                                   pair<long double, long double> k) {
  if (p.first == k.first) return {0, 0};
  long double a = (k.second - p.second) / (k.first - p.first),
              b = p.second - a * p.second;
  return {a, b};
}
void punkt_przeciecia(pair<long double, long double> p,
                      pair<long double, long double> k,
                      pair<long double, long double> innyp,
                      pair<long double, long double> innyk,
                      vector<pair<long double, long double> >& V) {
  if (il_wek(p, k, innyp) * il_wek(p, k, innyk) != -1) return;
  pair<long double, long double> wsp1 = wsp(p, k), wsp2 = wsp(innyp, innyk);
  if (p.first == k.first)
    V.push_back({p.first, wsp2.first * p.first + wsp2.second});
  else if (innyp.first == innyk.first)
    V.push_back({innyp.first, wsp1.first * innyp.first + wsp1.second});
  else {
    long double x = (wsp2.second - wsp1.second) / (wsp1.first - wsp2.first);
    V.push_back({x, wsp1.first * x + wsp1.second});
  }
}
int main() {
  cout << setprecision(10) << fixed;
  int n, m;
  cin >> n >> m;
  vector<pair<long double, long double> > V;
  V.resize(n);
  for (auto& P : V) cin >> P.first >> P.second;
  V.push_back(V[0]);
  V.push_back(V[1]);
  skieruj(V);
  while (m--) {
    vector<pair<long double, long double> > P;
    pair<long double, long double> aktp, aktk;
    cin >> aktp.first >> aktp.second >> aktk.first >> aktk.second;
    for (int i = 1; i <= n; i++)
      if (zmienia(aktp, aktk, i, V)) P.push_back(V[i]);
    for (int i = 1; i <= n; i++)
      punkt_przeciecia(aktp, aktk, V[i], V[i + 1], P);
    sort(P.begin(), P.end());
    long double wynik = 0.0;
    for (int i = 1; i < P.size(); i += 2)
      wynik += sqrt(
          (P[i].first - P[i - 1].first) * (P[i].first - P[i - 1].first) +
          (P[i].second - P[i - 1].second) * (P[i].second - P[i - 1].second));
    cout << wynik << endl;
  }
  return 0;
}
