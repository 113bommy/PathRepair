#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000 + 10;
struct node {
  char s[30], t[30];
  bool operator<(const node &A) const {
    if (strcmp(s, A.s) == 0) return strcmp(t, A.t) < 0;
    return strcmp(s, A.s) < 0;
  }
} P[maxn];
char ss[30], tt[30];
int main() {
  int n;
  while (scanf("%d", &n) != EOF) {
    int N = 0;
    for (int i = 1; i <= n; i++) {
      bool flag = 0;
      scanf("%s%s", ss, tt);
      if (!N) {
        N++;
        flag = 1;
        strcpy(P[N].s, ss);
        strcpy(P[N].t, tt);
      } else {
        for (int j = 1; j <= N; j++) {
          if (strcmp(P[j].t, ss) == 0) {
            strcpy(P[N].t, tt);
            flag = 1;
            break;
          }
        }
      }
      if (!flag) {
        N++;
        strcpy(P[N].s, ss);
        strcpy(P[N].t, tt);
      }
    }
    sort(P + 1, P + N + 1);
    printf("%d\n", N);
    for (int i = 1; i <= N; i++) {
      printf("%s %s\n", P[i].s, P[i].t);
    }
  }
  return 0;
}
