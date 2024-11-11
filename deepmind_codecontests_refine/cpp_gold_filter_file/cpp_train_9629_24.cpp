#include <bits/stdc++.h>
using namespace std;
template <class T>
T sqr(T x) {
  return x * x;
}
const int MAXN = (int)(5e5) + 10;
int n, q;
vector<int> g[MAXN], o[MAXN];
char s[MAXN];
int h[MAXN];
int sm[MAXN][26];
int tin[MAXN], tout[MAXN], timer;
void go(int v, int he) {
  o[he].push_back(v);
  h[v] = he;
  tin[v] = timer++;
  for (int to : g[v]) {
    go(to, he + 1);
  }
  tout[v] = timer++;
}
int getL(int v, int he) {
  int lf = -1, rg = o[he].size();
  while (rg - lf > 1) {
    int md = (lf + rg) / 2;
    if (tin[o[he][md]] >= tin[v]) {
      rg = md;
    } else {
      lf = md;
    }
  }
  return rg;
}
int getR(int v, int he) {
  int lf = -1, rg = o[he].size();
  while (rg - lf > 1) {
    int md = (lf + rg) / 2;
    if (tout[o[he][md]] <= tout[v]) {
      lf = md;
    } else {
      rg = md;
    }
  }
  return lf + 1;
}
int main() {
  scanf("%d%d", &n, &q);
  for (int i = 1; i < n; i++) {
    int pr;
    scanf("%d", &pr);
    --pr;
    g[pr].push_back(i);
  }
  scanf("%s", s);
  go(0, 0);
  for (int i = 0; i < n; i++) {
    int pr = 0;
    for (int j = 0; j < ((int)((o[i]).size())); j++) {
      for (int k = 0; k < 26; k++) {
        sm[o[i][j] + 1][k] = sm[pr][k];
      }
      sm[o[i][j] + 1][s[o[i][j]] - 'a']++;
      pr = o[i][j] + 1;
    }
  }
  int v, he;
  while (q-- > 0) {
    scanf("%d%d", &v, &he);
    --v;
    --he;
    if (he <= h[v]) {
      puts("Yes");
    } else {
      int lf = getL(v, he) - 1;
      if (lf < 0) {
        lf = 0;
      } else {
        lf = o[he][lf] + 1;
      }
      int rg = getR(v, he) - 1;
      if (rg < 0) {
        rg = 0;
      } else {
        rg = o[he][rg] + 1;
      }
      int cnt = 0;
      for (int i = 0; i < 26; i++) {
        if ((sm[rg][i] - sm[lf][i]) % 2 == 1) {
          cnt++;
        }
      }
      if (cnt < 2) {
        puts("Yes");
      } else {
        puts("No");
      }
    }
  }
  return 0;
}
