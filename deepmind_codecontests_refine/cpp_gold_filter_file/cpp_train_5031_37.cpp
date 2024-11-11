#include <bits/stdc++.h>
using namespace std;
int const MAXn = 1e6 + 2;
vector<unsigned long long> adya[MAXn];
vector<unsigned long long> H[MAXn];
vector<pair<int, int> > edge;
unsigned long long pot[MAXn];
unsigned long long funt_H(int a, int b, int id) {
  return H[id][b] - (!a ? 0 : H[id][a - 1]) * pot[b - a + 1];
}
unordered_map<unsigned long long, long long> mapa;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, m;
  cin >> n >> m;
  pot[0] = 1;
  for (int i = 1; i <= n + 1; i++) pot[i] = pot[i - 1] * 1000007;
  for (int i = 1; i <= m; i++) {
    int n1, n2;
    cin >> n1 >> n2;
    adya[n1].push_back(n2);
    adya[n2].push_back(n1);
    edge.push_back({n1, n2});
  }
  long long sol = 0;
  for (int i = 1; i <= n; i++) {
    adya[i].push_back(0);
    adya[i].push_back(1e6 + 2);
    sort((adya[i]).begin(), (adya[i]).end());
    for (auto x : adya[i]) {
      if (H[i].empty()) {
        H[i].push_back(x);
        continue;
      }
      H[i].push_back(H[i].back() * 1000007 + x);
    }
    mapa[H[i].back()]++;
  }
  for (auto x : mapa) {
    sol = (sol + ((x.second * (x.second - 1)) / 2));
  }
  for (auto x : edge) {
    int a = x.first, b = x.second;
    if (adya[a].size() != adya[b].size()) continue;
    int pos =
        lower_bound((adya[b]).begin(), (adya[b]).end(), a) - adya[b].begin();
    int tam = adya[b].size() - 1;
    unsigned long long hb =
        funt_H(0, pos - 1, b) * pot[tam - pos] + funt_H(pos + 1, tam, b);
    pos = lower_bound((adya[a]).begin(), (adya[a]).end(), b) - adya[a].begin();
    tam = adya[a].size() - 1;
    unsigned long long ha =
        funt_H(0, pos - 1, a) * pot[tam - pos] + funt_H(pos + 1, tam, a);
    if (hb == ha) sol++;
  }
  cout << sol;
  return 0;
}
