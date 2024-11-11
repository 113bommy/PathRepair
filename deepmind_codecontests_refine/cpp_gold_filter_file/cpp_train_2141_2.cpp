#include <bits/stdc++.h>
using namespace std;
char S[(long long)1e5 + 2];
int main() {
  int N, M;
  scanf("%d ", &M);
  fgets(S, (long long)1e5 + 2, stdin);
  N = strlen(S) - 1;
  S[N] = 0;
  int k = 0;
  for (k = 1; k <= 26; k <<= 1)
    ;
  k >>= 1;
  int i = -1;
  for (i = -1; k; k >>= 1)
    if (i + k < 26) {
      char worst = 'a' + i + k;
      int last = -1;
      int j = 0;
      for (j = 0; j < N; j++) {
        if (S[j] <= worst) last = j;
        if (j - last >= M) break;
      }
      if (j != N) i += k;
    }
  char worst = 'a' + i + 1;
  vector<char> ret;
  int last = -1;
  int j = 0;
  int last_worst = -1;
  for (j = 0; j < N; j++) {
    if (S[j] < worst) {
      last = j;
      ret.push_back(S[j]);
    }
    if (S[j] == worst) {
      last_worst = j;
    }
    if (j - last >= M) {
      last = last_worst;
      ret.push_back(worst);
    }
  }
  sort(ret.begin(), ret.end());
  for (auto i : ret) printf("%c", i);
  printf("\n");
  return 0;
}
