#include <bits/stdc++.h>
using namespace std;
struct posicao {
  int x, y;
};
int cmp(posicao a, posicao b) {
  if (a.x != b.x) return a.x < b.x;
  return a.y < b.y;
}
int main() {
  string resp;
  int t, n, vale, antx, anty;
  posicao vet[1001];
  cin >> t;
  for (int i = 0; i < t; ++i) {
    resp = "";
    cin >> n;
    for (int j = 0; j < n; ++j) {
      cin >> vet[j].x >> vet[j].y;
    }
    sort(vet, vet + n, cmp);
    antx = vet[0].x;
    anty = vet[0].y;
    vale = 1;
    for (int j = 1; j < n; ++j) {
      if (antx <= vet[j].x && anty <= vet[j].y) {
        antx = vet[j].x;
        anty = vet[j].y;
      } else
        vale = 0;
    }
    if (vale) {
      cout << "YES" << endl;
      antx = 0;
      anty = 0;
      for (int j = 0; j < n; ++j) {
        antx = vet[j].x - antx;
        anty = vet[j].y - anty;
        for (int k = 0; k < antx; ++k) {
          resp = resp + 'R';
        }
        for (int k = 0; k < anty; ++k) {
          resp = resp + 'U';
        }
        antx = vet[j].x;
        anty = vet[j].y;
      }
      cout << resp << endl;
    } else
      cout << "NO" << endl;
  }
  return 0;
}
