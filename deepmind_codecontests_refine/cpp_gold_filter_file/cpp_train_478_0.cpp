#include <bits/stdc++.h>
using namespace std;
int n;
map<string, int> mp;
char cmd[100];
char stra[100], strb[100];
void deal(char arr[100], int& nsand, int& nstar, string& a) {
  int i, j;
  int l, h;
  l = 0;
  h = strlen(arr) - 1;
  while (arr[l] == '&') {
    l++;
  }
  while (arr[h] == '*') {
    h--;
  }
  nsand = l;
  nstar = strlen(arr) - 1 - h;
  a = "";
  for (i = l; i <= h; i++) a += arr[i];
  return;
}
int main() {
  int i, j;
  int nsand, nstar;
  string a, b;
  int num;
  while (scanf("%d", &n) != EOF) {
    mp.clear();
    mp["void"] = 1;
    for (i = 0; i < n; i++) {
      scanf("%s", cmd);
      if (cmd[4] == 'd') {
        scanf("%s%s", stra, strb);
        b = strb;
        deal(stra, nsand, nstar, a);
        if (mp[a] <= 0) {
          mp[b] = 0;
        } else {
          num = mp[a];
          if (num + nstar - nsand <= 0)
            mp[b] = 0;
          else
            mp[b] = num + nstar - nsand;
        }
      } else {
        scanf("%s", stra);
        deal(stra, nsand, nstar, a);
        num = mp[a];
        if (num <= 0)
          printf("errtype\n");
        else {
          num = num + nstar - nsand;
          if (num <= 0)
            printf("errtype\n");
          else {
            printf("void");
            for (j = 1; j < num; j++) printf("*");
            printf("\n");
          }
        }
      }
    }
  }
  return 0;
}
