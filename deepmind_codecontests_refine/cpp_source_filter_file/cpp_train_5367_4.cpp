#include <bits/stdc++.h>
using namespace std;
int main() {
  map<int, vector<pair<int, int>>> rutas;
  map<int, int> panaderias;
  int n;
  int m;
  int k;
  cin >> n >> m >> k;
  for (int i = 0; i < n; ++i) {
    vector<pair<int, int>> aux;
    rutas[i + 1] = aux;
    panaderias[i + 1] = 0;
  }
  if (k >= n || k == 0) {
    cout << -1;
    return 0;
  }
  for (int i = 0; i < m; ++i) {
    int c1;
    int c2;
    int peso;
    cin >> c1 >> c2 >> peso;
    rutas[c1].push_back(make_pair(c2, peso));
    rutas[c2].push_back(make_pair(c1, peso));
  }
  for (int i = 0; i < k; ++i) {
    int c;
    cin >> c;
    panaderias[c] = 1;
  }
  int menor = -1;
  for (int i = 0; i < n; ++i) {
    if (panaderias[i + 1] == 1) {
      for (auto it : rutas[i + 1]) {
        int aux = it.second;
        if (aux < menor || menor == -1 && panaderias[it.first] == 0) {
          menor = aux;
        }
      }
    }
  }
  cout << menor;
  return 0;
}
