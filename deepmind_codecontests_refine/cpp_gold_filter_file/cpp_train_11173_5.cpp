#include <bits/stdc++.h>
using namespace std;
int g[100005];
int del[100005];
bool f[100005];
int n, m;
int delSize;
void getDel(int num) {
  int i, root;
  delSize = 0;
  root = int(sqrt(double(num))) + 1;
  for (i = 2; i <= root; i++) {
    if (num % i == 0) {
      del[delSize] = i;
      delSize++;
      while (num % i == 0) num /= i;
      root = int(sqrt(double(num))) + 1;
    }
  }
  if (num != 1) {
    del[delSize] = num;
    delSize++;
  }
}
void on(int num) {
  int i;
  if (f[num]) {
    printf("Already on");
    return;
  }
  getDel(num);
  for (i = 0; i < delSize; i++) {
    if (g[del[i]] != -1) {
      printf("Conflict with %d", g[del[i]]);
      return;
    }
  }
  f[num] = true;
  for (i = 0; i < delSize; i++) g[del[i]] = num;
  printf("Success");
}
void off(int num) {
  if (!f[num]) {
    printf("Already off");
    return;
  }
  int i;
  f[num] = false;
  getDel(num);
  for (i = 0; i < delSize; i++) {
    g[del[i]] = -1;
  }
  printf("Success");
}
int main() {
  int i, num;
  char sign;
  scanf("%d%d\n", &n, &m);
  memset(g, -1, sizeof(g));
  for (i = 0; i < m; i++) {
    if (i) printf("\n");
    scanf("%c %d\n", &sign, &num);
    if (sign == '+')
      on(num);
    else
      off(num);
  }
  return 0;
}
