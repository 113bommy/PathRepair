#include <bits/stdc++.h>
using namespace std;
long long const MX = 2e5;
long long const INF = 1e9 + 9;
struct Alquiler {
  long long precio, tanque;
} A;
bool cmp(Alquiler &i, Alquiler &j) { return i.precio < j.precio; }
long long RoadToCinema(long long ini, long long fin, long long t,
                       vector<long long> &gas) {
  long long med = (ini + fin) / 2;
  if (2 * med != ini + fin) med++;
  if (fin == med) return fin;
  if (ini > 1e9) return -1;
  bool posible = true;
  long long Pant = 0, Ttotal = 0, dist;
  for (long long i = 0; i < gas.size(); i++) {
    dist = gas[i] - Pant;
    Ttotal += max(dist, 3 * dist - med);
    if (dist > med) posible = false;
    Pant = gas[i];
  }
  if (posible && Ttotal <= t) return RoadToCinema(ini, med, t, gas);
  return RoadToCinema(med, fin, t, gas);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long n, k, s, t;
  cin >> n >> k >> s >> t;
  vector<Alquiler> listaCarros;
  for (long long i = 0; i < n; i++) {
    cin >> A.precio >> A.tanque;
    listaCarros.push_back(A);
  }
  vector<long long> gas(k + 1);
  for (long long i = 0; i < k; i++) {
    cin >> gas[i];
  }
  gas[k] = s;
  sort(gas.begin(), gas.end());
  sort(listaCarros.begin(), listaCarros.end(), cmp);
  long long capmn = RoadToCinema(0ll, INF, t, gas);
  if (capmn == -1) {
    cout << -1;
    return 0;
  }
  for (long long i = 0; i < n; i++) {
    if (listaCarros[i].tanque >= capmn) {
      cout << listaCarros[i].precio;
      return 0;
    }
  }
  cout << -1;
  return 0;
}
