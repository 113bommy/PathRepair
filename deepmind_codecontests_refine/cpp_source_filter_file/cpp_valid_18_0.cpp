#include <bits/stdc++.h>
using namespace std;
int n, k, t, a, b, libres, inter;
int conectado[105];
int necesidad[105];
void unir(int a, int b) {
  conectado[a] = b;
  conectado[b] = a;
  for (int i = a + 1; i < b; i++) {
    if (conectado[i] != 0) {
      if (conectado[i] > b or conectado[i] < a) {
        inter++;
      }
    }
  }
}
void reset() {
  for (int i = 1; i <= 2 * n; i++) {
    necesidad[i] = false;
    conectado[i] = 0;
  }
  libres = 0;
  inter = 0;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> t;
  while (t--) {
    cin >> n >> k;
    libres = 2 * n;
    for (int i = 1; i <= k; i++) {
      cin >> a >> b;
      necesidad[a] = b;
      necesidad[b] = a;
      libres -= 2;
    }
    for (int i = 1; i <= 2 * n; i++) {
      if (necesidad[i] > i) {
        unir(i, necesidad[i]);
      }
    }
    for (int i = 1; i <= 2 * n; i++) {
      if (conectado[i] == 0) {
        if (libres > 0) {
          int fin = libres / 2;
          int ini = 0;
          for (int j = i + 1; j <= 2 * n; j++) {
            if (conectado[j] == 0) {
              if (ini == fin - 1) {
                unir(i, j);
                libres -= 2;
                break;
              } else {
                ini++;
              }
            }
          }
        }
      }
    }
    cout << inter << '\n';
    reset();
  }
}
