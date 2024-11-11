#include <bits/stdc++.h>
using namespace std;
const int N = 5e3 + 7;
int p[N], b[N], tem1[N], tem2[N], ans_p[N];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    printf("? %d 0\n", i);
    fflush(stdout);
    scanf("%d", &tem1[i]);
    if (tem1[i] == -1) return 0;
  }
  for (int i = 0; i < n; i++) {
    printf("? 0 %d\n", i);
    fflush(stdout);
    scanf("%d", &tem2[i]);
    if (tem2[i] == -1) return 0;
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) b[j] = i ^ tem2[j];
    for (int j = 0; j < n; j++) p[j] = b[0] ^ tem1[j];
    int flag = 1;
    for (int j = 0; j < n; j++) {
      if (p[b[j]] != j || p[j] >= n || b[j] >= n) {
        flag = 0;
        break;
      }
    }
    if (flag == 1) {
      if (ans == 0) {
        for (int j = 0; j < n; j++) {
          ans_p[j] = p[j];
        }
      }
      ans++;
    }
  }
  printf("!\n");
  printf("%d\n", ans);
  for (int i = 0; i < n; i++) {
    if (i != n - 1)
      printf("%d ", ans_p[i]);
    else
      printf("%d\n", ans_p[i]);
  }
  fflush(stdout);
}
