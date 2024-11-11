#include <bits/stdc++.h>
using namespace std;
const int n = 10005, m = 26000005;
int i, N, j, tot, l, last, x, y, Max, flag;
int A[30], p[30], X[n], Q[n], Ans[n], Y[m];
char s[30], S[n];
int Cmp(const int &i, const int &j) { return p[i] < p[j]; }
int cmp(const int &i, const int &j) { return X[i] < X[j]; }
int main() {
  scanf("%s", S);
  scanf("%d", &N);
  for (i = 1; i <= N; ++i) {
    scanf("%s", s);
    l = strlen(s);
    X[i] = 0;
    for (j = 0; j < l; ++j) X[i] |= 1 << (s[j] - 'a');
  }
  for (j = 0; j < 26; ++j) A[j] = j;
  l = strlen(S);
  for (i = 0; i < l; ++i) {
    if (i != 0 && S[i] == S[i - 1]) continue;
    last = p[S[i] - 'a'], flag = 0;
    p[S[i] - 'a'] = i + 1;
    sort(A, A + 26, Cmp);
    y |= 1 << (S[i] - 'a');
    x = y;
    for (j = 0; j < 26; ++j) {
      if (p[A[j]] <= last) {
        if (p[A[j]]) x ^= 1 << A[j];
        continue;
      }
      if (!flag && last) {
        x ^= 1 << A[j], flag = 1;
        continue;
      }
      Y[++tot] = x;
      x ^= 1 << A[j];
    }
  }
  for (i = 1; i <= N; ++i) Q[i] = i;
  sort(Q + 1, Q + N + 1, cmp);
  sort(Y + 1, Y + tot + 1);
  j = 1;
  for (i = 1; i <= N; ++i)
    if (X[Q[i]] == X[Q[i - 1]])
      Ans[Q[i]] = Ans[Q[i - 1]];
    else {
      for (; j <= tot && X[Q[i]] > Y[j]; ++j)
        ;
      for (; j <= tot && X[Q[i]] == Y[j]; ++j) ++Ans[Q[i]];
    }
  for (i = 1; i <= N; ++i) printf("%d\n", Ans[i]);
  return 0;
}
