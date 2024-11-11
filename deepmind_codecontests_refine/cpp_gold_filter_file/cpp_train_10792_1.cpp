#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  long long reverse, change;
  cin >> n >> reverse >> change;
  char anterior;
  int cantCeros = 0;
  string auxString;
  cin >> auxString;
  if (auxString[0] == '0') cantCeros++;
  anterior = auxString[0];
  for (int i = int(1); i < int(n); i++) {
    if (auxString[i] != anterior) {
      anterior = auxString[i];
      if (auxString[i] == '0') cantCeros++;
    }
  }
  if (cantCeros == 0) {
    cout << 0 << endl;
    return 0;
  }
  if (reverse < change) {
    cout << ((long long)cantCeros - 1) * reverse + change << endl;
  } else {
    cout << (long long)cantCeros * change << endl;
  }
  return 0;
}
