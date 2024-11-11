#include <bits/stdc++.h>
using namespace std;
int n, x;
long double P[105];
long double Pmiss[105][100005];
long double Pmcur, Phcur;
int guess[105];
long double E;
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> x;
    P[i] = x / 100.0;
  }
  for (int i = 1; i <= n; i++) {
    Pmiss[i][1] = 1 - P[i];
    for (int j = 2; j <= 100000; j += 2) {
      Pmiss[i][j] = Pmiss[i][j / 2] * Pmiss[i][j / 2];
      Pmiss[i][j + 1] = Pmiss[i][j] * Pmiss[i][1];
    }
  }
  E = n * 1.0;
  Phcur = 1.0;
  for (int i = 1; i <= n; i++) {
    guess[i] = 1;
    Phcur *= P[i];
  }
  int cur = 0;
  while (true) {
    E += (1 - Phcur);
    int next = 1;
    for (int i = 2; i <= n; i++) {
      if ((1 - Pmiss[i][guess[i] + 1]) / (1 - Pmiss[i][guess[i]]) >
          (1 - Pmiss[next][guess[next] + 1]) / (1 - Pmiss[next][guess[next]]))
        next = i;
    }
    guess[next]++;
    if (next >= 100000) break;
    cur++;
    if (cur > n * 1000) break;
    Phcur = 1.0;
    for (int i = 1; i <= n; i++) Phcur *= (1 - Pmiss[i][guess[i]]);
  }
  for (int i = 1; i <= n; i++) E += Pmiss[i][guess[i]] / P[i];
  cout << (fixed) << setprecision(9) << E;
}
