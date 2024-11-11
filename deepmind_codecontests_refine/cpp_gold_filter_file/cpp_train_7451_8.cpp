#include <bits/stdc++.h>
using namespace std;
int n, m, q, like[100069], opp[100069], par[100069];
map<string, int> ma;
int see(int x) {
  if (x == par[x]) return x;
  return par[x] = see(par[x]);
}
void join(int x, int y) {
  x = see(x);
  y = see(y);
  par[x] = y;
}
int main() {
  scanf("%d", &n), scanf("%d", &m), scanf("%d", &q);
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    ma[s] = i + 1;
  }
  for (int i = 1; i < n + 1; i++) par[i] = i, opp[i] = -1, like[i] = -1;
  for (int i = 0; i < m; i++) {
    int x;
    scanf("%d", &x);
    string s1, s2;
    cin >> s1 >> s2;
    int p1 = ma[s1];
    int p2 = ma[s2];
    p1 = see(p1);
    p2 = see(p2);
    if (x == 1) {
      if (p1 != p2) {
        if (opp[p1] == p2 || opp[p2] == p1) {
          puts("NO");
          continue;
        } else {
          puts("YES");
          par[p1] = p2;
          if (opp[p1] != -1 && opp[p2] != -1) {
            int op1 = see(opp[p1]);
            int op2 = see(opp[p2]);
            par[op1] = op2;
            opp[p2] = op2;
            opp[op2] = p2;
          } else if (opp[p1] != -1) {
            int op1 = see(opp[p1]);
            opp[p2] = op1;
            opp[op1] = p2;
          } else if (opp[p2] != -1) {
            int op2 = see(opp[p2]);
            opp[p2] = op2;
            opp[op2] = p2;
          }
        }
      } else
        puts("YES");
    } else {
      if (p1 == p2) {
        puts("NO");
        continue;
      } else {
        puts("YES");
        if (opp[p2] == -1) opp[p2] = p1;
        if (opp[p1] == -1) opp[p1] = p2;
        par[see(opp[p1])] = see(p2);
        par[see(opp[p2])] = see(p1);
        int pp1 = see(p1);
        int pp2 = see(p2);
        opp[pp1] = pp2;
        opp[pp2] = pp1;
      }
    }
  }
  while (q--) {
    string s1, s2;
    cin >> s1 >> s2;
    int p1 = ma[s1];
    int p2 = ma[s2];
    p1 = see(p1);
    p2 = see(p2);
    if (p1 == p2)
      puts("1");
    else if (p1 == opp[p2] || opp[p1] == p2)
      puts("2");
    else
      puts("3");
  }
  return 0;
}
