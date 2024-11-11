#include <bits/stdc++.h>
using namespace std;
struct node {
  int x, next, flag;
};
node e[100001];
int edge[100011], taile = 1;
int p[100001];
int n, m;
int ans[100001];
int t = 0;
int s1[100001], s2[100001];
int pp = 0;
void sol(int x) {
  int i, j, k;
  if (pp == 0) {
    for (i = 1; i <= n; i++) {
      for (j = edge[i]; j != -1; j = e[j].next) {
        if (i == x) {
          if (e[j].flag == 1) {
            ans[e[j].x] = 1;
          } else {
            ans[e[j].x] = -1;
          }
        } else {
          if (e[j].flag == 1) {
            ans[e[j].x] = -1;
          } else {
            ans[e[j].x] = 1;
          }
        }
      }
    }
    pp = x;
    return;
  }
  for (i = edge[pp]; i != -1; i = e[i].next) {
    ans[e[i].x] = 2;
  }
  for (i = edge[x]; i != -1; i = e[i].next) {
    ans[e[i].x] = 2;
  }
  return;
}
int main() {
  int i, j, k;
  memset(edge, -1, sizeof(int) * 100001);
  memset(ans, 0, sizeof(int) * 100001);
  memset(s1, 0, sizeof(int) * 100001);
  memset(s2, 0, sizeof(int) * 100001);
  scanf("%d %d", &n, &m);
  for (i = 1; i <= n; i++) {
    scanf("%d", &p[i]);
    if (p[i] > 0) {
      e[taile].x = i;
      e[taile].next = edge[p[i]];
      e[taile].flag = 1;
      edge[p[i]] = taile;
      taile++;
      s1[p[i]]++;
    } else {
      e[taile].x = i;
      e[taile].next = edge[-p[i]];
      e[taile].flag = -1;
      edge[-p[i]] = taile;
      taile++;
      s2[-p[i]]++;
    }
  }
  for (i = 2; i <= n; i++) {
    t += s2[i];
  }
  t += s1[1];
  if (t == m) {
    sol(1);
  }
  for (i = 2; i <= n; i++) {
    t -= s1[i - 1];
    t += s2[i - 1];
    t -= s2[i];
    t += s1[i];
    if (t == m) {
      sol(i);
    }
  }
  for (i = 1; i <= n; i++) {
    if (ans[i] == -1) {
      printf("Lie\n");
    } else if (ans[i] == 1) {
      printf("Truth\n");
    } else {
      printf("Not defined\n");
    }
  }
  return 0;
}
