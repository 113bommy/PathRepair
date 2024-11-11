#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
const long long mod = 1e9 + 7;
string element[110] = {
    "",   "H",  "He", "Li", "Be", "B",  "C",  "N",  "O",  "F",  "Ne", "Na",
    "Mg", "Al", "Si", "P",  "S",  "Cl", "Ar", "K",  "Ca", "Sc", "Ti", "V",
    "Cr", "Mn", "Fe", "Co", "Ni", "Cu", "Zn", "Ga", "Ge", "As", "Se", "Br",
    "Kr", "Rb", "Sr", "Y",  "Zr", "Nb", "Mo", "Tc", "Ru", "Rh", "Pd", "Ag",
    "Cd", "In", "Sn", "Sb", "Te", "I",  "Xe", "Cs", "Ba", "La", "Ce", "Pr",
    "Nd", "Pm", "Sm", "Eu", "Gd", "Tb", "Dy", "Ho", "Er", "Tm", "Yb", "Lu",
    "Hf", "Ta", "W",  "Re", "Os", "Ir", "Pt", "Au", "Hg", "Tl", "Pb", "Bi",
    "Po", "At", "Rn", "Fr", "Ra", "Ac", "Th", "Pa", "U",  "Np", "Pu", "Am",
    "Cm", "Bk", "Cf", "Es", "Fm"};
int n, m, pos[20], s1[20], s2[20];
bool flag;
string s;
vector<int> ans[22];
map<string, int> mp;
void dfs(int l, int sum, int r) {
  if (r == m + 1) {
    flag = 1;
    return;
  }
  if (s2[r] == sum) {
    dfs(1, 0, r + 1);
    return;
  }
  int pre = -1;
  for (int i = l; i <= n && !flag && s1[i] + sum <= s2[r]; i++) {
    if (pos[i] == -1 && s1[i] != pre) {
      pre = s1[i];
      pos[i] = r;
      dfs(l + 1, s1[i] + sum, r);
      if (!flag) pos[i] = -1;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int T;
  T = 1;
  for (int cs = 1; cs <= T; cs++) {
    cin >> n >> m;
    for (int i = 1; i <= 100; i++) mp[element[i]] = i;
    for (int i = 1; i <= n; i++) {
      cin >> s;
      s1[i] = mp[s];
    }
    for (int i = 1; i <= m; i++) {
      cin >> s;
      s2[i] = mp[s];
    }
    sort(s1 + 1, s1 + n + 1);
    sort(s2 + 1, s2 + m + 1);
    for (int i = 1; i <= n; i++) pos[i] = -1;
    dfs(1, 0, 1);
    if (flag) {
      cout << "YES\n";
      for (int i = 1; i <= n; i++) ans[pos[i]].push_back(s1[i]);
      for (int i = 1; i <= m; i++) {
        cout << element[ans[i][0]];
        for (int j = 1; j <= (int)ans[i].size() - 1; j++)
          cout << "+" << element[ans[i][j]];
        cout << "->" << element[s2[i]] << '\n';
      }
    } else
      cout << "NO\n";
  }
  return 0;
}
