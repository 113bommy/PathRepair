#include <bits/stdc++.h>
using namespace std;
int main() {
  int d;
  string s;
  cin >> d >> s;
  if (d == 1) {
    cout << "Impossible" << endl;
    exit(0);
  }
  vector<int> v;
  v.push_back(-1);
  for (int i = 0; i < int(s.size()); i++) {
    v.push_back(int(s[i]) - 'a');
    v.push_back(-1);
  }
  int cotapos, cotaneg;
  if (d % 2 == 1) {
    cotapos = d - 1;
    cotaneg = d;
  } else {
    cotapos = d;
    cotaneg = d - 1;
  }
  int n = int(v.size());
  vector<int> cota(n);
  for (int i = 0; i < n; i++)
    if (v[i] >= 0)
      cota[i] = cotapos;
    else
      cota[i] = cotaneg;
  vector<int> r(n);
  r[0] = 0;
  int imax = 0;
  for (int i = 1; i < n; i++) {
    if (imax + r[imax] > i) {
      if (i + r[imax - (i - imax)] < imax + r[imax]) {
        r[i] = r[imax - (i - imax)];
      } else {
        r[i] = imax + r[imax] - i;
        while (0 < i - r[i] and i + r[i] < n - 1 and
               v[i - r[i] - 1] == v[i + r[i] + 1])
          r[i]++;
        imax = i;
      }
    } else {
      r[i] = 0;
      while (0 < i - r[i] and i + r[i] < n - 1 and
             v[i - r[i] - 1] == v[i + r[i] + 1])
        r[i]++;
      imax = i;
    }
  }
  vector<int> anular(n, 0);
  vector<set<int> > prohibido(n);
  for (int i = 0; i < n; i++)
    if (cota[i] <= r[i])
      anular[i + r[i]] = 1;
    else if (cota[i] == r[i] + 1 and i - r[i] - 1 >= 0 and i + r[i] + 1 < n)
      prohibido[i + r[i] + 1].insert(v[i - r[i] - 1]);
  int index = 0;
  while (index < n and not anular[index]) index++;
  if (index == n) index--;
  int val;
  while (index >= 0) {
    if (v[index] < 0) {
      index--;
      continue;
    }
    val = v[index] + 1;
    while (prohibido[index].count(val) > 0) val++;
    if (val < 26) break;
    index--;
  }
  if (index < 0) {
    cout << "Impossible" << endl;
    exit(0);
  }
  v[index] = val;
  for (int i = index + 1; i < n; i++)
    if (v[i] >= 0) v[i] = 0;
  imax = 0;
  for (int i = 1; i < n; i++) {
    if (imax + r[imax] > i) {
      if (i + r[imax - (i - imax)] < imax + r[imax]) {
        r[i] = r[imax - (i - imax)];
      } else {
        r[i] = imax + r[imax] - i;
        while (0 < i - r[i] and i + r[i] < n - 1 and
               v[i - r[i] - 1] == v[i + r[i] + 1] and r[i] < cota[i])
          r[i]++;
        if (r[i] == cota[i]) {
          v[i + r[i]]++;
          int iant = i - 1;
          if (iant + cota[iant] == i + r[i] and iant - cota[iant] >= 0 and
              r[iant] == cota[iant] - 1 and
              v[iant - cota[iant]] == v[iant + cota[iant]])
            v[iant + cota[iant]]++;
          r[i]--;
        }
        imax = i;
      }
    } else {
      r[i] = 0;
      while (0 < i - r[i] and i + r[i] < n - 1 and
             v[i - r[i] - 1] == v[i + r[i] + 1] and r[i] < cota[i])
        r[i]++;
      if (r[i] == cota[i]) {
        v[i + r[i]]++;
        int iant = i - 1;
        if (iant + cota[iant] == i + r[i] and iant - cota[iant] >= 0 and
            r[iant] == cota[iant] - 1 and
            v[iant - cota[iant]] == v[iant + cota[iant]])
          v[iant + cota[iant]]++;
        r[i]--;
      }
      imax = i;
    }
  }
  for (int i = 0; i < n; i++)
    if (v[i] >= 0) cout << char(v[i] + 'a');
  cout << endl;
}
