#include <bits/stdc++.h>
using namespace std;
const int MAXN = 50010, P = 23;
long long h[MAXN], mulp[MAXN];
char S[MAXN];
int N;
void build_hash() {
  h[0] = S[0];
  for (int i = 1; i < N; i++) h[i] = h[i - 1] * P + S[i];
}
long long get_hash(int a, int b) {
  if (a == 0) return h[b];
  return h[b] - h[a - 1] * mulp[b - a + 1];
}
int lcp(int a, int b) {
  if (a < 0 || b >= N) return 0;
  int ans = 0;
  for (int i = 20; i >= 0; i--) {
    if (b + (1 << i) <= N &&
        get_hash(a, a + (1 << i) - 1) == get_hash(b, b + (1 << i) - 1)) {
      ans |= (1 << i);
      a += (1 << i);
      b += (1 << i);
    }
  }
  return ans;
}
int lcs(int a, int b) {
  if (a < 0 || b >= N) return 0;
  int ans = 0;
  for (int i = 20; i >= 0; i--) {
    if (a - (1 << i) + 1 >= 0 &&
        get_hash(a - (1 << i) + 1, a) == get_hash(b - (1 << i) + 1, b)) {
      ans |= (1 << i);
      a -= (1 << i);
      b -= (1 << i);
    }
  }
  return ans;
}
int main() {
  mulp[0] = 1;
  for (int i = 1; i < MAXN; i++) mulp[i] = mulp[i - 1] * P;
  scanf("%s", S);
  N = strlen(S);
  build_hash();
  int r = N - 1;
  int last = 0;
  for (int l = 1; l <= N; l++) {
    int L, R;
    bool found = false;
    for (int i = r - l; i >= 0; i -= l) {
      int p = lcp(i, i + l), s = lcs(i - 1, i + l - 1);
      if (p + s >= l) {
        L = i - s;
        R = L + (p + s) / l * l;
        found = true;
        break;
      }
    }
    if (found) {
      last = l;
      int minus = R - L;
      for (int i = R; i < N; i++) S[i - minus] = S[i];
      N -= minus;
      l--;
      r = L - 1;
    } else if (last == l) {
      build_hash();
      r = N - 1;
    }
  }
  for (int i = 0; i < N; i++) printf("%c", S[i]);
  printf("\n");
  return 0;
}
