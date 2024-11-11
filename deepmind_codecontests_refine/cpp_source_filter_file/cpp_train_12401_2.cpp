#include <bits/stdc++.h>
using namespace std;
const int M = 1e6 + 7;
const long long q = 7057594037927903;
const long long prime = 2137;
int n, c, pref[M], wynik, pom, a, akt;
vector<int> v[M];
void wczytaj() {
  scanf("%d%d", &n, &c);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a);
    v[a].push_back(i);
    pref[i] += pref[i - 1];
    if (a == c) pref[i]++;
  }
}
int main() {
  wczytaj();
  for (int i = 1; i <= 500007; i++) {
    pom = 0;
    akt = 0;
    for (int j = 0; j < (int)v[i].size(); j++) {
      wynik = max(wynik,
                  j + 1 - akt + pref[v[i][akt] - 1] + pref[n] - pref[v[i][j]]);
      if (pom > j + 1 - (pref[v[i][j]] - pref[v[i][0] - 1])) {
        pom = min(pom, j + 1 - (pref[v[i][j]] - pref[v[i][0] - 1]));
        akt = j;
      }
    }
  }
  printf("%d\n", wynik);
  return 0;
}
