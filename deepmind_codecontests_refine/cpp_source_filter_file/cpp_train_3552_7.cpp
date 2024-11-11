#include <bits/stdc++.h>
using namespace std;
const int N = 5e2 + 10;
const int M = 27;
int Cnt[N][M], Odd[N], Len[N], n, m, Ans;
char S[N][N];
bool Cmp(int a, int b) {
  if (Odd[a] > 1 || Odd[b] > 1) return false;
  for (int i = 0; i < 26; i++) {
    if (Cnt[a][i] != Cnt[b][i]) return false;
  }
  return true;
}
void Manacher() {
  int Po = 0, mx = 0;
  Len[0] = 1;
  for (int i = 1; i <= 2 * n; i++) {
    if (i <= mx)
      Len[i] = min(mx - i, Len[2 * Po - i]);
    else
      Len[i] = 1;
    while (i - Len[i] >= 1 && i + Len[i] <= 2 * n + 2 &&
           Cmp(i + Len[i], i - Len[i]))
      Len[i]++;
    if (Odd[i] > 1) Len[i] = 1;
    if (mx < i + Len[i]) {
      Po = i;
      mx = i + Len[i];
    }
    Ans += (Len[i] + 1) / 2;
  }
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%s", S[i] + 1);
  }
  for (int L = 1; L <= m; L++) {
    for (int i = 1; i <= n; i++) {
      for (int k = 0; k < 26; k++) {
        Cnt[i * 2 - 1][k] = Odd[i * 2 - 1] = 0;
      }
    }
    for (int R = L; R <= m; R++) {
      for (int i = 1; i <= n; i++) {
        Cnt[2 * i - 1][S[i][R] - 'a']++;
        if (Cnt[2 * i - 1][S[i][R] - 'a'] & 1)
          Odd[2 * i - 1]++;
        else
          Odd[2 * i - 1]--;
      }
      Manacher();
    }
  }
  printf("%d\n", Ans);
}
