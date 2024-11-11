#include <bits/stdc++.h>
using namespace std;
long long int infinito = 1000000000LL * 1000000000LL;
int cuantos[2000000];
long long int suma[2000000];
int primero, tope;
long long int valorsiguiente(int pos) {
  pos += primero;
  if (cuantos[pos] == 1) return suma[pos];
  while (cuantos[pos + 1] == 0) pos /= 2;
  pos++;
  while (pos < primero)
    if (cuantos[2 * pos])
      pos *= 2;
    else
      pos = 2 * pos + 1;
  return suma[pos];
}
void anyadir(int pos, long long int val, int c) {
  pos += primero;
  suma[pos] = val;
  cuantos[pos] = c;
  while (pos > 1) {
    pos /= 2;
    suma[pos] = suma[2 * pos] + suma[2 * pos + 1];
    cuantos[pos] = cuantos[2 * pos] + cuantos[2 * pos + 1];
  }
}
long long int cuantosantes(int pos) {
  pos += primero;
  long long int c = 0;
  while (pos > 1) {
    if (pos % 2 == 1) c += cuantos[pos - 1];
    pos /= 2;
  }
  return c;
}
long long int sumaantes(int pos) {
  pos += primero;
  long long int s = 0;
  while (pos > 1) {
    if (pos % 2 == 1) s += suma[pos - 1];
    pos /= 2;
  }
  return s;
}
int n, q;
struct accion {
  int t;
  int pos;
  long long int valor;
  accion() {}
  accion(int intt, int inpos, long long int invalor) {
    t = intt;
    pos = inpos;
    valor = invalor;
  }
};
long long int posactual[1000000];
vector<long long int> valores;
map<long long int, vector<int> > donde;
int main() {
  cout.setf(ios::fixed);
  cout.precision(10);
  cin >> n >> q;
  vector<accion> v;
  v.push_back(accion(1, 0, infinito));
  valores.push_back(v.back().valor);
  for (int i = 1; i <= n; i++) {
    long long int valor;
    cin >> valor;
    v.push_back(accion(1, i, valor));
    valores.push_back(valor);
  }
  for (int i = 0; i < q; i++) {
    int t;
    cin >> t;
    if (t == 1) {
      long long int p, x;
      cin >> p >> x;
      v.push_back(accion(0, p, -1));
      v.push_back(accion(1, p, x));
      valores.push_back(x);
    } else {
      long long int valor;
      cin >> valor;
      v.push_back(accion(2, -1, valor));
    }
  }
  sort(valores.begin(), valores.end());
  for (int i = 0; i < int(valores.size()); i++) donde[valores[i]].push_back(i);
  for (int i = 0; i < int(v.size()); i++) {
    accion &a = v[i];
    if (a.t == 1) {
      int posicion = donde[a.valor].back();
      donde[a.valor].pop_back();
      posactual[a.pos] = posicion;
      a.pos = posicion;
    } else if (a.t == 0) {
      a.pos = posactual[a.pos];
    }
  }
  int nn = int(valores.size());
  primero = 1;
  while (nn > 0) {
    nn /= 2;
    primero *= 2;
  }
  tope = 2 * primero;
  for (int i = 0; i < int(v.size()); i++) {
    accion &a = v[i];
    if (a.t == 0) {
      anyadir(a.pos, 0, 0);
    } else if (a.t == 1) {
      anyadir(a.pos, a.valor, 1);
    } else {
      int inf = 0;
      int sup = int(valores.size()) - 1;
      double sol = double(suma[1] - infinito + a.valor) / (cuantos[1] - 1);
      while (inf + 1 < sup) {
        int med = (inf + sup) / 2;
        long long int c = cuantosantes(med);
        long long int s = sumaantes(med);
        long long int val = valorsiguiente(med);
        if (s + a.valor <= c * val) {
          sup = med;
          sol = double(s + a.valor) / c;
        } else {
          inf = med;
        }
      }
      cout << sol << endl;
    }
  }
}
