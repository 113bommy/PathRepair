#include <bits/stdc++.h>
using namespace std;
const int MAXK = 3 * 1e5;
long long best = 9 * 1e18;
vector<int> A, B, C, D;
int N, M, K, X, S, x;
int main() {
  scanf("%d", &N);
  scanf("%d", &M), scanf("%d", &K);
  scanf("%d", &X), scanf("%d", &S);
  for (int i = 0; i < (int)M; i++) {
    scanf("%d", &x);
    A.push_back(x);
  }
  for (int i = 0; i < (int)M; i++) {
    scanf("%d", &x);
    B.push_back(x);
  }
  for (int i = 0; i < (int)K; i++) {
    scanf("%d", &x);
    C.push_back(x);
  }
  for (int i = 0; i < (int)K; i++) {
    scanf("%d", &x);
    D.push_back(x);
  }
  for (int i = 0; i < (int)M; i++)
    if (B[i] <= S) {
      int pos = upper_bound(D.begin(), D.end(), S - B[i]) - D.begin();
      pos--;
      if (pos < 0)
        best = min(best, 1ll * A[i] * N);
      else
        best = min(best, 1ll * A[i] * (N - C[pos]));
    }
  int pos = upper_bound(D.begin(), D.end(), S) - D.begin();
  pos--;
  if (pos > 0)
    best = min(best, 1ll * X * (N - C[pos]));
  else
    best = min(best, 1ll * X * N);
  cout << best << endl;
}
