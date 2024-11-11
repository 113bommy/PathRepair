#include <bits/stdc++.h>
using namespace std;
const int MAXN = 6000, INF = (1 << 30);
int n;
int A[MAXN];
int D[MAXN];
int H[MAXN];
int S[MAXN];
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> A[i];
    S[i] = S[i - 1] + A[i];
  }
  for (int i = 1; i <= n; i++) D[i] = INF;
  D[0] = 0;
  H[0] = 0;
  D[1] = 0;
  H[1] = A[1];
  for (int i = 2; i <= n; i++) {
    for (int j = 0; j < i; j++) {
      if (D[j] == INF) continue;
      if (S[i] - S[j] >= H[j]) {
        int k = D[j] + (i - j - 1);
        if (k < D[i]) {
          D[i] = k;
          H[i] = S[i] - S[j];
        } else {
          if (k == D[i]) {
            D[i] = k;
            if (S[i] - S[j] < H[i]) H[i] = S[i] - S[j];
          }
        }
      }
    }
  }
  cout << D[n] << endl;
  return 0;
}
