#include <bits/stdc++.h>
using namespace std;
const long long N = 1e6 + 69, base = 1024 * 1024, mod = 1e9 + 7;
vector<int> wyn;
void pisz(vector<int> ve) {
  for (int i = 0; i < ve.size(); i++) cout << ve[i] << " ";
  cout << "\n";
}
void gemacht(vector<int> vek, vector<int> roz, int gl) {
  vek.resize(distance(vek.begin(), unique(vek.begin(), vek.end())));
  if (vek.size() == 1 && vek[0] == 0) {
    if (roz.size() < wyn.size()) wyn = roz;
    return;
  }
  if (gl > 20) return;
  int zle = 0;
  vector<int> re1, re2;
  for (int i = 0; i < vek.size(); i++) {
    if (vek[i] % 2 != 0) zle = 1;
  }
  if (zle == 0) {
    for (int i = 0; i < vek.size(); i++) {
      vek[i] /= 2;
    }
    gemacht(vek, roz, gl + 1);
    return;
  }
  for (int i = 0; i < vek.size(); i++) {
    if (vek[i] % 2 != 0)
      re1.push_back((vek[i] + 1) / 2), re2.push_back((vek[i] - 1) / 2);
    else
      re1.push_back((vek[i]) / 2), re2.push_back((vek[i]) / 2);
  }
  roz.push_back(-(1 << gl));
  gemacht(re1, roz, gl + 1);
  roz.pop_back();
  roz.push_back((1 << gl));
  gemacht(re2, roz, gl + 1);
}
int32_t main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  vector<int> vek;
  wyn.resize(100);
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    vek.push_back(a);
  }
  sort(vek.begin(), vek.end());
  gemacht(vek, vector<int>{}, 0);
  cout << wyn.size() << "\n";
  for (int i = 0; i < wyn.size(); i++) cout << wyn[i] << " ";
}
