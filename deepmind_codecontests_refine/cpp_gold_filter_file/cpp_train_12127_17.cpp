#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1e6 + 9;
const int MOD = 1e9 + 7;
char P[MAX_N];
char T[MAX_N];
bool vec[MAX_N];
int Next[MAX_N];
void Makenext() {
  int len = strlen(P);
  Next[0] = 0;
  for (int i = 1, k = 0; i < len; i++) {
    while (k > 0 && P[k] != P[i]) {
      k = Next[k - 1];
    }
    if (P[k] == P[i]) {
      k++;
    }
    Next[i] = k;
  }
}
int kmp(int N) {
  int ans = 0;
  int len1 = N;
  int len2 = strlen(P);
  int point = -MOD;
  for (int i = 0, k = 0; i < len1; i++) {
    if (vec[i]) {
      point = i;
    }
    if (i >= point && i < point + len2) {
      T[i] = P[i - point];
      vec[i] = 1;
    }
    while (k > 0 && T[i] != P[k]) {
      k = Next[k - 1];
    }
    if (T[i] == P[k]) k++;
    if (k == len2) ans++;
  }
  return ans;
}
int main() {
  int N, M;
  while (cin >> N >> M) {
    memset(vec, 0, sizeof(vec));
    scanf("%s", P);
    Makenext();
    int len = strlen(P);
    for (int i = 0; i < M; i++) {
      int point;
      scanf("%d", &point);
      vec[point - 1] = 1;
    }
    int ans = kmp(N);
    if (ans >= M) {
      long long int res = 1;
      for (int i = 0; i < N; i++) {
        if (!vec[i]) {
          res = (res * 26) % MOD;
        }
      }
      printf("%lld\n", res);
    } else {
      printf("0\n");
    }
  }
  return 0;
}
