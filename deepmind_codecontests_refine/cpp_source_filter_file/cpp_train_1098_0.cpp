#include <bits/stdc++.h>
using namespace std;
long long int modulo = 1e9 + 7;
void anyade(long long int &a, long long int b) { a = (a + b) % modulo; }
const int primero = 1 << 20;
const int tope = 1 << 21;
long long int manerasri[tope];
int haymaneras[tope];
int obstaculo[tope];
void propaga(int pos) {
  while (pos > 1) {
    pos /= 2;
    obstaculo[pos] = obstaculo[2 * pos] or obstaculo[2 * pos + 1];
    haymaneras[pos] = haymaneras[2 * pos] or haymaneras[2 * pos + 1];
    manerasri[pos] = manerasri[2 * pos + 1];
    if (not obstaculo[2 * pos + 1]) anyade(manerasri[pos], manerasri[2 * pos]);
  }
}
void ponmaneras(int pos, long long int val, int hay) {
  pos += primero;
  manerasri[pos] = val;
  haymaneras[pos] = hay;
  propaga(pos);
}
void ponobstaculo(int pos, int val) {
  pos += primero;
  obstaculo[pos] += val;
  propaga(pos);
}
void elimina(int pos, int pospeque) {
  pos += primero;
  pospeque += primero;
  if (haymaneras[pos]) ponmaneras(pos - primero, 0, 0);
  while (pos > 1) {
    if (pos % 2 == 1 and haymaneras[pos - 1]) {
      pos--;
      while (pos < primero)
        if (haymaneras[2 * pos + 1])
          pos = 2 * pos + 1;
        else
          pos = 2 * pos;
      if (pos < pospeque) return;
      ponmaneras(pos - primero, 0, 0);
    } else
      pos /= 2;
  }
}
long long int sumale(int pos) {
  pos += primero;
  if (obstaculo[pos]) {
    return 0;
  }
  long long int s = manerasri[pos];
  while (pos > 1) {
    if (pos % 2 == 1) {
      anyade(s, manerasri[pos - 1]);
      if (obstaculo[pos - 1]) {
        return s;
      }
    }
    pos /= 2;
  }
  return s;
}
struct elem {
  int i1, i2, j, enter;
  elem() {}
  elem(int i1, int i2, int j, int enter) : i1(i1), i2(i2), j(j), enter(enter) {}
};
bool operator<(elem e1, elem e2) {
  if (e1.j < e2.j) return true;
  if (e1.j > e2.j) return false;
  if (e1.enter and not e2.enter) return e2.i1 <= e1.i2 + 1;
  if (not e1.enter and e2.enter) return e1.i1 > e2.i2 + 1;
  return e1.i1 < e2.i1;
}
int n, m, k;
vector<elem> ve;
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> m >> k;
  for (int d = 0; d < k; d++) {
    int i1, j1, i2, j2;
    cin >> i1 >> j1 >> i2 >> j2;
    ve.push_back(elem(i1, i2, j1, 1));
    ve.push_back(elem(i1, i2, j2 + 1, 0));
  }
  sort(ve.begin(), ve.end());
  ponmaneras(1, 1, 1);
  int lasti = 0, lastj = 0;
  for (int d = 0; d < int(ve.size()) and ve[d].j <= m; d++) {
    elem &e = ve[d];
    int i1 = e.i1;
    int i2 = e.i2;
    int j = e.j;
    if (e.enter) {
      if (j == 1) {
        ponobstaculo(i1, 1);
      } else {
        if (not(lasti == i2 + 1 and lastj == j))
          ponmaneras(i2 + 1, sumale(i2 + 1), 1);
        elimina(i2, i1);
        ponobstaculo(i1, 1);
        lasti = i1;
        lastj = j;
      }
    } else {
      ponobstaculo(i1, -1);
    }
  }
  cout << sumale(n) << endl;
}
