#include <bits/stdc++.h>
using namespace std;
int H, W, S;
const int MAXN = 30;
char hrt[MAXN][MAXN];
int dn[MAXN][MAXN][MAXN][MAXN];
int V[MAXN][MAXN];
int f(int solust, int solalt, int sagust, int sagalt) {
  int &rev = dn[solust][solalt][sagust][sagalt];
  if (rev != -1) return rev;
  vector<int> tmp;
  tmp.clear();
  for (int(i) = (1); (i) <= (H); (i)++)
    for (int(j) = (1); (j) <= (W); (j)++) {
      if (V[i][j] && solust < ((i + j) / 2) && sagalt > ((i + j) / 2) &&
          solalt < ((j - i + H + 1) / 2) && sagust > ((j - i + H + 1) / 2)) {
        if (hrt[i][j] == 'R')
          tmp.push_back(f(solust, solalt, ((j - i + H + 1) / 2), sagalt) ^
                        f(solust, ((j - i + H + 1) / 2), sagust, sagalt));
        if (hrt[i][j] == 'L')
          tmp.push_back(f(solust, solalt, sagust, ((i + j) / 2)) ^
                        f(((i + j) / 2), solalt, sagust, sagalt));
        if (hrt[i][j] == 'X')
          tmp.push_back(
              f(solust, ((j - i + H + 1) / 2), sagust, ((i + j) / 2)) ^
              f(((i + j) / 2), ((j - i + H + 1) / 2), sagust, sagalt) ^
              f(solust, solalt, ((j - i + H + 1) / 2), ((i + j) / 2)) ^
              f(((i + j) / 2), solalt, ((j - i + H + 1) / 2), sagalt));
      }
    }
  sort(tmp.begin(), tmp.end());
  tmp.resize(unique(tmp.begin(), tmp.end()) - tmp.begin());
  rev = 0;
  for (int(i) = (0); (i) <= (((int)(tmp).size()) - 1); (i)++)
    if (rev == tmp[i])
      rev++;
    else
      break;
  return rev;
}
int main() {
  scanf(" %d %d", &H, &W);
  for (int(i) = (1); (i) <= (H); (i)++)
    for (int(j) = (1); (j) <= (W); (j)++) scanf(" %c", &hrt[i][j]);
  S = (H + W + 1) / 2;
  int res = 0;
  for (int(Q) = (0); (Q) <= (1); (Q)++) {
    memset(V, 0, sizeof(V));
    for (int(x) = (1); (x) <= (H); (x)++)
      for (int(y) = (1); (y) <= (W); (y)++)
        if ((x + y) % 2 == Q) V[x][y] = 1;
    memset(dn, -1, sizeof(dn));
    int tmp = f(0, 0, S / 2 + 1, S / 2 + 1);
    res ^= tmp;
  }
  printf("%s\n", res ? "WIN" : "LOSE");
  return 0;
}
