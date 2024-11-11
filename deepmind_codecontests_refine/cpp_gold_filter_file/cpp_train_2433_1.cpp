#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  vector<int> P(n + 1);
  vector<int> Q(n + 1);
  vector<int> D(n + 1);
  vector<int> T(n + 1);
  vector<int> O(n);
  for (int i = 0; i < n; i++) P[i] = i;
  for (int i = 0; i < n; i++) {
    scanf("%d", &Q[i]);
    Q[i]--;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &D[i]);
    D[i]--;
  }
  O = P;
  if (P == D) {
    cout << "NO" << endl;
    return 0;
  }
  int cc = 0;
  int v1 = -1;
  for (int I = 1;; I++) {
    if (I > k) break;
    for (int i = 0; i < n; i++) T[i] = P[Q[i]];
    P = T;
    if (P == O) {
      cc = I;
      break;
    }
    if (P == D) v1 = I;
  }
  int v2 = -1;
  P = O;
  for (int I = 1;; I++) {
    if (I > k) break;
    for (int i = 0; i < n; i++) T[Q[i]] = P[i];
    P = T;
    if (P == O) {
      cc = I;
      break;
    }
    if (P == D) v2 = I;
  }
  if (cc == 2 && k != 1) {
    printf("NO\n");
    return 0;
  }
  printf(
      (((v1 & 1) == (k & 1) && v1 != -1) || ((v2 & 1) == (k & 1) && v2 != -1))
          ? "YES\n"
          : "NO\n");
}
