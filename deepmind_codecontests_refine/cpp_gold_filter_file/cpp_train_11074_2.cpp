#include <bits/stdc++.h>
using namespace std;
bool compound[100030 + 1];
set<int> s;
unsigned long long int l, h;
int val, t;
void criba() {
  for (int i = 2; i < 100030; i++) {
    if (!compound[i]) {
      s.insert(i);
      val = i + i;
      while (val <= 100030) {
        compound[val] = true;
        val += i;
      }
    }
  }
}
int main() {
  criba();
  int h, w;
  scanf("%d %d", &h, &w);
  vector<vector<int>> m(h, vector<int>(w));
  for (int i = 0; i < h; i++)
    for (int j = 0; j < w; j++) scanf("%d", &m[i][j]);
  compound[1] = 1;
  compound[0] = 1;
  vector<vector<int>> mf(h, vector<int>(w, 0));
  for (int i = 0; i < h; i++)
    for (int j = 0; j < w; j++) {
      if (compound[m[i][j]]) mf[i][j] = *s.upper_bound(m[i][j]) - m[i][j];
    }
  vector<int> filas(h);
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      filas[i] += mf[i][j];
    }
  }
  vector<int> columnas(w);
  for (int j = 0; j < w; j++) {
    for (int i = 0; i < h; i++) {
      columnas[j] += mf[i][j];
    }
  }
  int minfil = filas[0];
  for (int i = 1; i < h; i++) minfil = min(minfil, filas[i]);
  int mincol = columnas[0];
  for (int i = 1; i < w; i++) mincol = min(mincol, columnas[i]);
  cout << min(minfil, mincol) << endl;
  return 0;
}
