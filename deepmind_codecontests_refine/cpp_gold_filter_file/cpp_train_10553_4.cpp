#include <bits/stdc++.h>
using namespace std;
const int N = int(1e6) + 50;
char S[N], T[N];
int slen, tlen, lef[N], rig[N], cnt[255][255];
inline int getID(char c) {
  if (c == 'R') return 0;
  if (c == 'G') return 1;
  if (c == 'B') return 2;
  throw;
}
int main() {
  scanf("%s", S + 1);
  slen = strlen(S + 1);
  scanf("%s", T + 1);
  tlen = strlen(T + 1);
  int l = 1, r = 1;
  while (l <= slen && r <= tlen) {
    lef[l] = r;
    r += S[l] == T[r];
    ++l;
  }
  slen = min(slen, l - 1);
  l = r = 1;
  while (l <= slen && r <= tlen) {
    rig[l] = r;
    l += S[l] == T[r];
    ++r;
  }
  tlen = min(tlen, r - 1);
  for (int i = l + bool(rig[l]); i <= slen; ++i) {
    rig[i] = tlen;
  }
  long long res = 0;
  for (int i = 1; i <= slen; ++i) {
    for (int j = max(1, lef[i - 1]); j < lef[i]; ++j) --cnt[T[j]][T[j - 1]];
    for (int j = 1 + rig[i - 1]; j <= rig[i]; ++j) ++cnt[T[j]][T[j - 1]];
    res += rig[i] - lef[i] + 1;
    if (S[i - 1] != S[i]) res -= cnt[S[i - 1]][S[i]];
  }
  printf("%I64d\n", res);
  return 0;
}
