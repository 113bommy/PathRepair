#include <bits/stdc++.h>
int N, M, S, fail[200001];
std::pair<int, int> a[200001], b[200001], s[200001];
int main() {
  scanf("%d%d", &N, &M);
  for (int i = 1, l, c; i <= N; i++) {
    char __c;
    scanf("%d-%c", &l, &__c);
    c = __c;
    if (i > 1 && a[i - 1].second == c) {
      a[--i].first += l;
      N--;
    } else
      a[i] = {l, c};
  }
  for (int i = 1, l, c; i <= M; i++) {
    char __c;
    scanf("%d-%c", &l, &__c);
    c = __c;
    if (i > 1 && b[i - 1].second == c) {
      b[--i].first += l;
      M--;
    } else
      b[i] = {l, c};
  }
  if (M == 1) {
    long long O = 0;
    for (int i = 1; i <= N; i++)
      if (a[i].first >= b[1].first && a[i].second == b[1].second)
        O += a[i].first - b[1].first + 1;
    printf("%lld\n", O);
    return 0;
  } else if (M == 2) {
    int O = 0;
    for (int i = 1; i < N; i++)
      if (a[i].first >= b[1].first && a[i + 1].first >= b[2].first &&
          a[i].second == b[1].second && a[i + 1].second == b[2].second)
        O++;
    printf("%d\n", O);
    return 0;
  }
  S = M - 2;
  std::copy(b + 2, b + S + 2, s + 1);
  for (int i = 2; i <= S; i++) {
    int ans = fail[i - 1];
    while (ans && s[ans + 1] != s[i]) ans = fail[ans];
    fail[i] = s[ans + 1] == s[i] ? ans + 1 : 0;
  }
  int O = 0;
  for (int i = 1, pos = 0; i < N; i++) {
    while (pos == S || pos && s[pos + 1] != a[i]) pos = fail[pos];
    if (s[pos + 1] == a[i]) pos++;
    if (pos == S)
      if (a[i - S].first >= b[1].first && a[i - S].second == b[1].second &&
          a[i + 1].first >= b[M].first && a[i + 1].second == b[M].second)
        O++;
  }
  printf("%d\n", O);
  return 0;
}
