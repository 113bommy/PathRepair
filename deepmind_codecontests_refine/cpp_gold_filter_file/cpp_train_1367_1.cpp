#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100000;
int n;
double len[MAXN + 1];
string s;
void init() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> len[i];
  cin >> s;
}
void solve() {
  double lenWater = 0, lenLand = 0, Demand = 5, Sta = 0, T = 0;
  for (int i = 1; i <= n; i++) {
    if (s[i - 1] == 'W') {
      Demand = 3;
      if (len[i] <= Sta) {
        Sta -= len[i];
        lenWater += len[i];
        T += 1.0 * len[i];
      } else {
        double x = (len[i] - Sta) / 2.0;
        Sta = 0;
        lenWater += len[i] - x;
        T += 1.0 * (len[i] - x) + 3.0 * x;
      }
    } else if (s[i - 1] == 'G') {
      if (len[i] <= Sta) {
        Sta -= len[i];
        lenLand += len[i];
      } else {
        double lw = (0.5 * (len[i] - Sta) <= lenWater ? 0.5 * (len[i] - Sta)
                                                      : lenWater);
        lenWater -= lw;
        Sta += lw * 2.0;
        T += (3.0 - 1.0) * lw;
        double x = (len[i] - Sta) / 2.0;
        Sta = 0;
        lenLand += len[i] - x;
        T += 1.0 * (len[i] - x) + 5.0 * x;
      }
    } else if (s[i - 1] == 'L') {
      if (len[i] > Sta) {
        double lw = (0.5 * (len[i] - Sta) <= lenWater ? 0.5 * (len[i] - Sta)
                                                      : lenWater);
        lenWater -= lw;
        Sta += lw * 2.0;
        T += (3.0 - 1.0) * lw;
        if (len[i] > Sta) {
          double lg = (0.5 * (len[i] - Sta) <= lenLand ? 0.5 * (len[i] - Sta)
                                                       : lenLand);
          lenLand -= lg;
          Sta += lg * 2.0;
          T += (5.0 - 1.0) * lg;
          if (len[i] > Sta) {
            T += Demand * (len[i] - Sta);
            Sta = len[i];
          }
        }
      }
      Sta -= len[i];
      T += 1.0 * len[i];
    }
  }
  cout << (long long)(T + 1e-6) << "\n";
}
int main() {
  cerr.precision(12);
  init();
  solve();
}
