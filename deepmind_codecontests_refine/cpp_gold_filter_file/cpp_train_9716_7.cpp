#include <bits/stdc++.h>
using namespace std;
int n, m, ans[100100], com[100100], notcom[100100];
int totalcom, totalnotcom, ncase;
bool criminal[100100];
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    int u;
    scanf("%d", &u);
    ans[i] = u;
    if (u < 0) {
      notcom[-u]++;
      totalnotcom++;
    } else {
      com[u]++;
      totalcom++;
    }
  }
  for (int i = 1; i <= n; i++)
    if (com[i] + totalnotcom - notcom[i] == m) {
      ncase++;
      criminal[i] = true;
    }
  for (int i = 1; i <= n; i++)
    if (ans[i] > 0) {
      if (criminal[ans[i]]) {
        if (ncase == 1)
          printf("Truth\n");
        else
          printf("Not defined\n");
      } else
        printf("Lie\n");
    } else {
      if (criminal[-ans[i]]) {
        if (ncase == 1)
          printf("Lie\n");
        else
          printf("Not defined\n");
      } else
        printf("Truth\n");
    }
}
