#include <bits/stdc++.h>
using namespace std;
double entrada[4];
int main() {
  double qi, tiempo;
  for (int i = 0; i < 4; i++) {
    cin >> entrada[i];
  }
  qi = (3.14159 * entrada[0] * entrada[0] * entrada[3]) / 4;
  if (entrada[2] <= qi) {
    cout << "NO" << endl;
  } else {
    tiempo = (3.14159 * entrada[0] * entrada[0] * entrada[1]) /
             (4 * (-qi + entrada[2]));
    cout << "YES" << endl;
    printf("%.10f\n", tiempo);
  }
}
