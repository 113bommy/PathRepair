#include <bits/stdc++.h>
using namespace std;
static const double EPS = 1e-8;
int n, m;
vector<string> field;
int memo[40][40][40][40];
int rec(int tl, int br, int tr, int bl, int par) {
  if (br <= tl + 1 || bl <= tr + 1) return 0;
  if (memo[tl][br][tr][bl] >= 0) return memo[tl][br][tr][bl];
  int nst[420];
  memset(nst, 0, sizeof(nst));
  for (int r = 0; r < n; r++) {
    int cs = max(0, max(tl - r, r - bl + m));
    cs += ((r & 1) ^ (cs & 1) ^ par);
    for (int c = cs; c < min(m, min(br - r, r - tr + m)); c += 2) {
      int nstc;
      if (field[r][c] == 'X') {
        nstc = rec(tl, r + c, tr, r - c + m - 1, par) ^
               rec(r + c + 1, br, tr, r - c + m - 1, par) ^
               rec(tl, r + c, r - c + m, bl, par) ^
               rec(r + c + 1, br, r - c + m, bl, par);
      } else if (field[r][c] == 'L') {
        nstc = rec(tl, r + c, tr, bl, par) ^ rec(r + c + 1, br, tr, bl, par);
      } else {
        nstc = rec(tl, br, tr, r - c + m - 1, par) ^
               rec(tl, br, r - c + m, bl, par);
      }
      nst[nstc] = 1;
    }
  }
  int cst = 0;
  while (nst[cst]) cst++;
  memo[tl][br][tr][bl] = cst;
  return cst;
}
int main() {
  istream &fin = cin;
  ostream &fout = cout;
  FILE *fpin = stdin;
  FILE *fpout = stdout;
  fin >> n >> m;
  field.assign(n, string(m, ' '));
  for (int i = 0; i < n; i++) {
    fin >> field[i];
  }
  memset(memo, -1, sizeof(memo));
  int res = rec(0, n + m - 1, 0, n + m - 1, 0);
  memset(memo, -1, sizeof(memo));
  res ^= rec(0, n + m - 1, 0, n + m - 1, 1);
  if (res)
    fout << "WIN" << endl;
  else
    fout << "LOSE" << endl;
}
