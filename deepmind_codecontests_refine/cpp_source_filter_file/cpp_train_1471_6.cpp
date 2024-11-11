#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000000;
int n;
int x[300010];
int y[300010];
pair<int, int> izq, der, down, up;
int ereccion(int i, int j, int k) {
  vector<int> pito, ura;
  pito.push_back(x[i]);
  pito.push_back(x[j]);
  pito.push_back(x[k]);
  ura.push_back(y[i]);
  ura.push_back(y[j]);
  ura.push_back(y[k]);
  sort(pito.begin(), pito.end());
  sort(ura.begin(), ura.end());
  return pito.back() - pito[0] + ura.back() - ura[0];
}
int triangulo() {
  set<int> pingo;
  pingo.insert(der.second);
  pingo.insert(izq.second);
  pingo.insert(up.second);
  pingo.insert(down.second);
  if (pingo.size() != 4) {
    return 2 * (der.first - izq.first) + 2 * (up.first - down.first);
  }
  vector<int> concha;
  for (auto pito : pingo) {
    concha.push_back(pito);
  }
  int ans = -1;
  for (int i = 0; i < 4; i++) {
    for (int j = i + 1; j < 4; j++) {
      int u = concha[i];
      int v = concha[j];
      for (int k = 0; k < n; k++) {
        if (k != u && k != v) {
          ans = max(ans, ereccion(i, j, k));
        }
      }
    }
  }
  return 2 * ans;
}
int main() {
  scanf("%d", &n);
  izq = make_pair(INF, 0);
  down = make_pair(INF, 0);
  der = make_pair(-INF, 0);
  up = make_pair(-INF, 0);
  for (int i = 0; i < n; i++) {
    scanf("%d %d", &x[i], &y[i]);
    down = min(down, make_pair(y[i], i));
    up = max(up, make_pair(y[i], i));
    der = max(der, make_pair(x[i], i));
    izq = min(izq, make_pair(x[i], i));
  }
  printf("%d ", triangulo());
  int anss = 2 * (der.first - izq.first) + 2 * (up.first - down.first);
  for (int i = 4; i <= n; i++) {
    printf("%d ", anss);
  }
  puts("");
  return 0;
}
