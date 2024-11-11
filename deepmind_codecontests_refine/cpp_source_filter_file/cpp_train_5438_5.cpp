#include <bits/stdc++.h>
using namespace std;
string x[1001] = {
    "H",  "He", "Li", "Be", "B",  "C",  "N",  "O",  "F",  "Ne", "Na", "Mg",
    "Al", "Si", "P",  "S",  "Cl", "Ar", "K",  "Ca", "Sc", "Ti", "V",  "Cr",
    "Mn", "Fe", "Co", "Ni", "Cu", "Zn", "Ga", "Ge", "As", "Se", "Br", "Kr",
    "Rb", "Sr", "Y",  "Zr", "Nb", "Mo", "Tc", "Ru", "Rh", "Pd", "Ag", "Cd",
    "In", "Sn", "Sb", "Te", "I",  "Xe", "Cs", "Ba", "La", "Ce", "Pr", "Nd",
    "Pm", "Sm", "Eu", "Gd", "Tb", "Dy", "Ho", "Er", "Tm", "Yb", "Lu", "Hf",
    "Ta", "W",  "Re", "Os", "Ir", "Pt", "Au", "Hg", "Tl", "Pb", "Bi", "Po",
    "At", "Rn", "Fr", "Ra", "Ac", "Th", "Pa", "U",  "Np", "Pu", "Am", "Cm",
    "Bk", "Cf", "Es", "Fm", "Md", "No", "Lr", "Rf", "Db", "Sg", "Bh", "Hs",
    "Mt", "Ds", "Rg", "Cn", "Nh", "Fl", "Me", "Lv", "Ts", "Og"};
map<string, bool> M;
int len;
bool flag = false;
string xx;
void dfs(int d, string x1) {
  if (d == len && x1 == "") {
    flag = true;
    return;
  } else if (d == len) {
    return;
  }
  if (M[x1 + xx[d]]) {
    dfs(d + 1, "");
  }
  dfs(d + 1, x1 + xx[d]);
}
int main() {
  int i, j;
  for (i = 0; i <= 300; i++) {
    for (j = 0; j < x[i].size(); j++)
      if (x[i][j] > 'Z') x[i][j] = x[i][j] - 'a' + 'A';
    M[x[i]] = true;
  }
  cin >> xx;
  len = xx.size();
  string x1;
  dfs(0, "");
  if (flag)
    printf("YES\n");
  else
    printf("NO\n");
  return 0;
}
