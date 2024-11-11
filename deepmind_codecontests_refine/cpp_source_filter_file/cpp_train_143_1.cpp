#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5001;
const int MAXM = 1000000001;
int Q[MAXN], L[MAXN], R[MAXN], P[MAXN], ADD[MAXN] = {0}, Ans[MAXN],
                                        Result[MAXN];
int N, M;
bool Achieve;
int main() {
  cin >> N >> M;
  fill(Ans + 1, Ans + N + 1, MAXM);
  for (int i = 0; i < M; i++) {
    cin >> Q[i] >> L[i] >> R[i] >> P[i];
    if (Q[i] == 1) {
      for (int j = L[i]; j <= R[i]; j++) ADD[j] += P[i];
    } else {
      for (int j = L[i]; j <= R[i]; j++) Ans[j] = min(Ans[j], P[i] - ADD[j]);
    }
  }
  Achieve = 1;
  copy(Ans + 1, Ans + N + 1, Result + 1);
  for (int i = 0; i < M; i++) {
    if (Q[i] == 1) {
      for (int j = L[i]; j <= R[i]; j++) Ans[j] += P[i];
    } else {
      bool achieve = 0;
      for (int j = L[i]; j <= R[i]; j++) {
        if (Ans[j] > P[i]) {
          achieve = 0;
          break;
        }
        if (Ans[j] == P[i]) achieve = 1;
      }
      if (!achieve) {
        Achieve = 0;
        break;
      }
    }
  }
  if (Achieve) {
    cout << "YES\n";
    for (int i = 1; i < N; i++) cout << Result[i] << " ";
    cout << Result[N] << endl;
  } else
    cout << "NO\n";
  return 0;
}
