#include <bits/stdc++.h>
using namespace std;
static const double EPS = 1e-8;
int main() {
  istream &fin = cin;
  ostream &fout = cout;
  FILE *fpin = stdin;
  FILE *fpout = stdout;
  int N, K;
  fin >> N >> K;
  string P, occ;
  fin >> P >> occ;
  bool ok = true;
  string res(N, ' ');
  for (int i = 0; i < (int)occ.size(); i++) {
    if (occ[i] == '0') continue;
    for (int j = 0; j < (int)P.size(); j++) {
      if (res[i + j] != ' ' && res[i + j] != P[j]) {
        ok = false;
        break;
      }
      res[i + j] = P[j];
    }
    if (!ok) break;
  }
  set<char> stc;
  for (int i = 0; i < (int)P.size(); i++) {
    stc.insert(P[i]);
  }
  char fill;
  if ((int)stc.size() > 1)
    fill = 'a';
  else {
    if (*stc.begin() == 'a')
      fill = 'b';
    else
      fill = 'a';
  }
  for (int i = 0; i < N; i++) {
    if (res[i] == ' ') res[i] = fill;
  }
  for (int i = 0; i < (int)occ.size(); i++) {
    if (occ[i] == '1') continue;
    if (res.substr(i, P.size()) == P) {
      ok = false;
      break;
    }
  }
  if (!ok)
    fout << "No solution\n";
  else
    fout << res << "\n";
}
