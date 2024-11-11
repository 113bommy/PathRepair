#include <bits/stdc++.h>
using namespace std;
struct elem {
  int i, j, c;
  elem() {}
  elem(int ini, int inj, int inc) {
    i = ini;
    j = inj;
    c = inc;
  }
};
int absolut(int a) {
  if (a < 0) return -a;
  return a;
}
int ibase, jbase;
int pasoshasta(int i, int j) {
  i = i - ibase;
  j = j - jbase;
  if (i == 0 and j == 0) return 1;
  int base = 2 * max(absolut(i), absolut(j)) - 1;
  int pasos = base * base;
  if (absolut(i) > absolut(j)) {
    if (i > 0)
      return pasos + 1 + i - 1 + i + i + i + i - j;
    else
      return pasos + 1 + j + ((-i) - 1);
  }
  if (j > 0) return pasos + 1 + j - 1 + j + j + i;
  return pasos + 1 + (-j) - 1 + 5 * (-j) - j - i;
}
bool compara(elem e1, elem e2) {
  return pasoshasta(e1.i, e1.j) < pasoshasta(e2.i, e2.j);
}
int main() {
  map<int, int> cambio;
  cambio[-1] = 0;
  cambio[0] = 0;
  int n, m;
  cin >> n >> m;
  vector<vector<int> > t(n, vector<int>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> t[i][j];
      cambio[t[i][j]] = 0;
    }
  }
  vector<vector<int> > g(n, vector<int>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> g[i][j];
      cambio[g[i][j]] = 0;
    }
  }
  int iini, jini;
  cin >> iini >> jini;
  iini--;
  jini--;
  int cc = -1;
  for (map<int, int>::iterator it = cambio.begin(); it != cambio.end(); it++)
    it->second = cc++;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      t[i][j] = cambio[t[i][j]];
      g[i][j] = cambio[g[i][j]];
    }
  }
  vector<int> pare(cc, -1);
  vector<int> color(cc);
  vector<int> cuantos(cc, 0);
  vector<int> donde(cc);
  for (int i = 0; i < cc; i++) color[i] = donde[i] = i;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) cuantos[t[i][j]]++;
  vector<vector<elem> > elementos(cc);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (g[i][j] != -1 and i != iini and j != jini)
        elementos[t[i][j]].push_back(elem(i, j, g[i][j]));
  vector<int> usado(cc, 0);
  queue<elem> q;
  q.push(elem(iini, jini, g[iini][jini]));
  long long int amount = 0;
  while (not q.empty()) {
    elem e = q.front();
    q.pop();
    ibase = e.i;
    jbase = e.j;
    int c = e.c;
    int ct = t[ibase][jbase];
    while (pare[ct] >= 0) ct = pare[ct];
    int col = color[ct];
    if (col != 0 and col != c) {
      if (not usado[col]) {
        usado[col] = 1;
        vector<elem> &ele = elementos[col];
        sort(ele.begin(), ele.end(), compara);
        for (int k = 0; k < int(ele.size()); k++) q.push(ele[k]);
      }
      amount += cuantos[ct];
      int dondec = donde[c];
      if (dondec == -1) {
        color[ct] = c;
        donde[c] = ct;
      } else {
        if (pare[ct] < pare[dondec]) {
          pare[ct] += pare[dondec];
          pare[dondec] = ct;
          cuantos[ct] += cuantos[dondec];
          color[ct] = c;
          donde[c] = ct;
        } else {
          pare[dondec] += pare[ct];
          pare[ct] = dondec;
          cuantos[dondec] += cuantos[ct];
        }
      }
      donde[col] = -1;
    }
  }
  cout << amount << endl;
}
