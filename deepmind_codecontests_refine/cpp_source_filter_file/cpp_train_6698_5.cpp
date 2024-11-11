#include <bits/stdc++.h>
using namespace std;
void loadData(void);
void proc(void);
void printRes(void);
int n;
int a[100000];
int b[100000];
int pos[100000];
int main(int argc, char** argv) {
  loadData();
  proc();
  return 0;
}
void proc(void) {
  for (int i = 0; i < n; i++) pos[a[i]] = i;
  for (int i = 0; i < n; i++)
    printf("%d%c", pos[b[i]] + 1, i == n - 1 ? '\n' : ' ');
  return;
}
void loadData(void) {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  for (int i = 0; i < n; i++) scanf("%d", &b[i]);
  return;
}
void printRes(void) { return; }
