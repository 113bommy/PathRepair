#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200000;
bool active[MAXN + 10];
int v[MAXN + 10];
vector<int> factors[MAXN + 10];
int cantidad[5000001];
int main() {
  int n, q;
  scanf("%d %d", &n, &q);
  for (int i = 0; i < n; i++) {
    scanf("%d", &v[i]);
    int aux = v[i];
    for (int j = 2; j * j <= aux; j++) {
      if (aux % j == 0) {
        factors[i].push_back(j);
        while (aux % j == 0) aux /= j;
      }
    }
    if (aux > 1) factors[i].push_back(aux);
  }
  long long bad = 0;
  int cnt = 0, ones = 0;
  for (int i = 0; i < q; i++) {
    int x;
    scanf("%d", &x);
    x--;
    if (active[x]) {
      if (v[x] == 1) {
        ones--;
      } else {
        cnt--;
        int sz = factors[x].size();
        for (int j = 1; j < (1 << sz); j++) {
          int counter = 0;
          int product = 1;
          for (int k = 0; k < sz; k++) {
            if (j & (1 << k)) {
              counter++;
              product = product * factors[x][k];
            }
          }
          cantidad[product]--;
          if (counter & 1)
            bad -= cantidad[product];
          else
            bad += cantidad[product];
        }
      }
    } else {
      if (v[x] == 1)
        ones++;
      else {
        cnt++;
        int sz = (int)factors[x].size();
        for (int j = 1; j < (1 << sz); j++) {
          int counter = 0;
          int product = 1;
          for (int k = 0; k < sz; k++) {
            if (j & (1 << k)) {
              counter++;
              product = product * factors[x][k];
            }
          }
          if (counter & 1)
            bad += cantidad[product];
          else
            bad -= cantidad[product];
          cantidad[product]++;
        }
      }
    }
    active[x] = !active[x];
    printf("%lld\n", (1LL * cnt * (cnt - 1) / 2) - bad + (1LL * cnt * ones) +
                         1LL * ones * (ones - 1) / 2);
  }
  return 0;
}
