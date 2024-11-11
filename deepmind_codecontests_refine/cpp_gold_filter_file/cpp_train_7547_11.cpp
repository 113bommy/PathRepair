#include <bits/stdc++.h>
using namespace std;
int N, Q;
int H[100010] = {0};
int P[100010] = {0};
int pp = 0;
int PL[100010] = {0};
long long delta[100010] = {0};
int main() {
  cin >> N >> Q;
  for (int i = 1; i <= N; i++) {
    scanf("%d", &H[i]);
    delta[i] = (long long)abs(H[i] - H[i - 1]);
  }
  for (int i = 1; i <= Q; i++) {
    int L, R;
    scanf("%d%d", &L, &R);
    pp = 0;
    P[++pp] = L + 1;
    long long Ans = 0;
    for (int j = L + 2; j <= R; j++) {
      for (; pp > 0 && delta[P[pp]] < delta[j]; P[pp--] = 0) {
        if (pp == 1)
          Ans += delta[P[pp]] * (P[pp] - L) * (j - P[pp]);
        else
          Ans += delta[P[pp]] * (P[pp] - P[pp - 1]) * (j - P[pp]);
      }
      P[++pp] = j;
    }
    for (; pp > 0; pp--) {
      if (pp == 1)
        Ans += delta[P[pp]] * (P[pp] - L) * (R - P[pp] + 1);
      else
        Ans += delta[P[pp]] * (P[pp] - P[pp - 1]) * (R - P[pp] + 1);
    }
    cout << Ans << endl;
  }
  return 0;
}
