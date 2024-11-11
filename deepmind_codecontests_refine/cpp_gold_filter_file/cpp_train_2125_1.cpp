#include <bits/stdc++.h>
using namespace std;
const int MAXN = 105;
bool marca[MAXN][MAXN][MAXN];
int dp[MAXN][MAXN][MAXN];
string cad[MAXN][MAXN][MAXN];
char s1[MAXN], s2[MAXN], virus[MAXN];
int pi[MAXN];
void PreKMP(char *P, int n) {
  int q, k = 0;
  pi[1] = 0;
  for (q = 2; q <= n; pi[q++] = k) {
    while (k && (P[k] != P[q - 1])) k = pi[k];
    if (P[k] == P[q - 1]) k++;
  }
}
int l1, l2, lv;
int solve(int i, int j, int lenv) {
  if (i == l1 || j == l2) return 0;
  if (marca[i][j][lenv]) return dp[i][j][lenv];
  marca[i][j][lenv] = true;
  cad[i][j][lenv] = "";
  string c1 = "";
  int sol = 0, aux, tmp;
  if (s1[i] == s2[j]) {
    int ll = lenv;
    while (ll != 0 && s1[i] != virus[ll]) ll = pi[ll];
    tmp = ll + (s1[i] == virus[ll]);
    if (tmp != lv) {
      aux = sol;
      sol = max(sol, solve(i + 1, j + 1, tmp) + 1);
      if (aux != sol) {
        c1 = s1[i] + cad[i + 1][j + 1][tmp];
      }
    }
  }
  aux = sol;
  sol = max(sol, solve(i + 1, j, lenv));
  if (aux != sol) {
    c1 = cad[i + 1][j][lenv];
  }
  aux = sol;
  sol = max(sol, solve(i, j + 1, lenv));
  if (aux != sol) {
    c1 = cad[i][j + 1][lenv];
  }
  dp[i][j][lenv] = sol;
  cad[i][j][lenv] = c1;
  return sol;
}
int main() {
  scanf("%s%s%s", s1, s2, virus);
  l1 = strlen(s1);
  l2 = strlen(s2);
  lv = strlen(virus);
  PreKMP(virus, lv);
  int sol = solve(0, 0, 0);
  if (!sol)
    cout << sol << endl;
  else
    cout << cad[0][0][0] << endl;
  return 0;
}
