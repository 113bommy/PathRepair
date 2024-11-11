#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1);
const double eps = 1e-9;
const long long mod = 1e9 + 7;
const long long llinf = (1ll << 60);
const long long N = 5e1 + 5;
long long cosa1[N];
map<long long, vector<pair<long long, long long> > > contador;
long long n;
vector<pair<long long, long long> > maximoSinOverlapearse(
    vector<pair<long long, long long> > vectora) {
  sort((vectora).begin(), (vectora).end(),
       [](pair<long long, long long> cosa1, pair<long long, long long> cosa2) {
         if (cosa1.second != cosa2.second) {
           return cosa1.second < cosa2.second;
         }
         return cosa1.first < cosa2.first;
       });
  vector<pair<long long, long long> > vectorb;
  long long last = 0;
  for (long long i = (0); i <= (((long long)(vectora).size()) - 1); i += (+1)) {
    if (last < vectora[i].first) {
      vectorb.push_back(vectora[i]);
      last = vectora[i].second;
    }
  }
  return vectorb;
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
  long long resultado = 0;
  cin >> n;
  for (long long i = (1); i <= ((n)); i += (+1)) {
    cin >> cosa1[i];
    cosa1[i] += cosa1[i - 1];
    resultado += cosa1[i];
  }
  n++;
  n--;
  for (long long l = (1); l <= ((n)); l += (+1)) {
    for (long long r = (1); r <= ((n)); r += (+1)) {
      if (r < l) {
        continue;
      }
      long long suma = cosa1[r] - cosa1[l - 1];
      contador[suma].push_back({l, r});
    }
  }
  for (auto &iterador : contador) {
    iterador.second = maximoSinOverlapearse(iterador.second);
  }
  long long suma = 0;
  for (auto it : contador) {
    if ((long long)(it.second).size() > (long long)(contador[suma]).size()) {
      suma = it.first;
      resultado--;
    }
  }
  cout << (long long)(contador[suma]).size() << '\n';
  for (auto aux : contador[suma]) {
    cout << aux.first << " " << aux.second << '\n';
  }
  return 0;
}
