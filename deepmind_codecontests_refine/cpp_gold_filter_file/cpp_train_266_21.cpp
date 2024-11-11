#include <bits/stdc++.h>
using namespace std;
void cuantospasos(vector<int> &a, int posini, vector<int> &d, int n,
                  vector<int> &indice0, vector<int> &indice1) {
  if (indice0[posini] != -1) d[indice0[posini]] = 0;
  if (indice1[posini] != -1) d[indice1[posini]] = 0;
  vector<int> v;
  vector<int> visitado(n + 1, 0);
  v.push_back(posini);
  visitado[posini] = 1;
  int pasos = 0;
  while (not v.empty()) {
    pasos++;
    vector<int> nextv;
    for (int i = 0; i < int(v.size()); i++) {
      int pos = v[i];
      for (int j = 0; j < int(a.size()); j++) {
        int len = a[j];
        if (pos - len >= 0 and visitado[pos - len] == 0) {
          int nextpos = pos - len;
          if (indice0[nextpos] != -1) d[indice0[nextpos]] = pasos;
          if (indice1[nextpos] != -1) d[indice1[nextpos]] = pasos;
          visitado[nextpos] = 1;
          nextv.push_back(nextpos);
        }
        if (pos + len < n + 1 and visitado[pos + len] == 0) {
          int nextpos = pos + len;
          if (indice0[nextpos] != -1) d[indice0[nextpos]] = pasos;
          if (indice1[nextpos] != -1) d[indice1[nextpos]] = pasos;
          visitado[nextpos] = 1;
          nextv.push_back(nextpos);
        }
      }
    }
    v = nextv;
  }
}
int main() {
  int n, k, l;
  cin >> n >> k >> l;
  vector<int> indice0(n + 1, -1);
  vector<int> indice1(n + 1, -1);
  vector<int> posuno(k);
  for (int i = 0; i < k; i++) {
    cin >> posuno[i];
    posuno[i]--;
    indice0[posuno[i]] = i;
    indice1[posuno[i] + 1] = i + k;
  }
  vector<int> a(l);
  for (int i = 0; i < l; i++) cin >> a[i];
  vector<vector<int> > d(2 * k, vector<int>(2 * k, 100000000));
  for (int i = 0; i < k; i++) {
    cuantospasos(a, posuno[i], d[i], n, indice0, indice1);
    cuantospasos(a, posuno[i] + 1, d[i + k], n, indice0, indice1);
  }
  vector<vector<int> > cuantos(1 << k, vector<int>(2 * k, 100000000));
  vector<int> lenciclo(1 << k);
  for (int c = 1; c < (1 << k); c++) {
    int bit = k - 1;
    while (((1 << bit) & c) == 0) bit--;
    for (int b = 0; b <= bit; b++) {
      if (((1 << b) & c) == 0 or b == bit) {
        for (int lado = 0; lado < 2; lado++) {
          if (c - (1 << bit) == 0) {
            cuantos[c][k * lado + b] = d[k * lado + b][k + bit];
          } else {
            for (int bb = 0; bb < bit; bb++) {
              if ((1 << bb) & c) {
                cuantos[c][k * lado + b] =
                    min(cuantos[c][k * lado + b],
                        d[k * lado + b][bb] + cuantos[c - (1 << bb)][k + bb]);
                cuantos[c][k * lado + b] =
                    min(cuantos[c][k * lado + b],
                        d[k * lado + b][k + bb] + cuantos[c - (1 << bb)][bb]);
              }
            }
          }
        }
      }
    }
    lenciclo[c] = cuantos[c][bit];
  }
  vector<int> coste(1 << k, 100000000);
  for (int c = 1; c < (1 << k); c++) {
    coste[c] = min(coste[c], lenciclo[c]);
    for (int subc = 1; subc < c; subc++)
      if ((c & subc) == subc)
        coste[c] = min(coste[c], coste[subc] + lenciclo[c - subc]);
  }
  if (coste[(1 << k) - 1] >= 100000000)
    cout << -1 << endl;
  else
    cout << coste[(1 << k) - 1] << endl;
}
