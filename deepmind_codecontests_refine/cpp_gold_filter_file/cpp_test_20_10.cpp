#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
const int N = 4e2 + 99;
const int A = 5;
const int B = 4;
int pref[N][N], t[N][N];
int n, m;
deque<pair<int, int>> q;
int ans = INF;
void dodaj(int i, int j, int z) {
  int suma = (pref[j - 1][z - 1] - pref[i][z - 1]);
  suma += (j - i - 1 -
           (pref[j - 1][z] - pref[i][z] - pref[j - 1][z - 1] + pref[i][z - 1]));
  suma += (z - 1 - (pref[j][z - 1] - pref[j - 1][z - 1]));
  suma += (z - 1 - (pref[i][z - 1] - pref[i - 1][z - 1]));
  while (!q.empty() && q.back().second >= suma) q.pop_back();
  q.push_back({z, suma});
}
void usun(int z) {
  while (!q.empty() && q.front().first < z + B) q.pop_front();
}
int licz(int i, int j, int z) {
  int suma = q.front().second;
  suma -= (pref[j - 1][z] - pref[i][z]);
  suma -= (z - (pref[i][z] - pref[i - 1][z]));
  suma -= (z - (pref[j][z] - pref[j - 1][z]));
  suma += (j - i - 1 -
           (pref[j - 1][z] - pref[i][z] - pref[j - 1][z - 1] + pref[i][z - 1]));
  return suma;
}
void solve() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      char c;
      cin >> c;
      t[i][j] = (c == '1');
      pref[i][j] =
          pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1] + t[i][j];
    }
  }
  for (int i = 1; i <= n - A + 1; i++) {
    for (int j = i + A - 1; j <= n; j++) {
      q.clear();
      for (int z = B; z <= m; z++) {
        dodaj(i, j, z);
      }
      for (int z = 1; z <= m - B + 1; z++) {
        ans = min(ans, licz(i, j, z));
        usun(z);
      }
    }
  }
  cout << ans << "\n";
  ans = INF;
}
int main() {
  int Q;
  cin >> Q;
  while (Q--) solve();
}
