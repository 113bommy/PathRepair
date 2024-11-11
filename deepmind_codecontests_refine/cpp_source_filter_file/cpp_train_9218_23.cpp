#include <bits/stdc++.h>
using namespace std;
int n, k, s1, s2;
string s[100] = {"H",  "He", "Li", "Be", "B",  "C",  "N",  "O",  "F",  "Ne",
                 "Na", "Mg", "Al", "Si", "P",  "S",  "Cl", "Ar", "K",  "Ca",
                 "Sc", "Ti", "V",  "Cr", "Mn", "Fe", "Co", "Ni", "Cu", "Zn",
                 "Ga", "Ge", "As", "Se", "Br", "Kr", "Rb", "Sr", "Y",  "Zr",
                 "Nb", "Mo", "Tc", "Ru", "Rh", "Pd", "Ag", "Cd", "In", "Sn",
                 "Sb", "Te", "I",  "Xe", "Cs", "Ba", "La", "Ce", "Pr", "Nd",
                 "Pm", "Sm", "Eu", "Cd", "Tb", "Dy", "Ho", "Er", "Tm", "Yb",
                 "Lu", "Hf", "Ta", "W",  "Re", "Os", "Ir", "Pt", "Au", "Hg",
                 "TI", "Pb", "Bi", "Po", "Af", "Ru", "Fr", "Ra", "Ac", "Th",
                 "Pa", "U",  "Xp", "Pu", "Am", "Cm", "Bk", "Cf", "Es", "Fm"};
string t;
int a[100], b[100], g[100][100];
int dp1[200000], dp2[200000], father[200000];
bool ok;
void read(int &x) {
  cin >> t;
  for (int i = 0; i <= 99; i++)
    if (s[i] == t) {
      x = i + 1;
      return;
    }
}
void check() {
  for (int i = 1; i <= (1 << n) - 1; i++)
    for (int j = 1; j <= n; j++)
      if (i & (1 << (j - 1))) dp1[i] += a[j];
  for (int i = 1; i <= (1 << n) - 1; i++) {
    dp2[i] = -1;
    for (int j = i; j; j = (j - 1) & i) {
      if (dp2[i ^ j] != -1 && b[dp2[i ^ j] + 1] == dp1[j]) {
        dp2[i] = dp2[i ^ j] + 1;
        father[i] = i ^ j;
      }
    }
  }
  if (dp2[(1 << n) - 1] == k) {
    ok = 1;
    int x = (1 << n) - 1;
    for (int i = k; i >= 1; i--) {
      for (int j = 1; j <= n; j++)
        if ((1 << (j - 1)) & (x ^ father[x])) g[i][++g[i][0]] = j;
      x = father[x];
    }
  }
}
int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    read(a[i]);
    s1 += a[i];
  }
  for (int i = 1; i <= k; i++) {
    read(b[i]);
    s2 += b[i];
  }
  if (s1 == s2) check();
  if (!ok)
    cout << "NO\n";
  else {
    cout << "YES\n";
    for (int i = 1; i <= k; i++) {
      cout << s[a[g[i][1]] - 1];
      for (int j = 2; j <= g[i][0]; j++) cout << "+" << s[a[g[i][j]] - 1];
      cout << "->" << s[b[i] - 1] << "\n";
    }
  }
  return 0;
}
