#include <bits/stdc++.h>
using namespace std;
int main() {
  vector<int> vec(200001, INT_MIN);
  int q;
  int izq = -1, der = 1;
  char c;
  int aux, resp;
  scanf("%d", &q);
  scanf(" %c %d", &c, &aux);
  vec.at(aux) = 0;
  q--;
  while (q--) {
    scanf(" %c %d", &c, &aux);
    if (c == 'L') {
      vec.at(aux) = izq;
      izq--;
    } else if (c == 'R') {
      vec.at(aux) = der;
      der++;
    } else {
      resp = min(der - 1 - vec.at(aux), abs(izq + 1 + vec.at(aux)));
      printf("%d\n", resp);
    }
  }
  return 0;
}
