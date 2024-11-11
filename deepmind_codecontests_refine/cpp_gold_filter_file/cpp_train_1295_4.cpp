#include <bits/stdc++.h>
using namespace std;
int cantidad[20], sum, sumatotal, bitstomados, nes, inicial[20];
int bit;
int limit;
int main() {
  int potencia = 0;
  cin >> sum >> limit;
  bit = sum;
  potencia = limit;
  for (int i = 1; potencia > 0; i++) {
    cantidad[i] = (potencia + 1) >> 1;
    inicial[i] = cantidad[i];
    potencia = potencia >> 1;
  }
  for (int i = 1; bit > 0; i++) {
    cantidad[i] += cantidad[i - 1] >> 1;
    cantidad[i - 1] = cantidad[i - 1] & 1;
    if (bit & 1) {
      if (cantidad[i] == 0) {
        cout << -1;
        return 0;
      }
      cantidad[i]--;
    }
    bit = bit >> 1;
    bitstomados++;
  }
  for (int i = bitstomados; i > 0; i--) {
    if (cantidad[i] > inicial[i]) {
      cantidad[i - 1] += (cantidad[i] - inicial[i]) << 1;
      cantidad[i] = inicial[i];
    }
    nes += inicial[i] - cantidad[i];
  }
  cout << nes << '\n';
  for (int i = 1; i <= bitstomados; i++) {
    if (inicial[i] > cantidad[i]) {
      for (int j = 1; j <= inicial[i] - cantidad[i]; j++) {
        cout << (((j << 1) - 1) << (i - 1)) << ' ';
      }
    }
  }
}
