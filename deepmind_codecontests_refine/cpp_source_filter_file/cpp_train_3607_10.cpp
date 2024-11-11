#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e3 + 100;
int N;
char S[maxn], T[maxn], cnt[2][27], pos[27], ps[27][maxn], ans[6500];
int main() {
  int ct = 0;
  scanf("%d", &N);
  scanf("%s", S);
  scanf("%s", T);
  for (int i = 0; i < N; i++) {
    cnt[0][S[i] - 'a']++;
    cnt[1][T[i] - 'a']++;
    ps[S[i] - 'a'][pos[S[i] - 'a']++] = i;
  }
  for (int i = 0; i < 26; i++)
    if (cnt[0][i] != cnt[1][i]) {
      printf("-1\n");
      return 0;
    }
  int id;
  for (int i = N - 1; i >= 0; i--) {
    id = ps[T[i] - 'a'][--pos[T[i] - 'a']];
    ans[ct++] = N;
    ans[ct++] = id;
    ans[ct++] = 1;
    for (int j = 0; j < 26; j++)
      for (int k = pos[j] - 1; k >= 0; k--)
        if (ps[j][k] > id) {
          ps[j][k] = N + id - ps[j][k];
        } else {
          ps[j][k]++;
        }
  }
  printf("%d\n%d", ct, ans[0]);
  for (int i = 1; i < ct; i++) printf(" %d", ans[i]);
  printf("\n");
}
