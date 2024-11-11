#include <bits/stdc++.h>
using namespace std;
int main() {
  int n_trees, k_factor;
  while (cin >> n_trees >> k_factor) {
    int model;
    int high[n_trees];
    for (int i = 0; i < n_trees; i++) {
      cin >> high[i];
    }
    int menor = 10000;
    int indice = -1;
    for (int i = 0; i < n_trees; i++) {
      int base = high[i] - i * k_factor;
      int cambio = 0;
      if (base == 0) continue;
      for (int j = 0; j < n_trees; j++) {
        if (high[j] != base) cambio++;
        base += k_factor;
      }
      if (cambio < menor) {
        menor = cambio;
        indice = i;
      }
    }
    cout << menor << endl;
    int base = high[indice] - indice * k_factor;
    for (int i = 0; i < n_trees; i++) {
      if (base != high[i]) {
        int res = base - high[i];
        if (res >= 0)
          cout << "+ ";
        else
          cout << "- ";
        printf("%d %d \n", i + 1, abs(res));
      }
      base += k_factor;
    }
  }
}
