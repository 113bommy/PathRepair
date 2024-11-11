#include <bits/stdc++.h>
using namespace std;
using vec = vector<int>;
using mat = vector<vec>;

int N, M;
mat A;

int solve(vector<bool> ok) {
  vec cnt(M, 0);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (ok[A[i][j]]) {
        cnt[A[i][j]]++;
        break;
      }
    }
  }
  int P, Q = 0;
  for (int i = 0; i < M; i++) {
    if (Q < cnt[i]) {
      P = i;
      Q = cnt[i];
    }
  }
  if (Q == 0) {
    return N;
  } else {
    ok[P] = false;
    return min(solve(ok), Q);
  }
}

int main() {
  cin >> N >> M;
  A.resize(N, vec(M));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> A[i][j];
      A[i][j]--;
    }
  }
  vector<bool> sports(M, true);
  cout << solve(sports) << endl;
}