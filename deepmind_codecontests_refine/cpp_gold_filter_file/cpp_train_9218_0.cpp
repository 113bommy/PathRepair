#include <bits/stdc++.h>
using namespace std;
inline int readint() {
  int a = 0;
  char c = getchar(), f = 1;
  for (; c < '0' or c > '9'; c = getchar())
    if (c == '-') f = -f;
  for (; '0' <= c and c <= '9'; c = getchar())
    a = (a << 3) + (a << 1) + (c ^ 48);
  return a * f;
}
void writeint(long long x) {
  if (x < 0) putchar('-'), x = -x;
  if (x > 9) writeint(x / 10);
  putchar((x % 10) ^ 48);
}
template <typename T>
void getMax(T &a, const T &b) {
  if (a < b) a = b;
}
template <typename T>
void getMin(T &a, const T &b) {
  if (b < a) a = b;
}
const int MaxN = 17;
string has[101];
void prepare() {
  has[1] = "H";
  has[26] = "Fe";
  has[2] = "He";
  has[27] = "Co";
  has[3] = "Li";
  has[28] = "Ni";
  has[4] = "Be";
  has[29] = "Cu";
  has[5] = "B";
  has[30] = "Zn";
  has[6] = "C";
  has[31] = "Ga";
  has[7] = "N";
  has[32] = "Ge";
  has[8] = "O";
  has[33] = "As";
  has[9] = "F";
  has[34] = "Se";
  has[10] = "Ne";
  has[35] = "Br";
  has[11] = "Na";
  has[36] = "Kr";
  has[12] = "Mg";
  has[37] = "Rb";
  has[13] = "Al";
  has[38] = "Sr";
  has[14] = "Si";
  has[39] = "Y";
  has[15] = "P";
  has[40] = "Zr";
  has[16] = "S";
  has[41] = "Nb";
  has[17] = "Cl";
  has[42] = "Mo";
  has[18] = "Ar";
  has[43] = "Tc";
  has[19] = "K";
  has[44] = "Ru";
  has[20] = "Ca";
  has[45] = "Rh";
  has[21] = "Sc";
  has[46] = "Pd";
  has[22] = "Ti";
  has[47] = "Ag";
  has[23] = "V";
  has[48] = "Cd";
  has[24] = "Cr";
  has[49] = "In";
  has[25] = "Mn";
  has[50] = "Sn";
  has[51] = "Sb";
  has[76] = "Os";
  has[52] = "Te";
  has[77] = "Ir";
  has[53] = "I";
  has[78] = "Pt";
  has[54] = "Xe";
  has[79] = "Au";
  has[55] = "Cs";
  has[80] = "Hg";
  has[56] = "Ba";
  has[81] = "Tl";
  has[57] = "La";
  has[82] = "Pb";
  has[58] = "Ce";
  has[83] = "Bi";
  has[59] = "Pr";
  has[84] = "Po";
  has[60] = "Nd";
  has[85] = "At";
  has[61] = "Pm";
  has[86] = "Rn";
  has[62] = "Sm";
  has[87] = "Fr";
  has[63] = "Eu";
  has[88] = "Ra";
  has[64] = "Gd";
  has[89] = "Ac";
  has[65] = "Tb";
  has[90] = "Th";
  has[66] = "Dy";
  has[91] = "Pa";
  has[67] = "Ho";
  has[92] = "U";
  has[68] = "Er";
  has[93] = "Np";
  has[69] = "Tm";
  has[94] = "Pu";
  has[70] = "Yb";
  has[95] = "Am";
  has[71] = "Lu";
  has[96] = "Cm";
  has[72] = "Hf";
  has[97] = "Bk";
  has[73] = "Ta";
  has[98] = "Cf";
  has[74] = "W";
  has[99] = "Es";
  has[75] = "Re";
  has[100] = "Fm";
}
bool dp[MaxN + 1][1 << MaxN];
int a[MaxN], b[MaxN + 1], n;
vector<int> match[MaxN * 100 + 1];
string s;
char str[MaxN];
int toInt() {
  scanf("%s", str), s.clear();
  for (int j = 0; str[j]; ++j) s.push_back(str[j]);
  for (int j = 1; j <= 100; ++j)
    if (has[j] == s) return j;
}
void paint(int x) {
  int len = has[x].size();
  for (int i = 0; i < len; ++i) putchar(has[x][i]);
}
void print(int i, int S) {
  if (!i) return;
  int op;
  bool f = false;
  for (auto s : match[b[i]])
    if ((s & S) == s && dp[i - 1][S ^ s]) {
      print(i - 1, S ^ s);
      op = s;
      break;
    }
  for (int j = 0; j < n; ++j)
    if (op >> j & 1) {
      if (f) putchar('+');
      paint(a[j]), f = 1;
    }
  putchar('-'), putchar('>');
  paint(b[i]), putchar('\n');
}
int main() {
  prepare();
  n = readint();
  int m = readint();
  for (int i = 0; i < n; ++i) a[i] = toInt();
  dp[0][0] = true;
  for (int S = 1; S < (1 << n); ++S) {
    int sum = 0;
    for (int i = 0; i < n; ++i)
      if (S >> i & 1) sum += a[i];
    match[sum].push_back(S);
  }
  for (int i = 1; i <= m; ++i) {
    b[i] = toInt();
    for (auto S : match[b[i]]) {
      int ALL = (1 << n) - 1 - S;
      for (int s = ALL; s; s = (s - 1) & ALL) dp[i][s | S] |= dp[i - 1][s];
      dp[i][S] |= dp[i - 1][0];
    }
  }
  if (!dp[m][(1 << n) - 1]) {
    puts("NO");
    return 0;
  }
  puts("YES");
  print(m, (1 << n) - 1);
  return 0;
}
