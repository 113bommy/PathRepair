#include <bits/stdc++.h>
using namespace std;
double tt;
string v[] = {"",   "H",  "He", "Li", "Be", "B",  "C",  "N",  "O",  "F",  "Ne",
              "Na", "Mg", "Al", "Si", "P",  "S",  "Cl", "Ar", "K",  "Ca", "Sc",
              "Ti", "V",  "Cr", "Mn", "Fe", "Co", "Ni", "Cu", "Zn", "Ga", "Ge",
              "As", "Se", "Br", "Kr", "Rb", "Sr", "Y",  "Zr", "Nb", "Mo", "Tc",
              "Ru", "Rh", "Pd", "Ag", "Cd", "In", "Sn", "Sb", "Te", "I",  "Xe",
              "Cs", "Ba", "La", "Ce", "Pr", "Nd", "Pm", "Sm", "Eu", "Gd", "Tb",
              "Dy", "Ho", "Er", "Tm", "Yb", "Lu", "Hf", "Ta", "W",  "Re", "Os",
              "Ir", "Pt", "Au", "Hg", "Tl", "Pb", "Bi", "Po", "At", "Rn", "Fr",
              "Ra", "Ac", "Th", "Pa", "U",  "Np", "Pu", "Am", "Cm", "Bk", "Cf",
              "Es", "Fm"};
int trans(const string a) {
  for (int i = 0; i <= 100; i++)
    if (v[i] == a) return i;
  return -1;
}
int n, k, top = 0;
string s;
string res[100];
vector<int> lst[100];
vector<int> a, b;
bool ok = false;
void go(vector<int> &a, vector<int> &b) {
  if (((clock() - tt) / CLOCKS_PER_SEC) > 2.8) return;
  int n = a.size();
  int m = b.size();
  vector<int> aa;
  vector<int> bb(b);
  bb.erase(--bb.end());
  if (n == m && m == 0) {
    ok = true;
    return;
  }
  if (n * m == 0) return;
  const int mst = (1 << n) - 1;
  int mask = mst;
  while (mask) {
    aa.clear();
    int sum = 0;
    for (int i = 0; i < n; i++)
      if ((1 << i) & mask) {
        sum += a[i];
      } else {
        aa.push_back(a[i]);
      }
    if (b[m - 1] == sum) {
      top++;
      lst[top].clear();
      res[top] = v[sum];
      for (int i = 0; i < n; i++)
        if ((1 << i) & mask) lst[top].push_back(a[i]);
      go(aa, bb);
      if (ok) return;
      top--;
    }
    mask = (mask - 1) & mst;
  }
}
int main() {
  tt = clock();
  int n, k;
  scanf("%d %d\n", &n, &k);
  for (int i = 1; i <= n; i++) {
    cin >> s;
    a.push_back(trans(s));
  }
  for (int i = 1; i <= k; i++) {
    cin >> s;
    b.push_back(trans(s));
  }
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  go(a, b);
  if (ok) {
    cout << "YES\n";
    for (int i = 1; i <= top; i++) {
      int sz = lst[i].size();
      for (int j = 0; j < sz; j++) {
        cout << v[lst[i][j]];
        if (j != sz - 1)
          cout << "+";
        else
          cout << "->";
      }
      cout << res[i] << endl;
    }
  } else
    cout << "NO\n";
  return 0;
}
