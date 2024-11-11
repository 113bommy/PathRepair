#include <bits/stdc++.h>
using namespace std;
int N, M;
long long contadores[255];
char entrada[100003];
int i;
long long cantidad;
int main() {
  gets(entrada);
  i = 0;
  memset(contadores, 0, sizeof(contadores));
  while (entrada[i] != '\0') {
    ++contadores[entrada[i]];
    ++i;
  }
  cantidad = 0;
  for (i = 0; i < 255; ++i) {
    cantidad += contadores[i] * contadores[i];
  }
  cout << cantidad << endl;
}
