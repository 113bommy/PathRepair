#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
const long long INF = 1000000000;
struct wie {
  int il_50, il_100, str;
};
int main() {
  ios_base::sync_with_stdio(0);
  int n, k;
  cin >> n >> k;
  int p = 0, s = 0;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    if (x == 50)
      ++p;
    else
      ++s;
  }
  vector<vector<long long> > C(51, vector<long long>(51));
  for (int i = 0; i <= 50; ++i) {
    for (int j = 0; j <= i; ++j) {
      if (j == 0 || j == i)
        C[i][j] = 1;
      else
        C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
    }
  }
  long long il[51][51][2];
  long long odl[51][51][2];
  bool odw[51][51][2];
  for (int i = 0; i < 51; ++i) {
    for (int j = 0; j < 51; ++j) {
      for (int l = 0; l < 2; ++l) {
        odw[i][j][l] = false;
        odl[i][j][l] = -1;
      }
    }
  }
  queue<wie> Q;
  Q.push({p, s, 1});
  odw[p][s][1] = true;
  while (!Q.empty()) {
    wie akt = Q.front();
    Q.pop();
    if (akt.il_100 == s && akt.il_50 == p && akt.str == 1) {
      odl[akt.il_50][akt.il_100][akt.str] = 0;
      il[akt.il_50][akt.il_100][akt.str] = 1;
      for (int i = 0; i <= akt.il_50; ++i) {
        for (int j = 0; j <= akt.il_100; ++j) {
          wie nowy = {p - akt.il_50 + i, s - akt.il_100 + j, (akt.str ^ 1)};
          if (i + j != 0 && 50 * i + 100 * j <= k) {
            Q.push(nowy);
            odw[nowy.il_50][nowy.il_100][nowy.str] = true;
          }
        }
      }
    } else {
      odl[akt.il_50][akt.il_100][akt.str] = INF;
      il[akt.il_50][akt.il_100][akt.str] = 0;
      for (int i = 0; i <= akt.il_50; ++i) {
        for (int j = 0; j <= akt.il_100; ++j) {
          wie nowy = {p - akt.il_50 + i, s - akt.il_100 + j, (akt.str ^ 1)};
          if (i + j != 0 && 50 * i + 100 * j <= k) {
            if (odw[nowy.il_50][nowy.il_100][nowy.str]) {
              if (odl[nowy.il_50][nowy.il_100][nowy.str] != -1) {
                odl[akt.il_50][akt.il_100][akt.str] =
                    min(odl[akt.il_50][akt.il_100][akt.str],
                        odl[nowy.il_50][nowy.il_100][nowy.str] + 1);
                il[akt.il_50][akt.il_100][akt.str] =
                    (il[akt.il_50][akt.il_100][akt.str] +
                     C[akt.il_50][i] * C[akt.il_100][j] *
                         il[nowy.il_50][nowy.il_100][nowy.str]) %
                    MOD;
              }
            } else {
              Q.push(nowy);
              odw[nowy.il_50][nowy.il_100][nowy.str] = true;
            }
          }
        }
      }
    }
  }
  if (odw[p][s][0])
    cout << odl[p][s][0] << " " << il[p][s][0];
  else
    cout << "-1 0";
  return 0;
}
