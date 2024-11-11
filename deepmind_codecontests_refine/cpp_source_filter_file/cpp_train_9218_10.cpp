#include <bits/stdc++.h>
using namespace std;
const int N = 18;
const int inf = 1e9 * 2 + 10;
const long long INF = 1e18 * 2 + 10;
string st[] = {
    "Pony", "H",  "He", "Li", "Be", "B",  "C",  "N",  "O",  "F",  "Ne", "Na",
    "Mg",   "Al", "Si", "P",  "S",  "Cl", "Ar", "K",  "Ca", "Sc", "Ti", "V",
    "Cr",   "Mn", "Fe", "Co", "Ni", "Cu", "Zn", "Ga", "Ge", "As", "Se", "Br",
    "Kr",   "Rb", "Sr", "Y",  "Zr", "Nb", "Mo", "Tc", "Ru", "Rh", "Pd", "Ag",
    "Cd",   "In", "Sn", "Sb", "Te", "I",  "Xe", "Cs", "Ba", "La", "Ce", "Pr",
    "Nd",   "Pm", "Sm", "Eu", "Gd", "Tb", "Dy", "Ho", "Er", "Tm", "Yb", "Lu",
    "Hf",   "Ta", "W",  "Re", "Os", "Ir", "Pt", "Au", "Hg", "Tl", "Pb", "Bi",
    "Po",   "At", "Rn", "Fr", "Ra", "Ac", "Th", "Pa", "U",  "Np", "Pu", "Am",
    "Cm",   "Bk", "Cf", "Es", "Fm"};
int a[N], b[N], sum[1 << N], dp[1 << N], n, k, idx[1 << N], pre[1 << N];
vector<int> res[1 << N];
int getid(string x) {
  for (int i = (0); i <= (110); ++i)
    if (x == st[i]) return i;
  return 0;
}
int main() {
  cin >> n >> k;
  for (int i = (0); i <= (n - 1); ++i) {
    string x;
    cin >> x;
    a[i] = getid(x);
  }
  for (int i = (0); i <= (k - 1); ++i) {
    string x;
    cin >> x;
    b[i] = getid(x);
  }
  for (int mask = (0); mask <= ((1 << n) - 1); ++mask)
    for (int i = (0); i <= (n - 1); ++i)
      if (mask & (1 << i)) {
        sum[mask] += a[i];
        res[mask].push_back(i);
      }
  for (int mask = (0); mask <= ((1 << n) - 1); ++mask) {
    for (int i = (0); i <= (k - 1); ++i)
      if (b[i] == sum[mask]) idx[mask] = i;
  }
  fill(&dp[0], &dp[0] + (1 << N), -1);
  dp[0] = 0;
  for (int mask = (0); mask <= ((1 << n) - 1); ++mask) {
    for (int new_mask = mask; new_mask; new_mask = (new_mask - 1) & mask) {
      int left = mask ^ new_mask;
      if (dp[left] != -1) {
        if (sum[new_mask] == b[dp[left]]) {
          if (dp[mask] < dp[left] + 1) {
            dp[mask] = dp[left] + 1;
            pre[mask] = left;
          }
        }
      }
    }
  }
  if (dp[(1 << n) - 1] == -1)
    cout << "NO";
  else {
    cout << "YES\n";
    int MASK = (1 << n) - 1;
    while (MASK) {
      int nM = pre[MASK];
      int left = nM ^ MASK;
      for (int i = (0); i <= ((int)(res[left]).size() - 1); ++i)
        cout << st[a[res[left][i]]] << "+="[i == (int)(res[left]).size() - 1];
      cout << st[b[idx[left]]] << "\n";
      MASK = nM;
    }
  }
  return 0;
}
