#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100000;
int a[MAXN + 2];
int d[MAXN + 2];
int N;
set<int> solucion;
int agrega(int D, int& tam, vector<int>& valores, vector<int>& rep) {
  bool encontrado = false;
  for (int i = 0; i < tam; i++) {
    if (valores[i] == D) {
      encontrado = true;
      rep[i]++;
    }
  }
  if (!encontrado) {
    tam++;
    valores.push_back(D);
    rep.push_back(1);
  }
  return (encontrado) ? 0 : 1;
}
void genera_solucion() {
  vector<int> valores;
  vector<int> repeticiones;
  vector<int> pos;
  int cuantos = 0;
  for (int i = 1; i < N; i++) {
    int aux = agrega(d[i], cuantos, valores, repeticiones);
    if (aux == 1) pos.push_back(i);
    if (cuantos > 2) return;
  }
  if (cuantos == 1) {
    solucion.insert(a[1] - d[1]);
    solucion.insert(a[N] + d[1]);
  } else if (repeticiones[0] == 1 || repeticiones[1] == 1) {
    if (valores[0] < valores[1]) {
      swap(valores[0], valores[1]);
      swap(repeticiones[0], repeticiones[1]);
      swap(pos[0], pos[1]);
    }
    if (repeticiones[0] != 1 && valores[0] % 2 != 0) return;
    if (valores[0] / 2 == valores[1]) {
      int p = pos[0];
      solucion.insert(a[p] + valores[0] / 2);
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;
  for (int i = 1; i <= N; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + N + 1);
  for (int i = 1; i < N; i++) {
    d[i] = a[i + 1] - a[i];
  }
  if (N == 1) {
    cout << "-1\n";
    return 0;
  }
  if (N == 2) {
    solucion.insert(a[1] - d[1]);
    if (d[1] % 2 == 0) solucion.insert(a[1] + (d[1] / 2));
    solucion.insert(a[2] + d[1]);
  } else {
    genera_solucion();
  }
  int resp = solucion.size();
  cout << resp << "\n";
  for (set<int>::iterator it = solucion.begin(); it != solucion.end(); it++) {
    cout << *it << " ";
  }
  if (resp > 0) cout << "\n";
  return 0;
}
