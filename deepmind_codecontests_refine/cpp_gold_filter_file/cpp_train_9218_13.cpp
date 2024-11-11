#include <bits/stdc++.h>
using namespace std;
const string table[] = {
    "n",  "H",  "He", "Li", "Be", "B",  "C",  "N",  "O",  "F",  "Ne", "Na",
    "Mg", "Al", "Si", "P",  "S",  "Cl", "Ar", "K",  "Ca", "Sc", "Ti", "V",
    "Cr", "Mn", "Fe", "Co", "Ni", "Cu", "Zn", "Ga", "Ge", "As", "Se", "Br",
    "Kr", "Rb", "Sr", "Y",  "Zr", "Nb", "Mo", "Tc", "Ru", "Rh", "Pd", "Ag",
    "Cd", "In", "Sn", "Sb", "Te", "I",  "Xe", "Cs", "Ba", "La", "Ce", "Pr",
    "Nd", "Pm", "Sm", "Eu", "Gd", "Tb", "Dy", "Ho", "Er", "Tm", "Yb", "Lu",
    "Hf", "Ta", "W",  "Re", "Os", "Ir", "Pt", "Au", "Hg", "Tl", "Pb", "Bi",
    "Po", "At", "Rn", "Fr", "Ra", "Ac", "Th", "Pa", "U",  "Np", "Pu", "Am",
    "Cm", "Bk", "Cf", "Es", "Fm"};
int n, m, S[20], T[20], pre[20][1 << 17], MT;
bool f[20][1 << 17];
vector<int> M[200];
string Ss[20], Ts[20];
map<string, int> Tn;
void init(int x, int s, int mass) {
  if (x == n) {
    if (mass <= 100) M[mass].push_back(s);
  } else {
    init(x + 1, s, mass);
    init(x + 1, s + (1 << x), mass + S[x]);
  }
}
int main() {
  for (int i = 1; i <= 100; i++) Tn[table[i]] = i;
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> Ss[i], S[i] = Tn[Ss[i]];
  for (int i = 1; i <= m; i++) cin >> Ts[i], T[i] = Tn[Ts[i]];
  init(0, 0, 0);
  f[0][0] = true;
  int St = 1 << n;
  for (int i = 0; i < n; i++) {
    int mass = T[i + 1];
    for (int s = 0; s < St; s++) {
      if (!f[i][s]) continue;
      for (int k = 0; k < (int)M[mass].size(); k++) {
        if ((M[mass][k] & s)) continue;
        pre[i + 1][s ^ M[mass][k]] = s;
        f[i + 1][s ^ M[mass][k]] = true;
      }
    }
  }
  if (!f[n][St - 1])
    cout << "NO" << endl;
  else {
    cout << "YES" << endl;
    int now = m, s = St - 1;
    while (now) {
      int tmp = s ^ pre[now][s];
      bool flag = false;
      for (int i = 0; i < n; i++) {
        if (tmp & (1 << i)) {
          if (flag) cout << "+";
          cout << table[S[i]], flag = true;
        }
      }
      cout << "->" << Ts[now] << endl;
      s = pre[now][s];
      now--;
    }
  }
}
