#include <bits/stdc++.h>
using namespace std;
char all[1005][1005];
struct A {
  int have[30] = {0};
} how[1005];
bool F(A a, A b) {
  for (int i = 0; i <= 26; i++) {
    if (a.have[i] > b.have[i]) return 0;
    if (a.have[i] < b.have[i]) return 1;
  }
  return 0;
}
int main() {
  int N, i, ans = 1, j, ok;
  scanf("%d", &N);
  for (i = 0; i < N; i++) {
    scanf("%s", all[i]);
    for (j = 0; j <= 26; j++) how[i].have[j] = 0;
    for (j = 0; all[i][j] != '\0'; j++) how[i].have[all[i][j] - 'a'] = 1;
  }
  sort(how, how + N, F);
  for (i = 1; i < N; i++) {
    ok = 0;
    for (j = 0; j <= 26; j++) {
      if (how[i].have[j] != how[i - 1].have[j]) ok = 1;
    }
    ans += ok;
  }
  printf("%d\n", ans);
  return 0;
}
