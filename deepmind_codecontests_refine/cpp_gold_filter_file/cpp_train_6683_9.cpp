#include <bits/stdc++.h>
using namespace std;
vector<long long> elemek, sor, sorvissza;
int main() {
  long long a, b, osszeg = 0, mo = 0;
  cin >> a >> b;
  elemek.resize(a);
  for (int i = 0; i < a; i++) cin >> elemek[i];
  sort(elemek.begin(), elemek.end());
  for (int i = 0; i < a / 2; i++) {
    sor.push_back(elemek[i + 1] - elemek[i] + elemek[a - 1 - i] -
                  elemek[a - 2 - i]);
  }
  if (a % 2 == 0) sor[a / 2 - 1] -= elemek[a / 2] - elemek[a / 2 - 1];
  for (int i = 0; i < a / 2; i++) {
    if (osszeg + sor[i] * (i + 1) > b) {
      cout << elemek[a - 1] - elemek[0] - (mo + (b - osszeg) / (i + 1));
      return 0;
    }
    osszeg += sor[i] * (i + 1);
    mo += sor[i];
  }
  cout << 0;
  return 0;
}
