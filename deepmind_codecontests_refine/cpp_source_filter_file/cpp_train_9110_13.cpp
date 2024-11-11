#include <bits/stdc++.h>
using namespace std;
long long n, m, s, d;
vector<long long> esteet;
vector<pair<string, long long>> tuloste;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m >> s >> d;
  esteet.resize(n);
  for (int i = 0; i < n; i++) {
    long long x;
    cin >> x;
    esteet[i] = x;
  }
  sort(esteet.begin(), esteet.end());
  if (esteet[0] < s) {
    cout << "IMPOSSIBLE" << endl;
    return 0;
  }
  long long edellinen = esteet[0] - 1;
  if (edellinen > 0) tuloste.push_back({"RUN", edellinen});
  for (int i = 1; i < n; i++) {
    if ((esteet[i] - esteet[i - 1]) - 2 < s) continue;
    if (esteet[i - 1] - edellinen >= d) {
      cout << "IMPOSSIBLE" << endl;
      return 0;
    } else {
      tuloste.push_back({"JUMP", (esteet[i - 1] + 1 - edellinen)});
      tuloste.push_back({"RUN", (esteet[i] - esteet[i - 1]) - 2});
      edellinen = esteet[i] - 1;
    }
  }
  if (esteet[n - 1] - edellinen >= d) {
    cout << "IMPOSSIBLE" << endl;
    return 0;
  }
  tuloste.push_back({"JUMP", esteet[n - 1] + 1 - edellinen});
  edellinen = esteet[n - 1] + 1;
  if (m - edellinen > 0) tuloste.push_back({"RUN", m - edellinen});
  for (int i = 0; i < tuloste.size(); i++) {
    cout << tuloste[i].first << " " << tuloste[i].second << endl;
  }
}
