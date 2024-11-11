#include <bits/stdc++.h>
using namespace std;
const int N = 50;
int n, k;
int v[7][N + 5];
int aux[7][N + 5];
struct info {
  int a, b, c;
};
vector<info> sl;
vector<pair<int, int> > poz;
void build() {
  for (int j = 1; j <= n; j++) poz.push_back(make_pair(2, j));
  for (int j = n; j >= 1; j--) poz.push_back(make_pair(3, j));
}
void roteste() {
  int p_gol = 0;
  for (int i = 0; i < 2 * n; i++) {
    if (v[poz[i].first][poz[i].second] == 0) {
      p_gol = i;
      break;
    }
  }
  for (int i = 2 * n; i > 0; i--) {
    int unde = p_gol + i + 2 * n;
    int ant = p_gol + i - 1 + 2 * n;
    unde %= (2 * n);
    ant %= (2 * n);
    aux[poz[unde].first][poz[unde].second] = v[poz[ant].first][poz[ant].second];
    if (aux[poz[unde].first][poz[unde].second]) {
      sl.push_back({aux[poz[unde].first][poz[unde].second], poz[unde].first,
                    poz[unde].second});
    }
  }
  for (int i = 2; i <= 3; i++)
    for (int j = 1; j <= n; j++) v[i][j] = aux[i][j];
}
void unite() {
  for (int j = 1; j <= n; j++)
    if (v[1][j] == v[2][j] && v[2][j]) {
      sl.push_back({v[2][j], 1, j});
      v[2][j] = 0;
      k--;
    }
  for (int j = 1; j <= n; j++)
    if (v[3][j] == v[4][j] && v[3][j]) {
      sl.push_back({v[3][j], 4, j});
      v[3][j] = 0;
      k--;
    }
}
int main() {
  cin >> n >> k;
  build();
  for (int i = 1; i <= 4; i++)
    for (int j = 1; j <= n; j++) cin >> v[i][j];
  for (int i = 1; i <= 2 * n; i++) {
    unite();
    if (k == 2 * n || k == 0) break;
    roteste();
  }
  if (k)
    cout << "-1\n";
  else {
    cout << sl.size() << "\n";
    for (auto itr : sl) {
      cout << itr.a << " " << itr.b << " " << itr.c << "\n";
    }
  }
  return 0;
}
