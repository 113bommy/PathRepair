#include <bits/stdc++.h>
using namespace std;
int mn = 1000001, sv;
char lst;
int n;
int ar[1000002];
void fnc(int sm, int pr, int id, int e, char ls) {
  if (id == n) {
    if (sm == 1 && pr == 1 && ls == 0) {
      if (e < mn) {
        mn = e;
        sv = -1;
      }
    }
    return;
  }
  if (pr == 1 && sm == 1) return;
  if (pr == 1) {
    fnc(1, 1, id + sm - 1, e + sm - 2, 1 - ls);
    return;
  }
  if (pr == 0) return;
  if (sm / pr + id > n + 1 || sm == 0) return;
  fnc(pr, sm % pr, id + sm / pr, e + sm / pr - 1, 1 - ls);
}
char st;
void fnc2(int sm, int pr, int id, char ls) {
  if (id == n) return;
  int i, tm;
  if (ls == 0)
    ar[id] = 'T';
  else
    ar[id] = 'B';
  if (sm - pr < pr) ls = 1 - ls;
  fnc2(max(sm - pr, pr), min(sm - pr, pr), id + 1, ls);
}
FILE* f1 = stdin;
int main() {
  int rs;
  int i, sm;
  fscanf(f1, "%d%d", &n, &rs);
  sv = 0;
  for (i = 1; i < rs; i++) {
    fnc(rs, i, 1, 0, 0);
    if (sv == -1) {
      sv = i;
      st = 0;
    }
    fnc(rs, i, 1, 0, 1);
    if (sv == -1) {
      sv = i;
      st = 1;
    }
  }
  if (n == 1 && rs == 1) {
    printf("0\nT\n");
    exit(0);
  }
  if (mn == 1000001)
    printf("IMPOSSIBLE");
  else {
    printf("%d\n", mn);
    fnc2(rs, sv, 1, st);
    printf("T");
    for (i = n - 1; i >= 1; i--) printf("%c", ar[i]);
  }
  printf("\n");
  scanf("%*d");
}
