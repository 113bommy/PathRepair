#include <bits/stdc++.h>
using namespace std;
int n;
int b[300000];
int indice[300000];
bool compara(int i1, int i2) { return b[i1] < b[i2]; }
const int primero = 1 << 19;
const int tope = 1 << 20;
int cuantos[tope];
double sumari[tope], sumale[tope];
double expo[300000];
void inserta(int pos, int val) {
  pos += primero;
  if (val == 0) {
    cuantos[pos] = 0;
    sumale[pos] = sumari[pos] = 1.0;
  } else {
    cuantos[pos] = 1;
    sumale[pos] = sumari[pos] = 1 / 2.0;
  }
  while (pos > 1) {
    pos /= 2;
    cuantos[pos] = cuantos[2 * pos] + cuantos[2 * pos + 1];
    sumale[pos] =
        sumale[2 * pos + 1] + sumale[2 * pos] * expo[cuantos[2 * pos + 1]];
    sumari[pos] =
        sumari[2 * pos] + sumari[2 * pos + 1] * expo[cuantos[2 * pos]];
  }
}
double acumri(int pos) {
  pos += primero;
  double s = 0;
  int c = cuantos[pos];
  while (pos > 1) {
    if (pos % 2 == 0) {
      s += expo[c] * sumari[pos + 1];
      c += cuantos[pos + 1];
    }
    pos /= 2;
  }
  return s;
}
double acumle(int pos) {
  pos += primero;
  double s = 0;
  int c = cuantos[pos];
  while (pos > 1) {
    if (pos % 2 == 1) {
      s += expo[c] * sumale[pos - 1];
      c += cuantos[pos - 1];
    }
    pos /= 2;
  }
  return s;
}
double acum(int pos) {
  return (1.0 + acumle(pos) * 2.0) * (1 / 2.0 + acumri(pos)) * b[pos];
}
int main() {
  ios::sync_with_stdio(false);
  cout.setf(ios::fixed);
  cout.precision(15);
  expo[0] = 1;
  for (int i = 1; i < 300000; i++) expo[i] = expo[i - 1] / 2.0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> b[i];
    indice[i] = i;
    inserta(i, b[i]);
  }
  sort(indice, indice + n, compara);
  double s = 0;
  for (int k = 0; k < n; k++) {
    int i = indice[k];
    s += acum(i);
    inserta(i, 0);
  }
  cout << s / n / n << endl;
}
