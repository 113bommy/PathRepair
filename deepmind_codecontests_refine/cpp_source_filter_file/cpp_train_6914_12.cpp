#include <bits/stdc++.h>
using namespace std;
int N, a[500];
void read();
void solve();
int main() {
  read();
  solve();
  return 0;
}
void read() {
  scanf("%d", &N);
  for (int i = 0; i < N; i++) scanf("%d", &a[i]);
}
void solve() {
  int now = 0, right;
  for (int i = N - 1; i >= 0; i--) {
    if (a[i] > 0) {
      right = i;
      break;
    }
  }
  while (1) {
    if (now != right) {
      if (a[now] != 0) {
        a[now]--;
        printf("PRL");
      } else {
        printf("R");
        now++;
      }
    } else {
      if (a[now] != 0) {
        a[now]--;
        if (a[now] == 0) {
          printf("P");
          break;
        } else
          printf("PLR");
      } else {
        break;
      }
    }
  }
  printf("\n");
}
