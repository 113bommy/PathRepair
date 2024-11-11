#include <bits/stdc++.h>
using namespace std;
long long int n, p, s, dpl[3003][3003], dpr[3003][3003], mejor, division,
    faltan, tmp;
pair<pair<long long int, long long int>, int> a[3003];
vector<long long int> equipop, equipos;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> p >> s;
  for (int i = (1); i <= (n); i++) cin >> a[i].first.first;
  for (int i = (1); i <= (n); i++) cin >> a[i].first.second;
  for (int i = (1); i <= (n); i++) a[i].second = i;
  sort(a + 1, a + n + 1);
  reverse(a + 1, a + n + 1);
  for (int i = (0); i <= (n); i++)
    for (int j = (1); j <= (n); j++) dpl[i][j] = dpr[i][j] = (-(1ll << 60));
  for (int i = (1); i <= (n); i++) {
    for (int x = (0); x <= (min(p, (long long int)i)); x++) {
      if (x)
        dpl[i][x] = max(dpl[i - 1][x - 1] + a[i].first.first,
                        dpl[i - 1][x] + a[i].first.second);
      else
        dpl[i][x] = dpl[i - 1][x] + a[i].first.second;
    }
  }
  for (int i = (n); i >= (1); i--) {
    for (int x = (0); x <= (p); x++) {
      if (x)
        dpr[i][x] = max(dpr[i + 1][x - 1] + a[i].first.second, dpr[i + 1][x]);
      else
        dpr[i][x] = dpr[i + 1][x];
    }
  }
  mejor = (-(1ll << 60));
  division = -1;
  for (int i = (p); i <= (n); i++) {
    faltan = s - (i - p);
    if (faltan >= 0 && faltan <= n - i) {
      tmp = dpl[i][p] + dpr[i + 1][faltan];
      if (tmp > mejor) {
        mejor = tmp;
        division = i;
      }
    }
  }
  for (int i = (division); i >= (1); i--) {
    if (p && dpl[i][p] == dpl[i - 1][p - 1] + a[i].first.first) {
      equipop.push_back(a[i].second);
      --p;
    } else {
      equipos.push_back(a[i].second);
      --s;
    }
  }
  for (int i = (division + 1); i <= (n); i++) {
    if (dpr[i][s] == dpr[i + 1][s - 1] + a[i].first.second) {
      equipos.push_back(a[i].second);
      --s;
    }
    if (!s) break;
  }
  sort(equipop.begin(), equipop.end());
  sort(equipos.begin(), equipos.end());
  cout << mejor << "\n";
  for (auto c : equipop) cout << c << " ";
  cout << "\n";
  for (auto c : equipos) cout << c << " ";
  cout << "\n";
  return 0;
}
