#include <bits/stdc++.h>
using namespace std;
void read(int &k) {
  k = 0;
  char x = getchar();
  while (x < '0' || x > '9') x = getchar();
  while (x >= '0' && x <= '9') {
    k = k * 10 - 48 + x;
    x = getchar();
  }
}
bool now[100010], pri[100010];
int c[100010], l, n, m, t, use[100010], len, k;
char ope[10];
vector<int> rec[100010];
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 2; i * i <= 100000; i++)
    if (!pri[i])
      for (int j = i * i; j <= 100000; j += i) pri[j] = true;
  for (int i = 2; i <= 100000; i++)
    if (!pri[i]) c[++len] = i;
  for (int i = 2; i <= 100000; i++) {
    t = i;
    for (int j = 1; j <= len && c[j] <= t; j++)
      if (t % c[j] == 0) {
        rec[t].push_back(j);
        while (t % c[j] == 0) t /= c[j];
      }
  }
  int i;
  for (; m--;) {
    scanf("%s%d", ope, &k);
    if (ope[0] == '+') {
      if (now[k])
        puts("Already on");
      else {
        l = rec[k].size();
        for (i = 0; i < l; i++)
          if (use[rec[k][i]]) break;
        if (i >= l) {
          for (i = 0; i < l; i++) use[rec[k][i]] = k;
          now[k] = true;
          puts("Success");
        } else
          printf("Conflict with %d\n", use[rec[k][i]]);
      }
    } else {
      if (!now[k])
        puts("Already off");
      else {
        now[k] = false;
        l = rec[k].size();
        for (i = 0; i < l; i++) use[rec[k][i]] = 0;
        puts("Success");
      }
    }
  }
  return 0;
}
