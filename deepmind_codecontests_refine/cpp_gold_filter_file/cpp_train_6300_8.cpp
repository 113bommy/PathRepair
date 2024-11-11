#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(10);
  int N;
  cin >> N;
  vector<int> P(N);
  for (int i = 0; i < N; i++) cin >> P[i];
  double E = 0;
  vector<double> pw(N, 1);
  set<pair<double, int> > S;
  for (int i = 0; i < N; i++) S.insert(make_pair(0, i));
  double Pt = 1;
  for (int k = 1; k <= 1000000; k++) {
    int x = S.begin()->second;
    S.erase(S.begin());
    if (pw[x] < 0.9999) Pt /= (1 - pw[x]);
    if (k >= N) {
      double Pc = Pt * pw[x] * P[x] / 100.0;
      E += k * Pc;
    }
    pw[x] *= (1 - P[x] / 100.0);
    Pt *= 1 - pw[x];
    S.insert(make_pair((1 / pw[x] - 1) / P[x], x));
  }
  cout << E << "\n";
  return 0;
}
