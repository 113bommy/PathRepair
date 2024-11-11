#include <bits/stdc++.h>
using namespace std;
const int MAXN = 15;
const int MAXK = 500005;
const int MAXL = 11;
const int inf = 1e9;
int f[1 << MAXN][110];
int nextC[MAXK][MAXN];
int invCnt[1 << MAXN][MAXN];
long long w[MAXK];
long long a[MAXN];
long long readWord() {
  static char s[15];
  scanf("%s", s);
  long long ans = 0;
  int len = strlen(s);
  for (int i = 0; i < (len); ++i) ans = ans * 26 + s[i] - 'a';
  return ans;
}
int main(void) {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < (n); ++i) a[i] = readWord();
  int invMax = n * (n - 1) / 2 + 1;
  for (int s = 0; s < ((1 << n)); ++s)
    for (int i = 0; i < (n); ++i) {
      invCnt[s][i] = 0;
      for (int j = 0; j < (n); ++j)
        if ((s & (1 << j)) && j > i) invCnt[s][i]++;
    }
  int m;
  scanf("%d", &m);
  int bestp = -1, ind;
  for (int i = 0; i < (m); ++i) {
    int k;
    scanf("%d", &k);
    for (int j = 0; j < (k); ++j) w[j] = readWord();
    static map<long long, int> M;
    M.clear();
    for (int j = k; j >= 0; --j) {
      if (j < k) M[w[j]] = j;
      for (int i = 0; i < (n); ++i) nextC[j][i] = M.count(a[i]) ? M[a[i]] : inf;
    }
    for (int s = 0; s < ((1 << n)); ++s)
      for (int j = 0; j < (invMax); ++j) f[s][j] = inf;
    f[0][0] = 0;
    for (int s = 0; s < ((1 << n)); ++s)
      for (int j = 0; j < (invMax); ++j)
        if (f[s][j] < inf) {
          for (int i = 0; i < (n); ++i)
            if (!(s & (1 << i)))
              f[s | (1 << i)][j + invCnt[s][i]] =
                  min(f[s | (1 << i)][j + invCnt[s][i]], nextC[f[s][j]][i] + 1);
        }
    for (int j = 0; j < (invMax); ++j)
      if (f[(1 << n) - 1][j] < inf && invMax - j > bestp)
        bestp = invMax - j, ind = i;
  }
  if (bestp == -1)
    puts("Brand new problem!");
  else {
    printf("%d\n", ind + 1);
    printf("[:");
    for (int i = 0; i < (bestp); ++i) printf("|");
    printf(":]\n");
  }
  return 0;
}
