#include <bits/stdc++.h>
using namespace std;
void loadData(void);
int proc(void);
void printRes(int);
int n, k, l, c, d, p, nl, np;
int main(int argc, char** argv) {
  loadData();
  printRes(proc());
  return 0;
}
int proc(void) { return min(min((k * l) / (nl * n), c * d), p / np); }
void loadData(void) {
  scanf("%d%d%d%d%d%d%d%d", &n, &k, &l, &c, &d, &p, &nl, &np);
  return;
}
void printRes(int res) {
  printf("%d\n", res);
  return;
}
