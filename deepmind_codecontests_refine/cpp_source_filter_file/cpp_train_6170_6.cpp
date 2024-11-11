#include <bits/stdc++.h>
using namespace std;
string S;
int N, K, L, R;
int psum[26][100010];
int calc(int l, int r, int c) {
  return psum[c][r] - (l == 0 ? 0 : psum[c][l - 1]);
}
struct Const {
  int c, l, r;
};
Const con[502];
int lpos[502], rpos[502], B[100010], C;
int main() {
  cin >> S;
  N = S.size();
  scanf("%d %d %d", &K, &L, &R);
  for (int i = 0; i < K; i++) {
    char c;
    int l, r;
    scanf("\n%c %d %d", &c, &l, &r);
    con[i] = {c - 'a', l, r};
  }
  for (int i = 0; i < 26; i++) {
    for (int j = 0; j < N; j++) {
      psum[i][j] = S[j] - 'a' == i;
      if (j) psum[i][j] += psum[i][j - 1];
    }
  }
  memset(lpos, -1, sizeof(lpos));
  memset(rpos, -1, sizeof(rpos));
  long long ans = 0;
  for (int i = 0; i < N; i++) {
    C += L <= 0;
    for (int j = 0; j < K; j++) {
      while (lpos[j] <= i && calc(lpos[j] + 1, i, con[j].c) >= con[j].l) {
        lpos[j]++;
        if (con[j].c == S[i] - 'a') {
          if (B[lpos[j]] == R) C--;
          B[lpos[j]]++;
          if (B[lpos[j]] == L) C++;
        }
      }
      while (rpos[j] <= i && calc(rpos[j] + 1, i, con[j].c) > con[j].r) {
        rpos[j]++;
        if (con[j].c == S[i] - 'a') {
          if (B[rpos[j]] == L) C--;
          B[rpos[j]]--;
          if (B[rpos[j]] == R) C++;
        }
      }
      if (con[j].c != S[i] - 'a') {
        if (rpos[j] < i && i <= lpos[j]) {
          if (B[i] == R) C--;
          B[i]++;
          if (B[i] == L) C++;
        }
      }
    }
    ans += C;
  }
  printf("%lld", ans);
}
